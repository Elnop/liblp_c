/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_dico_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:40:42 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/27 14:46:27 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_dico.h"

void	*lp_dico_get(t_dico dico, void *key, size_t key_size)
{
	t_dico_elem	*elem;

	elem = dico.firstelem;
	while (elem)
	{
		if (!lp_memcmp(elem->key, key, key_size))
			return (elem->value);
		elem = elem->next;
	}
	return (NULL);
}
