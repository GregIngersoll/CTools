#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/un.h>
#include "socket_utilities.h"

#define BUF_SIZE 255

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        fail_miserably("Need at least 1 argument for socket file");       
    }

    const char * socket_filename = argv[1];

    int fd = -1;

    int sock_fd = socket(AF_UNIX, SOCK_STREAM, 0);
    if (sock_fd == -1)
    {
        fail_miserably("Unable to create Socket");
    }

    struct sockaddr_un addr;
    memset(&addr, 0, sizeof(addr));
    addr.sun_family = AF_UNIX;
    strncpy(addr.sun_path, socket_filename, sizeof(addr.sun_path)-1);

    unlink(socket_filename);
   
    socklen_t addrlen = sizeof (addr);

    int connect_retval = connect(sock_fd, (struct sockaddr *) &addr, addrlen);
    if (connect_retval == -1)
    {
        fail_miserably("Unable to connect Socket");
    }

    const char * foo = "Hello, world";
    write(sock_fd, foo, strlen(foo));

    char buf[BUF_SIZE];
    read(sock_fd, buf, BUF_SIZE);


    close (sock_fd);
    unlink(socket_filename);
}