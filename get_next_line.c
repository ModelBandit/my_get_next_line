#include "get_next_line.h"

#define BUFFSIZE 1024

char buff[BUFFSIZE];

char *get_next_line(int fd)
{
    read(fd, buff, BUFFSIZE);
}