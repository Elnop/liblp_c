/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_capacity.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 00:46:12 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 07:54:50 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

size_t	array_capacity(t_array	array)
{
	return (array_header(array)->capacity);
}
