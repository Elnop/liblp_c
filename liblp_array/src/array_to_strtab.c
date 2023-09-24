/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_to_strtab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 23:29:24 by lperroti          #+#    #+#             */
/*   Updated: 2023/09/24 23:35:54 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

char	**array_to_strtab(t_array arr)
{
	char	**strtab;
	size_t	i;

	if (!arr)
		return (NULL);
	strtab = malloc(array_size(arr) * sizeof(char *));
	if (!strtab)
		return (NULL);
	i = 0;
	while (i < array_size(arr) - 1)
	{
		strtab[i] = lp_strdup(((char **)arr)[i]);
		if (!strtab[i])
			return (lp_free_strtab(strtab, i), NULL);
		i++;
	}
	strtab[i] = NULL;
	return (strtab);
}
