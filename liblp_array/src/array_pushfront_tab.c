/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_pushfront_tab.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:41:34 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/14 10:42:02 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	array_pushfront_tab(t_array *parray, void *elems, size_t elems_count)
{
	size_t	i;

	if (array_capacity(*parray) < array_size(*parray) + elems_count)
		array_grow(parray,
			elems_count - (array_capacity(*parray) - array_size(*parray))
			);
	i = 0;
	while (i < elems_count)
	{
		array_pushfront(parray, (char *)elems + i * array_elemsize(*parray));
		i++;
	}
	return (*parray);
}
