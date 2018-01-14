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

    /* ne conectam la server */
    if (connect (sd, (struct sockaddr *) &server,sizeof (struct sockaddr)) == -1)
      {
        perror ("[client]Eroare la connect().\n");
      }
}

void ClientRequests::ParseActionsQueue()
{
    /* citirea mesajului */
    while(1)
    {
    bzero (msg, 100);
    printf ("[client]Selectati actiune: ");
    fflush (stdout);
    msg[0] = 'n';
    msg[1] = 'u';
    msg[2] = 'm';
    msg[3] = 'e';
    if(msg[0] == 'q')
    {
       break;
    }

    /* trimiterea mesajului la server */
    if (write (sd, msg, 100) <= 0)
      {
        perror ("[client]Eroare la write() spre server.\n");
      }

    /* citirea raspunsului dat de server
       (apel blocant pina cind serverul raspunde) */

    if (read (sd, msg, 100) < 0)
      {
        perror ("[client]Eroare la read() de la server.\n");
      }
    /* afisam mesajul primit */
    printf ("[client]Mesajul primit este: %s\n", msg);
    }
    /* inchidem conexiunea, am terminat */
    close (sd);
}
