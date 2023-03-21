/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/27 18:15:21 by lperroti          #+#    #+#             */
/*   Updated: 2023/02/27 00:28:50 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	get_linelen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i + 1);
		i++;
	}
	return (0);
}

char	*ft_strdupline(char *str)
{
	char	*dup;
	size_t	len;

	len = get_linelen(str);
	if (!len)
		len = ft_strlen(str);
	if (!len)
		return (NULL);
	dup = malloc((len + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	dup[len] = 0;
	while (len > 0)
	{
		len--;
		dup[len] = str[len];
	}
	return (dup);
}

char	*join_buffers(
		char *first_s, char *second_s)
{
	char	*out_str;
	size_t	i;
	size_t	j;

	i = ft_strlen(first_s);
	j = ft_strlen(second_s);
	if (get_linelen(second_s))
		j = get_linelen(second_s);
	out_str = malloc((i + j + 1) * sizeof(char));
	if (!out_str)
		return (NULL);
	out_str[j + i] = 0;
	while (j > 0)
	{
		j--;
		out_str[j + i] = second_s[j];
	}
	while (i > 0)
	{
		i--;
		out_str[i] = first_s[i];
	}
	return (free(first_s), out_str);
}

void	update_buffer(char *buffer, char *new_buffer)
{
	size_t	i;

	i = 0;
	while (new_buffer[i])
	{
		buffer[i] = new_buffer[i];
		i++;
	}
	buffer[i] = 0;
}
