/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_strtab_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 19:31:43 by lperroti          #+#    #+#             */
/*   Updated: 2023/10/03 19:32:53 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_str.h"

size_t	lp_strtab_size(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}
