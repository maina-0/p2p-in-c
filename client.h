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
    char *(*request)(struct Client *client, char *server_ip, char *request);

};

struct client client_constructor(int domain,int service,int protocol,int port,unsigned long interface);


#endif //CLIENT_H
