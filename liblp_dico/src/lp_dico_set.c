/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_dico_set.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 03:19:21 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/27 15:32:28 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_dico.h"

static void	copy_value(t_dico_elem	*newelem, t_dico_insert insert_data)
{
	if (insert_data.copyfunc)
		newelem->value = insert_data.copyfunc(insert_data.value);
	else
	{
		newelem->value = malloc(insert_data.value_size);
		if (insert_data.value)
			lp_memcpy(newelem->value, insert_data.value,
				insert_data.value_size);
	}
}

void	*lp_dico_set(t_dico *pdico, t_dico_insert insert_data)
{
	t_dico_elem	*newelem;

	newelem = (t_dico_elem *)malloc(sizeof(t_dico_elem));
	if (!newelem)
		return (NULL);
	newelem->key = malloc(insert_data.key_size);
	if (!newelem->key)
		return (NULL);
	lp_memcpy(newelem->key, insert_data.key, insert_data.key_size);
	copy_value(newelem, insert_data);
	newelem->destructor = insert_data.destructor;
	if (!insert_data.destructor)
		newelem->destructor = &free;
	if (insert_data.destruct_original)
		newelem->destructor(insert_data.value);
	if (!newelem->value || !newelem->key)
		return (NULL);
	newelem->next = pdico->firstelem;
	pdico->firstelem = newelem;
	return (newelem->value);
}
