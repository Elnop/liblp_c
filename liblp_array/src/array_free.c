/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 05:42:03 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/30 20:48:54 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

void	array_free(t_array	array)
{
	size_t	i;

	if (!array)
		return ;
	if (array_header(array)->destroy_elem)
	{
		i = 0;
		while (i < array_header(array)->size)
		{
			array_header(array)
			->destroy_elem(array + i * array_header(array)->elem_size);
			i++;
		}
	}
	free(array_header(array));
}
