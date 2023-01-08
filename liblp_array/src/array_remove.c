/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 22:30:42 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 10:00:27 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

void	array_remove(t_array array, size_t index)
{
	size_t	size;
	size_t	elemsize;

	size = array_size(array);
	elemsize = array_elemsize(array);
	if (size - 1 < index)
		return ;
	lp_memmove(
		array + index * elemsize,
		array + (index + 1) * array_elemsize(array),
		array_elemsize(array) * (array_size(array) - index - 1));
	array_set_size(array, size - 1);
}
