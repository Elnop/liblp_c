/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_reverse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 02:02:34 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/06 03:47:11 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

void	array_reverse(t_array array)
{
	size_t	size;
	size_t	elemsize;
	size_t	i;

	size = array_size(array);
	elemsize = array_elemsize(array);
	i = 0;
	while (i < size / 2)
	{
		lp_memswap(
			array + i * elemsize,
			array + (size - i) * elemsize - elemsize,
			elemsize);
		i++;
	}
}
