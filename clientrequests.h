#ifndef CLIENTREQUESTS_H
#define CLIENTREQUESTS_H

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <string.h>
#include <errno.h>

class ClientRequests
{
public:
    ClientRequests();
    void ParseActions();

private:
    /* portul de conectare la server*/
    int port;

    int sd;			// descriptorul de socket
    struct sockaddr_in server;	// structura folosita pentru conectare
    char msg[100];		// mesajul trimis


};

#endif // CLIENTREQUESTS_H
