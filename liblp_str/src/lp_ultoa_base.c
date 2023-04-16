/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_ultoa_base.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 03:06:14 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/15 07:15:41 by lperroti         ###   ########.fr       */
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

char	*lp_ultoa_base(unsigned long nbr, char *base)
{
	unsigned int	baselen;
	static size_t	num_len;
	char			*buffer;
	size_t			i;

	if (!checkbase(base))
		return (0);
	if (!num_len)
		num_len = lp_ulong_lenbase(nbr, base);
	baselen = lp_strlen(base);
	i = 0;
	buffer = NULL;
	if (nbr / baselen > 0)
	{
		buffer = lp_ultoa_base(nbr / baselen, base);
		i = lp_strlen(buffer);
	}
	else
		buffer = malloc((num_len + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	buffer[i] = base[nbr % baselen];
	buffer[i + 1] = 0;
	return (lp_bzero(&num_len, sizeof(size_t)), buffer);
}
