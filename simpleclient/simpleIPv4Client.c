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

    int socketFileDescriptor = -1;
    int addrInfoStatus = -1;
    size_t lengthOfSentData;
    ssize_t numBytesReadFromServer;

    struct addrinfo hints;              // Hints to send to getaddrinfo
    struct addrinfo *result;            // Result from getaddrinfo
    struct addrinfo *sucessfulResult;   // Result pointer for successful connect.

    memset(&hints, 0, sizeof(hints));
    return 0;
}
