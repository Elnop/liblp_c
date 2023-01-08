/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 05:43:35 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/07 05:03:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_str.h"

char	*lp_substr(char const *s, unsigned int start, size_t len)
{
	char		*sub;
	size_t		s_len;
	size_t		i;

	s_len = lp_strlen(s);
	if (start >= s_len)
	{
		sub = malloc(sizeof(char));
		if (!sub)
			return (NULL);
		*sub = 0;
		return (sub);
	}
	if (s_len - (start) < len)
		len = s_len - (start);
	sub = malloc((len + 1) * sizeof(char));
	if (!sub)
		return (NULL);
	s += start;
	i = -1;
	while (++i < len && s[i])
		sub[i] = s[i];
	sub[i] = 0;
	return (sub);
}
