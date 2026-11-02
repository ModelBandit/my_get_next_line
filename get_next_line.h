/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchoi <chchoi@student.42gyeongsan.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/31 14:52:51 by chchoi            #+#    #+#             */
/*   Updated: 2026/11/02 11:20:37 by chchoi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*my_strnchr(const char *str, ssize_t len, char chr);
char	*my_strpdup(char *start_ptr, char *end_ptr, char **new_str);
ssize_t	my_checknullstream(char *buff, int fd, char **str);
ssize_t	my_release_swap(char *dst, char **src, ssize_t f_len);
ssize_t	my_len(const char *str);

#endif
