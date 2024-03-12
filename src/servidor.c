#include <stdio.h> 
#include <mqueue.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "mensajes.h"
#include "imp_clave.h"

mqd_t server;
void stop_server() {
    printf("Cerrando servidor...\n");
    mq_close(server);
    mq_unlink("/SERVIDOR");
    exit(0);
}

int tratar_peticion(peticion* p) {
    peticion local_peticion = *p;
    respuesta r;

    switch (local_peticion.op) {
    case 0: // init
        printf("Init\n");
        r.success = init();
        break;

    case 1: // set value
        printf("Set Value\n");
        r.success = set_value(local_peticion.key, local_peticion.value1, local_peticion.N_i, local_peticion.value2);
        break;

    case 2: // get value
        printf("Get Value\n");
        r.success = get_value(local_peticion.key, local_peticion.value1, &r.N, local_peticion.value2);
        break;

    case 3: // modify value
        printf("Modify Value\n");
        r.success = modify_value(local_peticion.key, local_peticion.value1, local_peticion.N_i, local_peticion.value2);
        break;

    case 4: // delete key
        printf("Delete Key\n");
        r.success = delete_key(local_peticion.key);
        break;

    case 5: // exists
        printf("Exists\n");
        r.success = exist(local_peticion.key);
        break;

    default:
        fprintf(stderr, "Not recognised operation: expected [0, 5] but %d was received\n", local_peticion.op);
        break;
    }
    mqd_t client = mq_open(local_peticion.q_client, O_WRONLY);
    mq_send(client, (char*)&r, sizeof(respuesta), 0);
}

int main(int argc, char* argv[]) {

    signal(SIGINT, stop_server);

    struct mq_attr attr;
    attr.mq_curmsgs = 0;
    attr.mq_flags = 0;
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = sizeof(peticion);

    server = mq_open("/SERVIDOR", O_CREAT | O_RDONLY, 0700, &attr);

    double v[] = { -1.0, 3.14, 7.65 };
    char s[] = "Hello world";

    while (!!1) {
        peticion p;
        mq_receive(server, (char*)&p, sizeof(peticion), NULL);
        tratar_peticion(&p);



    }

    return 0;

}

