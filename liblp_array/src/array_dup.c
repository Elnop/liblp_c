/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_dup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 02:39:25 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/10 05:22:12 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	array_dup(t_array array)
{
	t_array			dup;

	dup = array_new(array_capacity(array), array_elemsize(array));
	lp_memcpy(dup, array, array_size(array) * array_elemsize(array));
	array_set_size(dup, array_size(array));
	return (dup);
}
