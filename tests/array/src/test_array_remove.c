/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array_remove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:07:15 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/29 18:17:04 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_array.h"

typedef void *(*t_array_copy_elem)(void *);
typedef void (*t_array_destroy_elem)(void *);

bool	test_array_remove(void)
{
	const size_t				array_capacity = 10;
	const size_t				array_elemsize = sizeof(char);
	const char					*elems_to_push[] = {"abcd","1234","4321","2341"};
	const t_array_copy_elem		pfunc_copy = (t_array_copy_elem)lp_strdup;
	const t_array_destroy_elem	pfunc_destroy = (t_array_destroy_elem)free;
	t_array						array;

	array = array_new(array_capacity, array_elemsize,
		pfunc_copy, pfunc_destroy);
	array_pushback_tab(&array, (void *)elems_to_push, 4 + 1);
	array_remove(array, 2);
	if (array_size(array) == 3)
		lp_printf(GREEN"after remove elem, size OK" RESET"\n");
	else
		return ((void)lp_printf(RED"after remove elem, size KO"RESET"\n"), false);
	if (((char *)array)[2] == ((char *)array)[3])
		lp_printf(GREEN"after remove elem, elem removed OK" RESET"\n");
	else
		return ((void)lp_printf(RED"after remove elem, elem removed KO"RESET"\n"), false);
	array_free(array);
	return (true);
}