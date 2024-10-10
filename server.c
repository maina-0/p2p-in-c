#include <string.h>
#include <stdlib.h>
#include "server.h"

// Function to initialize a server structure
struct server server_constructor(int domain, int service, int protocol, unsigned long interface, int port, int backlog) {
    struct server new_server;

    new_server.domain = domain;//v4
    new_server.service = service;//tcp
    new_server.protocol = protocol;
    new_server.interface = interface;//ip
    new_server.port = port;
    new_server.backlog = backlog;


    

    
    memset(&new_server.address, 0, sizeof(new_server.address));
    new_server.address.sin_family = domain; 
    new_server.address.sin_addr.s_addr = htonl(interface); 
    new_server.address.sin_port = htons(port);


    return new_server;
}
