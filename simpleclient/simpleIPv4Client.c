#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// When dealing with sockets, nothing is really simple.
// --help | -h:  display help message
int main (int argc, char* argv[])
{
    if (argc != 3)
    {
        printf ("\nUsage:  simpleIPv4Cliet <ip-address> <port>\n");
        printf ("\t<ip-address>:\tIP Address for connect().\n");
        printf ("\t<port>:\t\tPort for connect().\n\n");
        return 0;
    }
    char* ipValue = argv[1];
    char* portNumber = argv[2];

    int socketFileDescriptor = -1;
    int addrInfoStatus = -1;
    size_t lengthOfSentData;
    ssize_t numBytesReadFromServer;

    struct addrinfo hints;              // Hints to send to getaddrinfo
    struct addrinfo *allResults;            // Result from getaddrinfo
    struct addrinfo *result;   // Result pointer for successful connect.

    memset(&hints, 0, sizeof(hints));

    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_flags = 0;
    hints.ai_protocol = 0;

    addrInfoStatus = getaddrinfo (ipValue, portNumber, &hints, &allResults);
    if (addrinfoStatus != 0)
    {
        fprintf(stderr, "Error with geaddrinfo: %s\n", gai_strerror(addrInfoStatus));
        exit(EXIT_FAILURE);
    }

    for (result = allResults; result != NULL; result = result->ai_next)
    {
        if (result == NULL)
            break;

        socketFileDescriptor = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
        if (socketFileDescriptor == -1)
            continue;

        if (connect(socketFileDescriptor, result->ai_addr, result->ai_addrlen) != -1)
            break;

        close(socketFileDescriptor);
    }

    freeaddrinfo (result);

    if (result == NULL)
    {
        fprintf (stderr, "Could not connect to IPv4 Address %s and port %s\n", ipValue, portNumber);
        exit (EXIT_FAILURE);
    }

    // Read from stan

    return 0;
}
