/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_dico_has.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:26:45 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/27 14:46:23 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_dico.h"

bool	lp_dico_has(t_dico dico, void *key, size_t key_size)
{
	t_dico_elem	*elem;

	elem = dico.firstelem;
	while (elem)
	{
		if (!lp_memcmp(elem->key, key, key_size))
			return (true);
		elem = elem->next;
	}
	return (false);
}
