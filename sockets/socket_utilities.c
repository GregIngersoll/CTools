#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "socket_utilities.h"

// fail_miserably:  Print an error message and terminate
void fail_miserably(char * message)
{    
    perror (message);
    exit (EXIT_FAILURE);
}

// Copies data From one filedesc to another filedesc.
void copyData (int from, int to)
{
    char buf[1024];
    int amount = -1;

    while ((amount = read(from, buf, sizeof(buf))) > 0)
    {
        if (write(to, buf, amount) != amount)
        {
            fail_miserably("Failed on write:  amount of data didn't match up");
            return;
        }
    }

    if (amount < 0)
    {
        fail_miserably("Failed on read:  no amount of data read");
    }
}