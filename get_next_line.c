
#include "get_next_line.h"

#include <stdio.h>
char *get_next_line(int fd)
{
    static char buff[BUFFSIZE];
    char *begin_cursor;
    char *end_cursor;
    ssize_t len;
    char *new_str;

    begin_cursor = my_checknullstream(buff, BUFFSIZE);

    if(*begin_cursor == '\0' || begin_cursor == &(buff[BUFFSIZE-1]))
    {
        len = read(fd, buff, BUFFSIZE);
        if(len == 0)
            return NULL;
        begin_cursor = buff;
    }
    end_cursor = my_strnchr(begin_cursor, &(buff[BUFFSIZE-1]) - begin_cursor, '\n');
    new_str = my_strndup(begin_cursor, end_cursor);
    my_bzerorange(begin_cursor, end_cursor);
    
    return new_str;
}