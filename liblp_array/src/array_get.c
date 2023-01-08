/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_get.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:58:47 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/06 00:03:45 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

void	*array_get(t_array array, size_t index)
{
	return (array + index * array_elemsize(array));
}
