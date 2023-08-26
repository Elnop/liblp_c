/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array_grow.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 04:15:56 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/26 04:19:31 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../liblp.h"

bool	test_array_grow()
{
	const size_t	test_capacity = 111;
	const size_t	test_grow = 111;
	const size_t	test_elemsize = sizeof(char);
	t_array			array;

	array = array_new(test_capacity, test_elemsize, NULL, NULL);
	if (array)
		printf(GREEN"array_new OK"RESET"\n");
	else
	{
		printf(RED"array_new KO"RESET"\n");
		return (false);
	}
	if (array_grow(&array, test_grow))
		printf(GREEN"return array_grow OK"RESET"\n");
	else
	{
		printf(RED"return array_grow KO"RESET"\n");
		return (false);
	}
	if (array)
		printf(GREEN"array after grow OK"RESET"\n");
	else
	{
		printf(RED"array after grow KO"RESET"\n");
		return (false);
	}
	if (array_capacity(array) == test_capacity + test_grow)
		printf(GREEN"array capacity after grow OK"RESET"\n");
	else
	{
		printf(RED"array capacity after grow KO"RESET"\n");
		return (false);
	}
	array_destroy(array);
	return (true);
}
