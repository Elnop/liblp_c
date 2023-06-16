/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 14:07:43 by lperroti          #+#    #+#             */
/*   Updated: 2023/06/16 13:40:27 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

void	update_fds_list(char *buffer)
{
	size_t	linelen;
	size_t	i;

	linelen = get_linelen(buffer);
	if (!linelen)
	{
		buffer[0] = 0;
		return ;
	}
	else
	{
		i = 0;
		while (buffer[i + linelen])
		{
			buffer[i] = buffer[i + linelen];
			i++;
		}
		buffer[i] = 0;
	}
}

char	*get_next_line(int fd)
{
	static char	fds_list[FD_MAX + 1][(BUFFER_SIZE > 0) * BUFFER_SIZE + 1];
	char		new_buffer[(BUFFER_SIZE > 0) * BUFFER_SIZE + 1];
	int			read_count;
	size_t		linelen;
	char		*line;

	if (fd < 0 || fd >= FD_MAX || (BUFFER_SIZE > 0) * BUFFER_SIZE == 0)
		return (NULL);
	read_count = BUFFER_SIZE;
	if (!fds_list[fd][0])
		read_count = read(fd, fds_list[fd], BUFFER_SIZE);
	fds_list[fd][(read_count > 0) * read_count] = 0;
	line = ft_strdupline(fds_list[fd]);
	linelen = get_linelen(line);
	while (read_count == BUFFER_SIZE && !linelen)
	{
		read_count = read(fd, new_buffer, BUFFER_SIZE);
		if (read_count == -1)
			return (free(line), NULL);
		new_buffer[read_count] = 0;
		line = join_buffers(line, new_buffer);
		linelen = get_linelen(line);
		update_buffer(fds_list[fd], new_buffer);
	}
	return (update_fds_list(fds_list[fd]), line);
}
