/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:52:43 by chchoi            #+#    #+#             */
/*   Updated: 2026/11/02 11:18:28 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

ssize_t	my_checknullstream(char *buff, int fd, char **str)
{
	ssize_t	i;
	ssize_t	len;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (buff[i] != '\0')
		{
			(*str) = &(buff[i]);
			return (BUFFER_SIZE - i);
		}
		++i;
	}
	len = read(fd, buff, BUFFER_SIZE);
	(*str) = buff;
	return (len);
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

char	*my_strpdup(char *start_ptr, char *end_ptr, char **new_str)
{
	char	*n_str;
	ssize_t	i;
	ssize_t	j;
	ssize_t	len;

	len = my_len(*new_str);
	n_str = malloc(end_ptr - start_ptr + 2 + len);
	if (n_str == NULL)
	{
		if (*new_str != NULL)
			free(*new_str);
		return (NULL);
	}
	i = 0;
	if (*new_str != NULL)
		i = my_release_swap(n_str, new_str, len);
	j = 0;
	while (j <= end_ptr - start_ptr)
	{
		n_str[i + j] = start_ptr[j];
		start_ptr[j++] = '\0';
	}
	n_str[i + j] = '\0';
	return (n_str);
}

ssize_t	my_release_swap(char *dst, char **src, ssize_t f_len)
{
	ssize_t	i;

	i = 0;
	while (i < f_len)
	{
		dst[i] = (*src)[i];
		++i;
	}
	free(*src);
	return (i);
}

ssize_t	my_len(const char *str)
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