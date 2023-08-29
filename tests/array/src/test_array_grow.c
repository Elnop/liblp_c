/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array_grow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:33:02 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/28 21:50:51 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_array.h"

bool	test_array_grow()
{
	const size_t	test_capacity = 111;
	const size_t	test_grow = 111;
	const size_t	test_elemsize = sizeof(char);
	t_array			array;

	array = array_new(test_capacity, test_elemsize, NULL, NULL);
	if (array)
		lp_printf(GREEN"array_new OK"RESET"\n");
	else
	{
		lp_printf(RED"array_new KO"RESET"\n");
		return (false);
	}
	if (array_grow(&array, test_grow))
		lp_printf(GREEN"return array_grow OK"RESET"\n");
	else
	{
		lp_printf(RED"return array_grow KO"RESET"\n");
		return (false);
	}
	if (array)
		lp_printf(GREEN"array after grow OK"RESET"\n");
	else
	{
		lp_printf(RED"array after grow KO"RESET"\n");
		return (false);
	}
	if (array_capacity(array) == test_capacity + test_grow)
		lp_printf(GREEN"array capacity after grow OK"RESET"\n");
	else
	{
		lp_printf(RED"array capacity after grow KO"RESET"\n");
		return (false);
	}
	array_free(array);
	return (true);
}
