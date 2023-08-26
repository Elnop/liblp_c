/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:37:07 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/26 03:51:29 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	str_to_array(const char str[])
{
	t_array	array;

	array = array_new(
				lp_strlen(str) + 1,
				sizeof(char),
				NULL,
				NULL);
	if (!array)
		return (NULL);
	return (array_pushback_tab(
			&array,
			(void *)str,
			lp_strlen(str) + 1)
	);
}
