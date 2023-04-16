/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_strfusion.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 12:05:09 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/16 17:09:13 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_str.h"

char	*lp_strfusion(char **p_s1, char *s2)
{
	char	*str;
	char	*s1;
	size_t	y;
	int		i;

	s1 = *p_s1;
	str = malloc((lp_strlen(s1) + lp_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (free(*p_s1), free(s2), NULL);
	i = 0;
	while (s1 && *s1)
	{
		str[i++] = *s1;
		s1++;
	}
	y = 0;
	while (s2 && s2[y])
	{
		str[i++] = s2[y];
		y++;
	}
	str[i] = 0;
	free(*p_s1);
	*p_s1 = str;
	return (free(s2), str);
}
