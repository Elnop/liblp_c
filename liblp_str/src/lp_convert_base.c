/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 16:35:16 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/12 16:36:08 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_str.h"

char	*lp_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*str;
	long int	tmp;
	long int	i;

	i = 0;
	tmp = lp_atoi_base(nbr, base_from);
	str = (char *)malloc(35 * sizeof(char));
	if (!str)
		return (NULL);
	return (lp_itoa_base(tmp, base_to, str, &i));
}
