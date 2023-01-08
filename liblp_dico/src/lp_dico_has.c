/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_dico_has.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:26:45 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 03:28:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_dico.h"

bool	lp_dico_has(t_dico dico, t_string key)
{
	t_dico_elem	*elem;

	elem = dico.firstelem;
	while (elem)
	{
		if (lp_str_isequal(elem->key, key))
			return (true);
		elem = elem->next;
	}
	return (false);
}
