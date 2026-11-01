/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:52:51 by chchoi            #+#    #+#             */
/*   Updated: 2026/11/02 07:51:31 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <stdlib.h>
# include <unistd.h>
char	*get_next_line(int fd);

char	*my_checknullstream(char *b_stream, ssize_t len);
char	*my_strnchr(const char *str, ssize_t len, char chr);
void	my_strpdup(const char *start_ptr, const char *end_ptr, char **new_str);
void	my_bzerorange(char *start_ptr, char *end_ptr);
ssize_t	my_strlen(const char *str);

#endif
