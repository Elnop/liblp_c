/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:36:40 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/07 05:03:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_str.h"

char	*lp_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*cpy;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	cpy = lp_strdup(s);
	if (!cpy)
		return (cpy);
	i = 0;
	while (cpy[i])
	{
		cpy[i] = f(i, cpy[i]);
		i++;
	}
	return (cpy);
}
