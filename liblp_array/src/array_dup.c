/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 02:39:25 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/25 22:16:44 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	array_dup(t_array array)
{
	t_array			dup;

	dup = array_new(
		array_capacity(array),
		array_elemsize(array),
		array_header(array)->elem_copy,
		array_header(array)->elem_destructor);
	lp_memcpy(dup, array, array_size(array) * array_elemsize(array));
	array_set_size(dup, array_size(array));
	return (dup);
}
