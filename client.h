#ifndef CLIENT_H
#define CLIENT_H

#include <sys/socket.h>
#include <netinet/in.h>

struct client
{
    int domain;
    int service;
    int protocol;
    unsigned long interface;
    int port;
    int backlog;
    int socket;
    struct sockaddr_in address;

};

struct client client_constructor(int domain,int service,int protocol,unsigned long interface,int port,int backlog);


#endif //CLIENT_H
