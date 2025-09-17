#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// Reads from stdin, and writes to stdout and stderr.
int main (int argc, char *argv[])
{
    // Method 1: fgets.
    char buffer[255];
    if (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        fprintf (stdout,  "%s\n", buffer);
        fprintf (stderr,  "%s\n", buffer);
    }

    return 0;

}
