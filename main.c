#include <pthread.h>
//#include <stdlib.h>
#include "server.h"
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <string.h>
//#include <unistd.h>


void *server_function(void *arg);
void client_function(char *buffer);


int main(){

    pthread_t server_thread;

    pthread_create(&server_thread,NULL,server_function,NULL);

    pthread_join(server_thread,NULL);
    return 0;
    


    while (true){
        char buffer(255);
        memset(buffer,0,255);
        fgets(buffer,255,stdin);
        client_function(buffer);
    }
}


void client_function(char *buffer){
    struct client new_client = client_constructor(AF_INET,SOCK_STREAM,0,INADDR_ANY,20001);
    client.buffer(&new_client,"41.89.68.34",&buffer);
}


void *server_function(void *arg){
    struct server new_server = server_constructor(AF_INET,SOCK_STREAM,0,INADDR_ANY,20001,20);
}
    
