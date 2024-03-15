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
        execl("./cliente", "");
    }
    wait(NULL);
    return 0;
}

int main(int argc, char *argv[]) {
    int i = 0;
    test_one_client();

    return 0;
}
