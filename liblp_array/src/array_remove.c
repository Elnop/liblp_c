/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:30:42 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/30 20:46:15 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

void	array_remove(t_array array, size_t index)
{
	size_t	size;
	size_t	elemsize;

	size = array_size(array);
	elemsize = array_elemsize(array);
	if (array_header(array)->destroy_elem)
		array_header(array)->destroy_elem(array + index * elemsize);
	if (size - 1 < index)
		return ;
	lp_memmove(
		array + index * elemsize,
		array + (index + 1) * elemsize,
		elemsize * (size - index - 1));
	array_header(array)->size = size - 1;
}
