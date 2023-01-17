/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_indexof.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 10:11:01 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/16 13:29:47 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

size_t	array_indexof(t_array array, void *value)
{
	size_t	i;

	i = 0;
	while (i < array_size(array))
	{
		if (!lp_memcmp(array + i * array_elemsize(array),
				value,
				array_elemsize(array))
		)
			return (i);
		i++;
	}
	return (0);
}
