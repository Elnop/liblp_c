/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 05:12:18 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 01:04:01 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	array_sort(t_array array, bool (*f)(void *a, void *b))
{
	size_t	elemsize;
	size_t	i;
	void	*elem1;
	void	*elem2;

	elemsize = array_elemsize(array);
	i = 0;
	if (array_size(array) < 2)
		return (array);
	while (!array_issort(array, f))
	{
		if (i * elemsize == (array_size(array) - 1) * elemsize)
			i = 0;
		elem1 = array + i * elemsize;
		elem2 = array + (i + 1) * elemsize;
		if (!f(elem1, elem2))
			lp_memswap(elem1, elem2, elemsize);
		i++;
	}
	return (array);
}
