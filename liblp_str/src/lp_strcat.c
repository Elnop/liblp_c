/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 11:46:05 by lperroti          #+#    #+#             */
/*   Updated: 2023/03/21 19:42:04 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_str.h"

bool	lp_strcat(char **s1, char const *s2)
{
	char	*str;
	char	*cp_s1;
	int		i;

	str = malloc((lp_strlen(*s1) + lp_strlen(s2) + 1) * sizeof(char));
	if (!str)
		return (false);
	i = 0;
	cp_s1 = *s1;
	if (!cp_s1)
		cp_s1 = "";
	while (*cp_s1)
	{
		str[i++] = *cp_s1;
		cp_s1++;
	}
	free(*s1);
	while (*s2)
	{
		str[i++] = *s2;
		s2++;
	}
	str[i] = 0;
	*s1 = str;
	return (true);
}
