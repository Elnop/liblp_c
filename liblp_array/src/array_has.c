/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_has.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:46:16 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/10 11:52:11 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

bool	array_has(t_array array, void *value)
{
	size_t	i;

	i = 0;
	while (i < array_size(array))
	{
		if (!lp_memcmp(
				array + i * array_elemsize(array),
				value,
				array_elemsize(array))
		)
			return (true);
		i++;
	}
	return (false);
}
