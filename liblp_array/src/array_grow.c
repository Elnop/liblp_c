/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_grow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:56:09 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/26 04:10:16 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	array_grow(t_array *parray, size_t grow)
{
	t_array	new_array;

	if (!parray || !*parray)
		return (NULL);
	new_array = array_pushback_tab(
		(t_array []){
			array_new(
				array_capacity(*parray) + grow,
				array_elemsize(*parray),
				array_header(*parray)->elem_copy,
				array_header(*parray)->elem_destructor)
		},
		*parray,
		array_size(*parray));
	array_destroy(*parray);
	*parray = new_array;
	return (*parray);
}
