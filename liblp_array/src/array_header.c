/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:28:36 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 07:54:38 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array_header	*array_header(t_array	array)
{
	return ((t_array_header *)array - 1);
}
