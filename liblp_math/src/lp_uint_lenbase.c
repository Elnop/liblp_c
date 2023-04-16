/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_uint_lenbase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 02:06:31 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/15 08:31:30 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_math.h"

size_t	lp_uint_lenbase(unsigned int n, char *base)
{
	size_t	i;
	size_t	baselen;

	i = 1;
	baselen = lp_strlen(base);
	while (n >= baselen)
	{
		n /= baselen;
		i++;
	}
	return (i);
}
