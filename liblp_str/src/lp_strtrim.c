/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:42:11 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/10 05:25:12 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_str.h"

static int	lp_ischarset(char c, const char *charsets)
{
	while (*charsets)
	{
		if (*charsets == c)
			return (1);
		charsets++;
	}
	return (0);
}

static size_t	lp_strlen_trimed(const char *str, const char *charsets)
{
	size_t	len;

	while (*str && lp_ischarset(*str, charsets))
		str++;
	if (!*str)
		return (0);
	len = 0;
	while (*str++)
		len++;
	str -= 2;
	while (lp_ischarset(*str, charsets) && *str--)
		len--;
	return (len);
}

char	*lp_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	len;

	len = lp_strlen_trimed(s1, set);
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (*s1 && lp_ischarset(*s1, set))
		s1++;
	while (i < len)
		str[i++] = *s1++;
	str[i] = 0;
	return (str);
}
