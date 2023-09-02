/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_pool_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/02 07:52:05 by lperroti          #+#    #+#             */
/*   Updated: 2023/09/02 07:54:43 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 02:45:42 by lperroti          #+#    #+#             */
/*   Updated: 2022/10/04 18:52:27 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_str.h"

static int	is_charset(char c, char *charset)
{
	while (*charset)
	{
		if (c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

static int	wordsize(char *str, char *charset)
{
	int	count;

	count = 0;
	while (!is_charset(str[count], charset) && str[count])
		count++;
	return (count + 1);
}

static char	*first_word(char **str, char *charset)
{
	int		i;
	char	*word;

	word = malloc((wordsize(*str, charset)) * sizeof(char));
	if (!word)
		return (NULL);
	i = 0;
	while (!is_charset(**str, charset) && **str)
	{
		word[i] = **str;
		(*str)++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**lp_pool_split(char *str, char *charset)
{
	char	**tab;
	int		tab_index;

	tab = malloc(lp_strlen(str) * sizeof(char *));
	if (!tab)
		return (NULL);
	tab_index = 0;
	while (*str)
	{
		while (is_charset(*str, charset) && *str)
			str++;
		if (!*str)
			break ;
		tab[tab_index] = first_word(&str, charset);
		tab_index++;
	}
	tab[tab_index] = NULL;
	return (tab);
}
