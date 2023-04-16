/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_ulong_lenbase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 03:00:33 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/15 06:12:44 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_math.h"

size_t	lp_ulong_lenbase(unsigned long n, char *base)
{
	size_t	i;
	size_t	baselen;

	i = 1;
	baselen = lp_strlen(base);
	while (n > baselen)
	{
		n /= baselen;
		i++;
	}
	return (i);
}
