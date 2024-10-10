#include <pthread.h>
#include <stdlib.h>
#include "server.h"
#include <stdio.h>
#include <errno.h>
#include <stdbool.h>
#include <unistd.h>


void *server_function(void *arg);

int main(){

    pthread_t server_thread;

    pthread_create(&server_thread,NULL,server_function,NULL);

    pthread_join(server_thread,NULL);
    return 0;
 
}

void *server_function(void *arg){
    struct server new_server = server_constructor(AF_INET,SOCK_STREAM,0,INADDR_ANY,20001,20);
    
    int socketfd;
    socketfd=socket(new_server.domain,new_server.service,new_server.protocol);

    if(socketfd<0){
        perror("err creating socket;");
        exit(1);
    }
        printf("socketfd is %i\n",socketfd);
    

    if (bind(socketfd,(struct sockaddr *)&new_server.address,sizeof(new_server.address))){
        perror("err binding port to ip;");
        exit(1);
    }
    printf("binding successful, listening port %i\n",new_server.port);

    if(listen(socketfd,new_server.backlog)<0){
        perror("err listening on port;");
        exit(1);

    }

    struct sockaddr_in clientaddr;
    int addrsize = sizeof(clientaddr);
    int *pointer=&addrsize;
    //clientaddr.sin_family=AF_INET;



    int clientFD=accept(socketfd,(struct sockaddr *)&clientaddr,&addrsize);//alternatively in the last argument give pointer
    
    char buffer[1024];
    
    while(true){ 

    ssize_t amntrecv=recv(clientFD,buffer,1024,0);


    if (amntrecv>0){
            buffer[amntrecv]=0;
            printf("-------------\n");
            printf("%s \n",buffer);
            printf("-------------\n");
        
        }

        if (amntrecv==0){
            break;
        }

    }   

    close(clientFD);
    shutdown(socketfd,SHUT_RDWR);

    return 0;
}

