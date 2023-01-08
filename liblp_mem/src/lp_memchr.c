/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:29:04 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/07 05:03:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_mem.h"

void	*lp_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ptdr;
	unsigned char	ptr;

	ptdr = (unsigned char *)s;
	ptr = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (ptdr[i] == ptr)
			return (ptdr + i);
		i++;
	}
	return (NULL);
}
