/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_str_isequal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:09:01 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 03:17:08 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_str.h"

bool	lp_str_isequal(const char *s1, const char *s2)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (str1[i] && str2[i] && !(s1[i] - str2[i]))
		i++;
	if (str1[i] || str2[i])
		return (false);
	return (true);
}
