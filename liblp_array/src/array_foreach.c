/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_foreach.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 09:42:17 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/15 09:48:11 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

void	array_foreach(t_array array, void (f)(void *))
{
	size_t	i;

	i = 0;
	while (i < array_size(array))
	{
		f(array + i * array_elemsize(array));
		i++;
	}
}
