/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtab_to_intarray.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:53:39 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/07 05:03:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

bool	check_overflow(char	*nbstr)
{
	unsigned int	i;
	long long		nbr;
	long long		max;

	i = 0;
	if (nbstr[0] == '-')
		i++;
	nbr = 0;
	max = 0;
	if (lp_strlen(nbstr) < 10)
		return (false);
	while (nbstr[i])
	{
		nbr = nbr * 10 + nbstr[i] - '0';
		max = max * 10 + "2147483647"[i] - '0';
		if (nbr > max)
			return (false);
		i++;
	}
	if (nbstr[0] == '-' && nbr > max + 1)
		return (false);
	return (true);
}

bool	check_tab(char **char_array, size_t size)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		if (char_array[i][j] == '-' || char_array[i][j] == '+')
			j++;
		if (!char_array[i][j])
			return (false);
		while (char_array[i][j])
		{
			if (!lp_isdigit(char_array[i][j]))
				return (false);
			j++;
		}
		if (check_overflow(char_array[i]))
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
