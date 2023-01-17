/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_issort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 05:17:12 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/10 12:58:04 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

bool	array_issort(t_array array, bool (*f)(void *a, void *b))
{
	size_t	size;
	size_t	elemsize;
	size_t	i;

	size = array_size(array);
	elemsize = array_elemsize(array);
	i = 0;
	if (size < 2)
		return (true);
	while (i * elemsize < (size - 1) * elemsize)
	{
		if (!f(array + i * elemsize, array + (i + 1) * elemsize))
			return (false);
		i++;
	}
	return (true);
}
