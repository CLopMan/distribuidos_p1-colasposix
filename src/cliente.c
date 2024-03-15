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
    int retorno = -1; 
    retorno = set_value(3, cd, 3, tres);
    printf("first set: %d\n", retorno); 
    retorno = set_value(9, cd, 3, tres);
    printf("snd set: %d\n", retorno);


    get_value(3, texto, &rn, rvec);
    printf("get_value:\n\ttexto: %s\n\tN: %d\n\tdoubles:", texto, rn);
    for (int i = 0; i < rn; ++i) {
        printf("\n\t\t[%d]: %lf", i, rvec[i]); 
    }
    printf("\n");

    modify_value(3, cd, 3, tres);
    modify_value(5, cd, 3, tres);
    delete_key(3);
    printf("exits: %i\n", exist(9));
    return 0;
}