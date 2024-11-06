#include "client.h"
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>

// Function to initialize a client structure
struct client client_constructor(int domain, int service, int protocol, unsigned long interface, int port) {
    struct client new_client;

    new_client.domain = domain;//v4
    new_client.service = service;//tcp
    new_client.protocol = protocol;
    new_client.interface = interface;//ip address
    new_client.port = port;
    new_client.socket=socket(domain,service,protocol);
    
    


    return new_client;
}
char * buffer (struct client *new_client, char *server_ip, char *buffer){
 //   memset(&(struct sockaddr *)server_add, 0, sizeof(server_add));
    struct sockaddr_in server_add;
    server_add.sin_family=new_client->domain;
    server_add.sin_port=htons(new_client->port);
    server_add.sin_addr.s_addr=(new_client->interface);

    inet_pton(new_client->domain,server_ip,&server_add.sin_addr);

    connect(new_client->socket,(struct sockaddr *)server_add,sizeof(server_add));

    send(new_client->socket,buffer,strlen(buffer),0);

    char response[1024];
    ssize_t amtrecv=read(new_client->socket,response,sizeof(response)+1);
    response[amtrecv]='\0';

    return (response);


}


