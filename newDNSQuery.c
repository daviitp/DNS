#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>
//#include <sys/socket.h>
//#include <netdb.h>

//struct addrinfo hints, *infoptr; // So no need to use memset global variables

int main() {

    char inbuf[256];
    int len;

    FILE *archivo;
    archivo = fopen("urls.txt","r");

    int i = 1;

    //while (feof(archivo) == 0)
    //{
        do {
            fgets(inbuf, 256, archivo);
            //len = strlen(inbuf);
            //inbuf[len-1] = '\0';
            //if(strlen(inbuf) > 0)
                printf("%d",i);
                printf("%s",inbuf);
                i = i + 1;
            //else
            //    return EXIT_SUCCESS;
        } while(feof(archivo) == 0);
    //}
}


#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

struct addrinfo hints, *infoptr; // So no need to use memset global variables

int main() {

    FILE *archivo;
    archivo = fopen("urls.txt","r");

    char url[256] = "www.bbc.com";

    hints.ai_family = AF_INET; // AF_INET means IPv4 only addresses

    int result = getaddrinfo(url, NULL, &hints, &infoptr);
    if (result) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(result));
        exit(1);
    }

    struct addrinfo *p;
    char host[256];

    for (p = infoptr; p != NULL; p = p->ai_next) {

        getnameinfo(p->ai_addr, p->ai_addrlen, host, sizeof (host), NULL, 0, NI_NUMERICHOST);
        printf("%s: %s\n",url,host);
    }

    freeaddrinfo(infoptr);
    return 0;
}


