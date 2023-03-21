/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:08:25 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/14 21:40:08 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif
# if (BUFFER_SIZE < 0)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 0
# endif
# if (BUFFER_SIZE > 100000)
#  undef BUFFER_SIZE
#  define BUFFER_SIZE 100000
# endif
# ifndef FD_MAX
#  define FD_MAX 1024
# endif

char	*get_next_line(int fd);
size_t	ft_strlen(char *str);
size_t	get_linelen(char *str);
char	*ft_strdupline(char *str);
char	*join_buffers(char *first_s, char *second_s);
void	update_buffer(char *buffer, char *new_buffer);

#endif