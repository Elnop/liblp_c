/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array_create.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:48:24 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/26 12:49:07 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/__test_array.h"

bool	test_array_create()
{
	const size_t	test_capacity = 111;
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
	if (array_capacity(array) == test_capacity)
		printf(GREEN"array_capacity OK"RESET"\n");
	else
	{
		printf(RED"array_capacity KO"RESET"\n");
		return (false);
	}
	if (array_elemsize(array) == test_elemsize)
		printf(GREEN"array_elemsize OK"RESET"\n");
	else
	{
		printf(RED"array_elemsize KO"RESET"\n");
		return (false);
	}
	array_destroy(array);
	return (true);
}