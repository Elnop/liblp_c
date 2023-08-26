/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:30:42 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/25 18:53:49 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

void	array_remove(t_array array, size_t index)
{
	if (array_size(array) - 1 < index)
		return ;
	if (array_header(array)->elem_destructor)
		array_header(array)->elem_destructor(array + index);
	lp_memmove(
		array + index *  array_elemsize(array),
		array + (index + 1) * array_elemsize(array),
		array_elemsize(array) * (array_size(array) - index - 1));
	array_set_size(array, array_size(array) - 1);
}
