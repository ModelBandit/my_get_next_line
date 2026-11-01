/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:52:35 by chchoi            #+#    #+#             */
/*   Updated: 2026/11/01 16:55:59 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*begin_cursor;
	char		*end_cursor;
	ssize_t		len;
	char		*new_str;

	begin_cursor = my_checknullstream(buff, BUFFER_SIZE);
	if (*begin_cursor == '\0')
	{
		len = read(fd, buff, BUFFER_SIZE);
		if (len <= 0)
			return (NULL);
		begin_cursor = buff;
	}
	end_cursor = my_strnchr(begin_cursor, &(buff[BUFFER_SIZE - 1])
			- begin_cursor, '\n');
	new_str = my_strndup(begin_cursor, end_cursor);
	if (new_str == NULL)
		return (NULL);
	my_bzerorange(begin_cursor, end_cursor);
	return (new_str);
}
