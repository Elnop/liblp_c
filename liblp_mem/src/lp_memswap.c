/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 03:12:46 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 00:20:04 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_mem.h"

void	lp_memswap(void *dest, const void *src, size_t n)
{
	t_byte	tmp;

	if (!dest && !src && n)
		return ;
	while (n-- > 0)
	{
		tmp = ((char *)dest)[n];
		((char *)dest)[n] = ((char *)src)[n];
		((char *)src)[n] = tmp;
	}
	return ;
}
