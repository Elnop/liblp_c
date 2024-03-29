/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_grow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:56:09 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/31 22:27:30 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	array_grow(t_array *parray, size_t grow)
{
	t_array	new_array;

	new_array = array_pushback_tab(
			(t_array []){array_new(
				array_capacity(*parray) + grow,
				array_elemsize(*parray),
				array_header(*parray)->copy_elem,
				array_header(*parray)->destroy_elem)},
			*parray,
			array_size(*parray)
			);
	array_free(*parray);
	*parray = new_array;
	return (new_array);
}
