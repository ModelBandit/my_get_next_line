/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:52:43 by chchoi            #+#    #+#             */
/*   Updated: 2026/11/02 07:51:33 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*my_checknullstream(char *b_stream, ssize_t len)
{
	ssize_t	i;

	i = 0;
	while (i < len)
	{
		if (b_stream[i] != '\0')
			return (&(b_stream[i]));
		++i;
	}
	return (&(b_stream[i - 1]));
}

char	*my_strnchr(const char *str, ssize_t len, char chr)
{
	char	*ptr;
	ssize_t	i;

	ptr = (char *)str;
	i = 0;
	while (i <= len)
	{
		if (ptr[i] == chr || ptr[i] == '\0')
			return (&(ptr[i]));
		++i;
	}
	return (&(ptr[i - 1]));
}

void	my_strpdup(const char *start_ptr, const char *end_ptr, char **new_str)
{
	char	*n_str;
	ssize_t	i;
	ssize_t	j;
	ssize_t	len;

	len = my_strlen(*new_str);
	n_str = malloc(end_ptr - start_ptr + 2 + len);
	i = 0;
	while (*new_str != NULL && i < len)
	{
		n_str[i] = (*new_str)[i];
		++i;
	}
	if (*new_str != NULL)
		free(*new_str);
	j = 0;
	while (j <= end_ptr - start_ptr)
	{
		n_str[i + j] = start_ptr[j];
		++j;
	}
	n_str[i + j] = '\0';
	*new_str = n_str;
}

void	my_bzerorange(char *start_ptr, char *end_ptr)
{
	ssize_t	i;
	ssize_t	len;

	i = 0;
	len = end_ptr - start_ptr;
	while (i <= len)
	{
		start_ptr[i] = '\0';
		++i;
	}
}

ssize_t	my_strlen(const char *str)
{
	ssize_t	i;

	if (str == NULL)
		return (0);
	i = 0;
	while (str[i] != '\0')
		++i;
	return (i);
}

// test
// #include <fcntl.h>

// #define BUFFSIZE 7

// char buff[BUFFSIZE];

// void testline(int fd)
// {
//     char *s = "file.txt";
//     int fd = open(s, O_RDWR, 00777);
//     int size = BUFFSIZE;

//     while(size == BUFFSIZE)
//     {
//         size = read(fd, buff, BUFFSIZE);

//         if(size < BUFFSIZE)
//         {
//             write(1, buff, size);
//         }
//         else
//             write(1, buff, size);

//     }

//     close(fd);
// }