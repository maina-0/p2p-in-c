#include <pthread.h>
//#include <stdlib.h>
#include "server.h"
#include <stdio.h>
#include <errno.h>
//#include <stdbool.h>
//#include <unistd.h>


void *server_function(void *arg);

int main(){

    pthread_t server_thread;

    pthread_create(&server_thread,NULL,server_function,NULL);

    pthread_join(server_thread,NULL);
    return 0;
 
}

void *server_function(void *arg){
    struct server new_server = server_constructor(AF_INET,SOCK_STREAM,0,INADDR_ANY,20001,20);
}
    
