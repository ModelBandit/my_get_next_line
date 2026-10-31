
#ifndef FT_GET_NEXT_LINE_H
#define FT_GET_NEXT_LINE_H

#define BUFFSIZE 1024

#include <stdlib.h>
#include <unistd.h>

char *get_next_line(int fd);

char *my_checknullstream(char *b_stream, ssize_t len);
char *my_strnchr(const char *str, ssize_t len, char chr);
char *my_strndup(const char *start_ptr, const char *end_ptr);
void my_bzerorange(char *start_ptr, char *end_ptr);

#endif