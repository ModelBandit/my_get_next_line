/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:52:35 by chchoi            #+#    #+#             */
/*   Updated: 2026/11/02 11:18:36 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*s_ptr;
	char		*e_ptr;
	ssize_t		len;
	char		*s;

	s = NULL;
	while (s == NULL || (s[my_len(s) - 1] != '\n' && s[my_len(s) - 1] != '\0'))
	{
		len = my_checknullstream(buff, fd, &s_ptr);
		if (len == 0)
			break ;
		else if (len == -1)
		{
			if (s != NULL)
				free(s);
			return (NULL);
		}
		e_ptr = my_strnchr(s_ptr, &(buff[BUFFER_SIZE - 1]) - s_ptr, '\n');
		s = my_strpdup(s_ptr, e_ptr, &s);
		if (s == NULL)
			return (NULL);
	}
	return (s);
}
