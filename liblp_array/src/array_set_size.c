/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_set_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 05:34:21 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 10:03:46 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

void	array_set_size(t_array array, size_t size)
{
	t_array_header	*pheader;

	pheader = array_header(array);
	pheader->size = size;
}
