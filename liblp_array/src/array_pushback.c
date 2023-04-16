/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_pushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 23:47:57 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/14 13:32:14 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	array_pushback(t_array *parray, void *elem)
{
	if (array_capacity(*parray) < array_size(*parray) + 1)
		array_grow(parray, 1);
	lp_memcpy((char *)*parray + array_size(*parray), elem,
		array_elemsize(*parray));
	array_set_size(*parray, array_size(*parray) + 1);
	return (*parray);
}
