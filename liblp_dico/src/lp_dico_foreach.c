/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_dico_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 04:24:41 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 04:28:02 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_dico.h"

void	lp_dico_foreach(t_dico dico, void (*f)(t_string key, void *value))
{
	t_dico_elem	*elem;

	elem = dico.firstelem;
	while (elem)
	{
		f(elem->key, elem->value);
		elem = elem->next;
	}
}
