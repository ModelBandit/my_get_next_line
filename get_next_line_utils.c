/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:52:43 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/31 14:53:35 by chchoi           ###   ########.fr       */
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
	ssize_t	i;

	i = 0;
	while (i < len)
	{
		if (str[i] == chr)
			return (&(str[i]));
		++i;
	}
	return (&(str[i - 1]));
}

char	*my_strndup(const char *start_ptr, const char *end_ptr)
{
	char	*n_str;
	ssize_t	i;
	ssize_t	len;

	len = end_ptr - start_ptr;
	n_str = malloc(len + 1);
	i = 0;
	while (i <= len)
	{
		n_str[i] = start_ptr[i];
		++i;
	}
	return (n_str);
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