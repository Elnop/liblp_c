/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array_remove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:07:15 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/30 04:51:58 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_array.h"
#include <stddef.h>
typedef void *(*t_array_copy_elem)(void	*);
typedef void (*t_array_destroy_elem)(void	*);

void	func_destroy(void *pelem)
{
	free(*(char **)pelem);
}

void	*func_copy(void *pelem)
{
	char	**dup_addr;

	dup_addr = malloc(sizeof(void *));
	*dup_addr = lp_strdup(*(char **)pelem);
	return (dup_addr);
}

bool	test_array_remove(void)
{
	const size_t			array_capacity = 1;
	const size_t			array_elemsize = sizeof(char *);
	char					**elems_to_push;
	t_array					array;

	elems_to_push = lp_split("Pfjk P123 P321 Pefg", ' ');
	array = array_new(array_capacity, array_elemsize,
			func_copy, func_destroy);
	if (!array)
		return (false);
	array_pushback_tab(&array, (void *)elems_to_push, 4);
	array_remove(array, 1);
	if (array_size(array) == 3)
		lp_printf(GREEN"after remove elem, size OK" RESET"\n");
	else
		return ((void)lp_printf(RED"after remove elem, size KO"RESET"\n"), false);
	if (!lp_strncmp((const char *)(((char **)array)[1]), elems_to_push[2], lp_strlen(elems_to_push[2])))
		lp_printf(GREEN"after remove elem, elem removed OK" RESET"\n");
	else
		return ((void)lp_printf(RED"after remove elem, elem removed KO"RESET"\n"), false);
	array_free(array);
	return (true);
}
