/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:39:56 by lperroti          #+#    #+#             */
/*   Updated: 2023/02/10 03:36:19 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	miniatoi(char **nptr)
{
	int	num;

	num = 0;
	while (**nptr >= '0' && **nptr <= '9')
	{
		num *= 10;
		num += **nptr - '0';
		(*nptr)++;
	}
	return (num);
}

double	lp_atof(char *nptr)
{
	long	integers;
	long	decimals;
	int		sign;

	integers = 0;
	decimals = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	sign = 1;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	integers = miniatoi(&nptr);
	if (*nptr == '.' || *nptr == ',')
		nptr++;
	decimals = miniatoi(&nptr);
	return (((double)integers + ((double)decimals * 0.1)) * sign);
}
