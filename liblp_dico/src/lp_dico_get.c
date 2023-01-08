/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_dico_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:40:42 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 03:28:01 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_dico.h"

void	*lp_dico_get(t_dico dico, t_string key)
{
	t_dico_elem	*elem;

	elem = dico.firstelem;
	while (elem)
	{
		if (lp_str_isequal(elem->key, key))
			return (elem->value);
		elem = elem->next;
	}
	return (NULL);
}
