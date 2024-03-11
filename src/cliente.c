#include <stdio.h> 
#include "claves.h"

int main(int argc, char *argv[]) {
    double tres[] = {3.3,33.3,333.3};
    int N;
    char cd[] = "cd";
    init();
    set_value(3, cd, 3, tres);
    set_value(4, cd, 3, tres);
    set_value(5, cd, 3, tres);
    set_value(6, cd, 3, tres);
    get_value(3,cd,&N, tres);
    modify_value(3, cd, 3, tres);
    modify_value(3, cd, 3, tres);
    modify_value(3, cd, 3, tres);
    delete_key(3);
    exist(3);

    return 0;
}