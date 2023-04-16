/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:30:15 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/15 14:05:55 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_math.h"

float	lp_power(int nbr, int power)
{
	long int	result;

	result = 1;
	while (power--)
		result *= nbr;
	return (result);
}
