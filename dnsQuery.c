#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int
lookup_host (const char *host)
{
    struct addrinfo hints, *res;
    int errcode;
    char addrstr[150];
    void *ptr;

    FILE *results;
        results = fopen("resultados.txt","w");

    FILE *detection;
        detection = fopen("detecciones.txt","w");

    memset (&hints, 0, sizeof (hints));
    hints.ai_family = PF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags |= AI_CANONNAME;

    errcode = getaddrinfo (host, NULL, &hints, &res);
    if (errcode != 0)
        {
        fprintf (detection, "Host: %s\n", host);
        return -1;
        }

    while (res)
        {
        inet_ntop (res->ai_family, res->ai_addr->sa_data, addrstr, 150);

        switch (res->ai_family)
            {
            case AF_INET:
            ptr = &((struct sockaddr_in *) res->ai_addr)->sin_addr;
            break;
            case AF_INET6:
            ptr = &((struct sockaddr_in6 *) res->ai_addr)->sin6_addr;
            break;
            }
        inet_ntop (res->ai_family, ptr, addrstr, 150);
        fprintf (results, "Host: %s\n", host);
        fprintf (results, "IPv%d address: %s (%s)\n", res->ai_family == PF_INET6 ? 6 : 4,
                addrstr, res->ai_canonname);
        res = res->ai_next;
        }

    return 0;
}

int main (void)
{

    char inbuf[256];
    int len;

        FILE *archivo;
        archivo = fopen("urls.txt","r");

        if (archivo == NULL)
                exit(1);
        else
        {
            while (feof(archivo) == 0)
            {
            do {
            bzero(inbuf, 256);
            fgets(inbuf, 256, archivo);
            len = strlen(inbuf);
            inbuf[len-1] = '\0';
            if(strlen(inbuf) > 0)
                lookup_host (inbuf);
            else
                return EXIT_SUCCESS;
			} while(1);
		}
    }
}