#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

#define MAX_CHILDS 5

int test_one_client() {
    printf("Test 1 sólo cliente:\n");
    int pid = fork();
    if (pid == 0) {
        execl("./cliente", "", NULL);
    }
    wait(NULL);
    return 0;
}

int test_two_writers() {
    printf("Tests 2: 2 escritores\n");

    int pid = fork();
    if (pid != 0) {
        pid = fork();
    }

    if (0 == pid) {
        printf("HIJO\n");
        execl("./custom_client", "0", "3", NULL);
    }
    
    for (int i = 0; i < 2; ++i) {
        wait(NULL);
    }
    return 0;

}

int main(int argc, char *argv[]) {
    test_one_client(); // comunicaicón correcta
    //setup
    int zero_creat = fork();
    if (zero_creat == 0 ) {
        printf("SETUP\n");
        execl("./custom_client", "0", "1", NULL);
    } else {
        wait(NULL);
    }
    int i = 5;
    while (i--) {
        test_two_writers(); // en este podremos comprobar la concurrencia 
                                //si se da el caso en el que ambos empiecen antes de que el primero termine
    }
    //test_two_creating_same_file();
    //test_one_reading_one_writing();
    //test_MAX_CHILDS_clients_writing();
    //test_MAX_CHILDS_reading();

    return 0;
}
