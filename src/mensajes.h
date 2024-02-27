#ifndef MENSAJES_H

#define MENSAJE_H


const int CHAR_SIZE = 256;
const int ARR_SIZE = 32;


typedef struct __peticion {
    char q_client[CHAR_SIZE];
    int key; 
    int op; 
    char value1[CHAR_SIZE];
    double value2[ARR_SIZE];
    int N_i;
} peticion;

typedef struct __respuesta {
    int success; 
    char value1[CHAR_SIZE];
    double value2[ARR_SIZE];
    int N;
} respuesta;

#endif