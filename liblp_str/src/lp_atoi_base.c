/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:30:14 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/12 16:33:15 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_str.h"

static int	checkbase(char *base)
{
	int		i;

	if (!base[0] || !base[1])
		return (0);
	while (*base)
	{
		if (
			*base == '+' || *base == '-'
			|| (*base >= '\t' && *base <= '\r') || *base == ' '
		)
			return (0);
		i = 1;
		while (base[i])
		{
			if (*base == base[i])
				return (0);
			i++;
		}
		base++;
	}
	return (1);
}

static int	find_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	lp_atoi_base(char *str, char *base)
{
	int	nbr;
	int	sign_coef;

	if (!checkbase(base))
		return (0);
	sign_coef = 1;
	nbr = 0;
	while ((*str && *str >= '\t' && *str <= '\r') || *str == ' ')
		str++;
	while (*str && (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign_coef *= -1;
		str++;
	}
	while (*str && find_in_base(*str, base) > -1)
	{
		nbr = nbr * lp_strlen(base) + find_in_base(*str, base);
		str++;
	}
	return (nbr * sign_coef);
}
