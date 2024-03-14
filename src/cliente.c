#include <stdio.h> 
#include "claves.h"

int main(int argc, char* argv[]) {
    double tres[] = { 3.3,33.3,333.3 };
    int N;
    char cd[] = "cd";
    char texto[256];
    int rn;
    double rvec[32];
    
    init();
    set_value(3, cd, 3, tres);
    set_value(9, cd, 3, tres);


    get_value(3, texto, &rn, rvec);
    printf(">>%d\n", rn);
    modify_value(3, cd, 3, tres);
    modify_value(5, cd, 3, tres);
    delete_key(3);
    printf("%i", exist(9));
    return 0;
}