/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array_remove.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:07:15 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/31 22:24:16 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_array.h"
#include <stddef.h>

typedef bool	(*t_array_copy_elem)(void	*pelem, void *dest);
typedef void	(*t_array_destroy_elem)(void *pelem);

void	func_destroy(void *pelem)
{
	free(*(char **)pelem);
}

bool	func_copy(void *pelem, void *dest)
{
	*(char **)dest = lp_strdup(*(char **)pelem);
	if (!dest)
		return (false);
	return (true);
}

void	free_tab(void	*tab)
{
	char	**tabtab;
	size_t	i;

	tabtab = (char **)tab;
	i = 0;
	while (tabtab[i])
	{
		free(tabtab[i]);
		i++;
	}
	free(tabtab);
}

static bool	create(t_array	*array, const char **elems_to_push)
{
	*array = array_new(10, sizeof(char *),
			func_copy, func_destroy);
	if (!*array)
		return (false);
	array_pushback_tab(array, (void *)elems_to_push, 5);
	return (true);
}

bool	test_array_remove(void)
{
	const char	**elems_to_push 
		= (const char **)lp_split("P P12 P123 P1234 P12345", ' ');
	t_array		array;

	create(&array, elems_to_push);
	array_remove(array, 1);
	if (array_size(array) == 4)
		lp_printf(GREEN"after remove elem, size OK" RESET"\n");
	else
		return ((void)lp_printf(RED"after remove, size KO"RESET"\n"), false);
	if (!lp_strncmp((const char *)(((char **)array)[1]), elems_to_push[2],
		lp_strlen(elems_to_push[2])))
		lp_printf(GREEN"after remove, elem removed OK" RESET"\n");
	else
		return ((void)lp_printf(RED"after remove, elem removed KO"RESET"\n"),
			false);
	array_free(array);
	free_tab(elems_to_push);
	return (true);
}
