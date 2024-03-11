#include "imp_clave.h"
#include <stdio.h>

/*Estructura de fichero
char [256]
N_value [4]
double[32*8]
*/

int write_file(int key, char *value1, int N_value2, double *V_value2, char permiso[4]) {
    
    char file_name[32];
    sprintf(file_name, "%d.tuple", key);

    FILE *tuple = fopen(file_name, permiso); // O_TRUNC, O_WRONLY, O_CREAT if exists return an error
                                            // dos hilos no pueden entrar aquí a la vez con el mismo valor de clave
    if (NULL == tuple) {
        perror("ERROR-fopen:");
        return -1;
    }

    if (-1 == fwrite(value1, 1, 256, tuple)) {
        perror("ERROR-write value 1");
        return -1;
    }

    if (-1 == fwrite(&N_value2, sizeof(int), 1, tuple)) {
        perror("ERROR-write N_value:");
        return -1;
    }

    if (-1 == fwrite(V_value2, sizeof(double), 32, tuple)) {
        perror("ERROR-write doubles: ");
        return -1;
    }
    fclose(tuple);
    return 0;

} 

// la he probado con un minicódigo en c y parece que funciona
int set_value(int key, char *value1, int N_value2, double *V_value2) {
    /*validaciones*/
    if (N_value2 > 32 || N_value2 < 1) {
        perror("ERROR: N_value 2 out of range");
    }

    return write_file(key, value1, N_value2, V_value2, "wx\0");
}

int modify_value(int key, char *value1, int N_value2, double *V_value2) {
    /*validaciones*/
    if (N_value2 > 32 || N_value2 < 1) {
        perror("ERROR: N_value 2 out of range");
    }

    return write_file(key, value1, N_value2, V_value2, "r+\0");
}



