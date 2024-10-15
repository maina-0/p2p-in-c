#include "client.h"
#include <stdlib.h>

// Function to initialize a client structure
struct client client_constructor(int domain, int service, int protocol, unsigned long interface, int port, int backlog) {
    struct server new_client;

    new_client.domain = domain;//v4
    new_client.service = service;//tcp
    new_client.protocol = protocol;
    new_client.interface = interface;//ip address
    new_client.port = port;
    new_client.socket=socket(domain,service,protocol);
    new_client.request=request;
    


    return new_client;
}
char *(*request)(struct client *client, char *server_ip, char *request){
    struct sockaddr_in server_add;
    server_add.sin_family=client->domain;
    server_add.sin_port=htons(client->port);
    server_add.sin_addr.s_addr=client->interface;

    inet_pton(client->domain,server_ip,&server_add.sin_addr);

    connect(client->socket,(struct sockaddr *)server_add,sizeof(server_add));

    send(client->socket,request,strlen(request),0);

    char response[1024];
    ssize_t amtrecv=read(client->socket,response,sizeof(response)+1);
    response[amtrecv]='\0';

    return (response);


}


