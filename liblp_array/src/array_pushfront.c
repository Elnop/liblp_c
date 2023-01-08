/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_pushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:00:42 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/07 05:03:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

void	array_pushfront(t_array	array, void	*elem)
{
	size_t	size;
	size_t	elemsize;
	size_t	capacity;

	size = array_size(array);
	elemsize = array_elemsize(array);
	capacity = array_capacity(array);
	if (size == capacity)
		return ;
	if (size)
		lp_memmove(array + 1 * elemsize, array, size * elemsize);
	lp_memcpy(array, elem, elemsize);
	array_set_size(array, size + 1);
}
