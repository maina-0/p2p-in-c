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
    int socket;
    char *(*buffer)(struct client *client, char *server_ip, char *buffer);

};

struct client client_constructor(int domain,int service,int protocol,unsigned long interface,int port);


#endif //CLIENT_H
