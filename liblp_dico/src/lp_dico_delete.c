/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_dico_delete.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 11:39:09 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 12:25:05 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_dico.h"

void	lp_dico_delete(t_dico dico)
{
	t_dico_elem	*elem;
	t_dico_elem	*previous;

	elem = dico.firstelem;
	while (elem)
	{
		previous = elem;
		elem = elem->next;
		free(previous->key);
		previous->destructor(previous->value);
		free(previous);
	}
}
