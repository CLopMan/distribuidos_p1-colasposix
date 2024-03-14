#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>

#define MAX_CHILDS 5

int test_one_client() {
    printf("Test 1 sólo cliente:\n");
    int i = 0;
    int pid = fork();
    if (pid == 0) {
        /*while( i < 5) {

            pid = fork();
            if (pid != 0) break;
            
            ++i;
        }*/
        execl("./cliente", "");
    }
    wait(NULL);
}

int main(int argc, char *argv[]) {
    int i = 0;
    test_one_client();

    return 0;
}
