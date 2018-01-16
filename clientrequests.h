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

#define REGISTER 1
#define LOGIN 2
#define LOGOUT 3

class ClientRequests
{
public:
    ClientRequests();
    ~ClientRequests();
    bool ConnectToServer();
    int ParseActions(int request_type, char* request_buffer);
    void SetUserId(int id);
    int GetUserId();
    int GetConnectionStatus();
    void SetConnectionStatus(bool status);
    void SetLoggedStatus(bool status);
    int GetLoggedStatus();

private:
    /* portul de conectare la server*/
    int port;

    int sd;			// descriptorul de socket
    struct sockaddr_in server;	// structura folosita pentru conectare
    char msg[100];		// mesajul trimis

    bool logged;
    int user_id; // user id in mysql and sqlite name
    bool connected_to_server;
    int retries = 1;
};

#endif // CLIENTREQUESTS_H
