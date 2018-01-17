#include "clientrequests.h"

ClientRequests::ClientRequests()
{
    this->port = 2728;

    /* cream socketul */
    if ((this->sd = socket (AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror ("[client] Eroare la socket().\n");
    }


    /* umplem structura folosita pentru realizarea conexiunii cu serverul */
    /* familia socket-ului */
    server.sin_family = AF_INET;
    /* adresa IP a serverului */
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    /* portul de conectare */
    server.sin_port = htons (port);

    ConnectToServer();
}

ClientRequests::~ClientRequests()
{
    /* inchidem conexiunea, am terminat */
    close (this->sd);
}

bool ClientRequests::ConnectToServer()
{
    /* ne conectam la server */
    this->connected_to_server = connect (sd, (struct sockaddr *) &server,sizeof (struct sockaddr)) + 1;
    if ( this->connected_to_server == 0)
    {
        perror ("[client]Eroare la connect().\n");
        return false;
    }
    return true;
}

int ClientRequests::ParseActions(int request_type, char* request_buffer)
{
    /* citirea mesajului */
    bzero (msg, 100);
    printf ("[client]Actiune selectata: %d!\n", request_type);
    fflush (stdout);

    /* trimiterea mesajului la server */
    if (write (sd, request_buffer, sizeof(int) + strlen(request_buffer + sizeof(int))) <= 0)
      {
        perror ("[client]Eroare la write() spre server.\n");
        fflush(stdout);

        this->connected_to_server = ConnectToServer();
        if(this->connected_to_server && retries)
        {
            return ParseActions(request_type, request_buffer);
        }
        else
        {
            retries--;
            return false;
        }
      }
    this->retries = 1;

    /* citirea raspunsului dat de server
       (apel blocant pina cind serverul raspunde) */

    if (read (sd, msg, 100) < 0)
      {
        perror ("[client] Eroare la read() de la server.\n");
      }
    /* afisam mesajul primit */
    printf ("[client]Mesajul primit este: %s\n", msg);

    if(strcmp(msg, "-1"))
    {
        if(request_type == LOGIN)
        {
            this->logged = true;
            memcpy(&(this->user_id), msg, sizeof(int));
        }
        return true;
    }
    return false;
}

void ClientRequests::SetUserId(int id)
{
    this->user_id = id;
}

int ClientRequests::GetUserId()
{
    return this->user_id;
}

int ClientRequests::GetConnectionStatus()
{
    return this->connected_to_server;
}

void ClientRequests::SetConnectionStatus(bool status)
{
    this->connected_to_server = status;
}

void ClientRequests::SetLoggedStatus(bool status)
{
    this->logged = status;
}

int ClientRequests::GetLoggedStatus()
{
    return this->logged;
}
