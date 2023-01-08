/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:31:39 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/07 05:03:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_str.h"

size_t	lp_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	dstlen;
	size_t	srclen;

	if ((!dst || !src) && !size)
		return (0);
	dstlen = lp_strlen(dst);
	srclen = lp_strlen(src);
	if (size <= dstlen)
		return (srclen + size);
	while (*dst)
		dst++;
	if (dstlen + srclen + 1 < size)
		size = dstlen + srclen + 1;
	i = 0;
	while (dstlen + i < size - 1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (dstlen + srclen);
}
