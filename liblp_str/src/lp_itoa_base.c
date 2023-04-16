/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:32:05 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/15 03:33:04 by lperroti         ###   ########.fr       */
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

char	*lp_itoa_base(int nbr, char *base)
{
	static size_t	i;
	static char		*buffer;
	unsigned int	baselen;

	if (!checkbase(base))
		return (0);
	if (!buffer)
		buffer = malloc((lp_int_lenbase(nbr, base) + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	if (nbr < 0)
	{
		nbr *= -1;
		buffer[i] = '-';
		i++;
	}
	baselen = lp_strlen(base);
	if (nbr / baselen > 0)
		lp_itoa_base(nbr / baselen, base);
	buffer[i] = base[nbr % baselen];
	i++;
	buffer[i] = 0;
	return (buffer);
}
