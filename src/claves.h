#ifndef CLAVES_H

#define CLAVES_H

/**
 * Inicializa el servicio borrando todos los datos anteriores
 * 
 * @return devuelve 0 en caso de éxito y -1 en cualquier otro caso
*/
int init();

/**
 * En la tupla de clave *key* se guardan los valores value1 (str) y 
 * value2 (vector de N_value2 elementos de tipo double)
 * 
 * 
*/
int set_value(int key, char *value1, int N_value2, double *V_value2);


/**
 * Recupera los valores de la clave *key* rellenando los argumentos. 
*/
int get_value(int key, char *value1, int *N_value2, double *V_value2);


int modify_value(int key, char *value1, int N_value2, double V_value2);

int delete_key(int key);

int exist(int key); 

#endif