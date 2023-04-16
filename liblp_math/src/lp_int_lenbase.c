/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_int_lenbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:18:09 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/14 10:14:55 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_math.h"

size_t	lp_int_lenbase(int n, char *base)
{
	size_t	i;
	size_t	baselen;

	i = 1;
	baselen = lp_strlen(base);
	while (lp_abs(n) > lp_abs(lp_power(baselen, i)))
		i++;
	return (i + (n < 0));
}
