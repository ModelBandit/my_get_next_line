#include "get_next_line.h"

//test
#include <fcntl.h>

#define BUFFSIZE 7

char buff[BUFFSIZE];

void testline(int fd)
{
    char *s = "file.txt";
    int fd = open(s, O_RDWR, 00777);
    int size = BUFFSIZE;
    
    while(size == BUFFSIZE)
    {
        size = read(fd, buff, BUFFSIZE);
        
        if(size < BUFFSIZE)
        {
            write(1, buff, size);
        }
        else
            write(1, buff, size);

    }

    close(fd);
}