/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_size.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 19:39:36 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 07:55:34 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

size_t	array_size(t_array	array)
{
	return (array_header(array)->size);
}