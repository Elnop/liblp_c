/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_free_strtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 23:34:37 by lperroti          #+#    #+#             */
/*   Updated: 2023/09/24 23:35:43 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_str.h"

void	lp_free_strtab(char **strtab, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(strtab[i++]);
	}
	free(strtab);
}
