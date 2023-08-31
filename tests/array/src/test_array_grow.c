/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array_grow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:33:02 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/31 22:16:04 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_array.h"

static bool	fck_the_norm(t_array array)
{
	if (array)
		lp_printf(GREEN"array after grow OK"RESET"\n");
	else
		return (lp_printf(RED"array after grow KO"RESET"\n"), false);
	if (array_capacity(array) == 222)
		lp_printf(GREEN"array capacity after grow OK"RESET"\n");
	else
		return (lp_printf(RED"array capacity after grow KO"RESET"\n"), false);
	return (true);
}

bool	test_array_grow(void)
{
	t_array			array;

	array = array_new(111, sizeof(char), NULL, NULL);
	if (array_grow(&array, 111))
		lp_printf(GREEN"return array_grow OK"RESET"\n");
	else
		return (lp_printf(RED"return array_grow KO"RESET"\n"), false);
	if (!fck_the_norm(array))
		return (false);
	array_free(array);
	return (true);
}
