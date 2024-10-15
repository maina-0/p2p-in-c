
#include <stdlib.h>
#include "server.h"
#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>


// Function to initialize a server structure
struct server server_constructor(int domain, int service, int protocol, unsigned long interface, int port, int backlog) {
    struct server new_server;

    new_server.domain = domain;//v4
    new_server.service = service;//tcp
    new_server.protocol = protocol;
    new_server.interface = interface;//ip
    new_server.port = port;
    new_server.backlog = backlog;
    new_server.socket=socket(new_server.domain,new_server.service,new_server.protocol);
   // new_server.socketfd = socketfd;
    


    

    
  //  memset(&new_server.address, 0, sizeof(new_server.address));
    new_server.address.sin_family = domain; 
    new_server.address.sin_addr.s_addr = htonl(interface); 
    new_server.address.sin_port = htons(port);
    

    int socketfd; 

    if(new_server.socket<0){
        perror("err creating socket;");
        exit(1);
    }
        printf("socketfd is %i\n",new_server.socket);
    

    if (bind(new_server.socket,(struct sockaddr *)&new_server.address,sizeof(new_server.address))){
        perror("err binding port to ip;");
        exit(1);
    }
    printf("binding successful, listening port %i\n",new_server.port);

    if(listen(new_server.socket,new_server.backlog)<0){
        perror("err listening on port;");
        exit(1);

    }

    struct sockaddr_in clientaddr;
    int addrsize = sizeof(clientaddr);
    int *pointer=&addrsize;
    //clientaddr.sin_family=AF_INET;



    int clientFD=accept(new_server.socket,(struct sockaddr *)&clientaddr,&addrsize);//alternatively in the last argument give pointer
    
    char buffer[1024];
    
    while(true){ 

    ssize_t amntrecv=recv(clientFD,buffer,1024,0);
        if (amntrecv>0){
            buffer[amntrecv]=0;
            printf("%s \n",buffer);
        }

        if (amntrecv==0){
            break;
        }

    }   

    close(clientFD);
    shutdown(new_server.socket,SHUT_RDWR);

    return new_server;
}
