/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_dico_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:19:21 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 12:18:07 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_dico.h"

void	*lp_dico_set(t_dico *pdico, t_dico_insert insert_data)
{
	t_dico_elem	*newelem;

	if (!insert_data.key)
		return (NULL);
	newelem = malloc(sizeof(t_dico_elem));
	if (!newelem)
		return (NULL);
	if (insert_data.copyfunc)
		newelem->value = insert_data.copyfunc(insert_data.value);
	else
	{
		newelem->value = malloc(insert_data.size);
		lp_memcpy(newelem->value, insert_data.value, insert_data.size);
	}
	newelem->destructor = insert_data.destructor;
	if (!insert_data.destructor)
		newelem->destructor = &free;
	if (insert_data.destruct_original)
		newelem->destructor(insert_data.value);
	newelem->key = lp_strdup(insert_data.key);
	if (!newelem->value || !newelem->key)
		return (NULL);
	newelem->next = pdico->firstelem;
	pdico->firstelem = newelem;
	return (newelem->value);
}
