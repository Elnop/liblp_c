/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 02:39:25 by lperroti          #+#    #+#             */
/*   Updated: 2023/11/30 00:14:19 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	array_dup(t_array src)
{
	t_array			dup;

	dup = array_new(array_capacity(src), array_elemsize(src),
			array_header(src)->copy_elem,
			array_header(src)->destroy_elem);
	if (!dup)
		return (NULL);
	if (array_header(src)->copy_elem)
	{
		if (!array_pushback_tab(&dup, src, array_size(src)))
			return (NULL);
	}
	else
		lp_memcpy(dup, src, array_size(src) * array_elemsize(src));
	array_set_size(dup, array_size(src));
	return (dup);
}
