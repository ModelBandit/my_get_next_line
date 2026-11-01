/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:52:35 by chchoi            #+#    #+#             */
/*   Updated: 2026/11/02 07:52:00 by chchoi           ###   ########.fr       */
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

	new_str = NULL;
	end_cursor = buff;
	while (new_str == NULL || new_str[my_strlen(new_str)-1] != '\n')
	{
		begin_cursor = my_checknullstream(buff, BUFFER_SIZE);
		if (*begin_cursor == '\0')
		{
			len = read(fd, buff, BUFFER_SIZE);
			if (len <= 0)
				break;
			begin_cursor = buff;
		}
		end_cursor = my_strnchr(begin_cursor, &(buff[BUFFER_SIZE - 1])
				- begin_cursor, '\n');
		my_strpdup(begin_cursor, end_cursor, &new_str);
		if (new_str == NULL)
			return (NULL);
		my_bzerorange(begin_cursor, end_cursor);
	}
	return (new_str);
}
