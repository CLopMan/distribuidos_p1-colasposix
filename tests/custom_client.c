#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../src/claves.h"

int main(int argc, char *argv[]) {
    int status;
    int sample_key = 0;
    char sample_str[256];
    strcpy(sample_str, "HELLO WORLD");
    double sample_vector[] = {3.14, 2.718, 1.618, 7.98e300};
    int sample_N = 4;

    char Bsample_str[] = "BYE WORLD";
    double Bsample_vector[] = {6.28, 5.418, 2.18};
    int Bsample_N = 3; 

    int received_N = -1; 
    char received_str[256];
    double received_vector[32];


    if (argc != 2) {
        fprintf(stderr, "Error: 2 arguments were expected but %d was given\n", argc);
        return -1; 
    }
    

    int argument = atoi(argv[1]);

    switch (argument)
    {
    case 0:
        status = init();
        break;
    case 1:
        status = set_value(sample_key, sample_str, sample_N, sample_vector);
        break;
    case 2:
        get_value(sample_key, received_str, &received_N, received_vector);
        break;
    case 3:
        status = modify_value(sample_key, Bsample_str, Bsample_N, Bsample_vector);
        break;
    case 4:
        status = delete_key(sample_key);
        break;
    case 5:
        status = exist(sample_key);
        break;
    default:
        fprintf(stderr, "ERROR: unrecognised op code (%d)", argument);
        return -1;
    }
    printf("status: %d\n", status);

    return 0; 
}