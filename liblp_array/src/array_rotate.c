/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 22:44:52 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/10 05:23:23 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

void	array_rotate(t_array array)
{
	size_t	size;
	size_t	elemsize;
	void	*tmp;

	size = array_size(array);
	elemsize = array_elemsize(array);
	if (size < 2)
		return ;
	tmp = malloc(elemsize);
	lp_memcpy(tmp, array, elemsize);
	lp_memmove(array, array + 1 * elemsize, (size - 1) * elemsize);
	lp_memcpy(array + (size - 1) * elemsize, tmp, elemsize);
	free(tmp);
}

void	array_rrotate(t_array array)
{
	size_t	size;
	size_t	elemsize;
	void	*tmp;

	size = array_size(array);
	elemsize = array_elemsize(array);
	if (size < 2)
		return ;
	tmp = malloc(elemsize);
	lp_memcpy(tmp, array + (size - 1) * elemsize, elemsize);
	lp_memmove(array + 1 * elemsize, array, (size - 1) * elemsize);
	lp_memcpy(array, tmp, elemsize);
	free(tmp);
}
