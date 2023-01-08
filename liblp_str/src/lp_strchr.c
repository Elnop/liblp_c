/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:31:01 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/07 05:03:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*lp_strchr(char const *s, int c)
{
	size_t	i;

	if (*s == (unsigned char)c)
		return ((char *)s);
	i = 0;
	while (s[i])
	{
		i++;
		if (s[i] == (unsigned char)c)
			return ((char *)s + i);
	}
	return (NULL);
}
