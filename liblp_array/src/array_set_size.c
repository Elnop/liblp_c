/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_set_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 05:34:21 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/26 01:39:42 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

/**
 * @brief set size of array (elems are auto destroyed)
 * 
 * @param array
 * @param size new size of array
 */
void	array_set_size(t_array array, size_t size)
{
	t_array_header	*pheader;
	size_t			i;

	pheader = array_header(array);
	if (pheader->size > size)
	{
		i = pheader->size - size;
		while (pheader->size + i > size)
		{
			array_remove(array, pheader->size + i);
			--i;
		}
	}
	else if (pheader->size < size)
	{
		array_grow(&array, size - pheader->size);
	}
}
