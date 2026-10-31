/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:52:51 by chchoi            #+#    #+#             */
/*   Updated: 2026/10/31 14:53:00 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_NEXT_LINE_H
# define FT_GET_NEXT_LINE_H

# define BUFFSIZE 1024

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);

char	*my_checknullstream(char *b_stream, ssize_t len);
char	*my_strnchr(const char *str, ssize_t len, char chr);
char	*my_strndup(const char *start_ptr, const char *end_ptr);
void	my_bzerorange(char *start_ptr, char *end_ptr);

#endif
