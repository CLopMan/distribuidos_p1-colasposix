#include <stdio.h> 
#include <mqueue.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>
#include "mensajes.h"

mqd_t server;
void stop_server()
{
    mq_close(server);
    mq_unlink("/SERVIDOR");
    exit(0);
}

int tratar_peticion(peticion *p){
    peticion local_peticion = *p;
    switch (local_peticion.op)
    {
    case 0:
        printf("Init\n");
        break;

    case 1:
        printf("Set Value\n");
        break;

    case 2:
        printf("Get Value\n");
        break;
    
    case 3:
        printf("Modify Value\n");
        break;

    case 4:
        printf("Delete Key\n");
        break;

    case 5:
        printf("Exists\n");
        break;

    default:
        printf("XD");
        break;
    }
}

int main(int argc, char *argv[])
{

    signal(SIGINT, stop_server);

    struct mq_attr attr;
    attr.mq_curmsgs = 0;
    attr.mq_flags = 0; 
    attr.mq_maxmsg = 10;
    attr.mq_msgsize = sizeof(peticion);

    server = mq_open("/SERVIDOR", O_CREAT | O_RDONLY, 0700, &attr);

    while(!!1){


    }

    return 0;

}

