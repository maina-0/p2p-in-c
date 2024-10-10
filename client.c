#include "client.h"
#include <stdlib.h>

// Function to initialize a client structure
struct client client_constructor(int domain, int service, int protocol, unsigned long interface, int port, int backlog) {
    struct server new_client;

    new_client.domain = domain;//v4
    new_client.service = service;//tcp
    new_client.protocol = protocol;
    new_client.interface = interface;//ip
    new_client.port = port;
    new_client.backlog = backlog;


    

    
    //memset(&new_server.address, 0, sizeof(new_server.address));
    new_client.address.sin_family = domain; 
    new_client.address.sin_addr.s_addr = htonl(interface); 
    new_client.address.sin_port = htons(port);


    return new_client;
}

