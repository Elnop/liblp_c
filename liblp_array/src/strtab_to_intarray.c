/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtab_to_intarray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:53:39 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/14 11:06:05 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

bool	check_overflow(char	*nbstr)
{
	if (*nbstr == '-' || *nbstr == '+')
	{
		if (*nbstr == '-')
		{
			nbstr++;
			if (lp_strlen(nbstr) < 10)
				return (true);
			if (lp_strncmp("2147483648", nbstr, 10) < 0)
				return (false);
			return (true);
		}
		nbstr++;
	}
	if (lp_strlen(nbstr) < 10)
		return (true);
	if (lp_strncmp("2147483647", nbstr, 10) < 0)
		return (false);
	return (true);
}

bool	check_tab(char **char_array, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		if (char_array[i][j] == '-' || char_array[i][j] == '+')
			j++;
		while (char_array[i][j])
		{
			if (!lp_isdigit(char_array[i][j]))
				return (false);
			j++;
		}
		if (!check_overflow(char_array[i]))
			return (false);
		i++;
	}
	return (true);
}

t_array	strtab_to_intarray(char **char_tab, size_t size)
{
	int				*num_array;
	unsigned int	i;

	if (!check_tab(char_tab, size))
		return (NULL);
	num_array = array_new(size, sizeof(int));
	if (!num_array)
		return (NULL);
	array_set_size((void *)num_array, size);
	i = 0;
	while (i < size)
	{
		num_array[i] = lp_atoi(char_tab[i]);
		i++;
	}
	return ((t_array)num_array);
}
