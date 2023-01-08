/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 15:36:01 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/07 05:03:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long long	lp_atol(const char *nptr)
{
	long long	num;
	long long	sign;

	num = 0;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == ' ')
		nptr++;
	sign = 1;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
	{
		num *= 10;
		num += *nptr - '0';
		nptr++;
	}
	return (num * sign);
}
