/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_int_print.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 01:42:49 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/10 05:22:53 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

static bool	print_elems(t_array array, size_t *pcount)
{
	size_t	size;
	size_t	i;

	size = array_size(array);
	i = 0;
	while (i < size)
	{
		if (!lp_putnbr_fdpc(((int *)array)[i], 1, pcount))
			return (false);
		if (i < size - 1)
			if (!lp_putstr_fdpc(", ", 1, pcount))
				return (false);
		i++;
	}
	return (true);
}

static bool	print_infos(t_array array, size_t *pcount)
{
	char	*tmp;

	if (!lp_putchar_fdpc('(', 1, pcount))
		return (false);
	tmp = lp_itoa(array_size(array));
	if (!lp_putstr_fdpc(tmp, 1, pcount))
		return (false);
	free(tmp);
	if (!lp_putchar_fdpc('/', 1, pcount))
		return (false);
	tmp = lp_itoa(array_capacity(array));
	if (!lp_putstr_fdpc(tmp, 1, pcount))
		return (false);
	free(tmp);
	if (!lp_putchar_fdpc(')', 1, pcount))
		return (false);
	return (true);
}

ssize_t	array_int_print(t_array array)
{
	size_t	count;

	count = 0;
	if (!print_infos(array, &count))
		return (false);
	if (!lp_putchar_fdpc('[', 1, &count))
		return (false);
	if (!print_elems(array, &count))
		return (false);
	if (!lp_putchar_fdpc(']', 1, &count))
		return (false);
	return (count);
}
