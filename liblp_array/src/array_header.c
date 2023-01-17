/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_header.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 03:28:36 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/15 09:37:37 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array_header	*array_header(t_array	array)
{
	if (!array)
		return (NULL);
	return ((t_array_header *)array - 1);
}
