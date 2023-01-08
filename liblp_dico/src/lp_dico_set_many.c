/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_dico_set_many.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 04:48:45 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 06:30:38 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_dico.h"

void	lp_dico_set_many(t_dico *pdico, t_dico_insert *datalist, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		lp_dico_set(pdico, datalist[i]);
		i++;
	}
}
