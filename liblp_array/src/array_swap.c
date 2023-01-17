/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 06:00:49 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/10 05:23:10 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

void	array_swap(t_array array, size_t index1, size_t index2)
{
	size_t	size;
	size_t	elemsize;

	size = array_size(array);
	elemsize = array_elemsize(array);
	if (index1 > size || index2 > size || index1 == index2)
		return ;
	lp_memswap(array + index1 * elemsize, array + index2 * elemsize, elemsize);
}
