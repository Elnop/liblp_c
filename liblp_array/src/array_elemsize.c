/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_elemsize.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:24:18 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 07:55:01 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

size_t	array_elemsize(t_array	array)
{
	return (array_header(array)->elem_size);
}
