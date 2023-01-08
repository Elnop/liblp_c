/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 03:45:15 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/07 05:03:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_str.h"

char	*lp_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if (!*little || little == big)
		return ((char *)big);
	while (len > 0 && *big)
	{
		i = 0;
		while (i < len && little[i] == big[i] && big[i])
			i++;
		if (!little[i])
			return ((char *)big);
		big++;
		len--;
	}
	return (NULL);
}
