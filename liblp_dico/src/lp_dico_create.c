/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_dico_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:27:16 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 15:04:33 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_dico.h"

t_dico	*lp_dico_create(void)
{
	t_dico	*new_dico;

	new_dico = malloc(sizeof(t_dico) + 255 * MAX_KEY_LENGTH);

	*new_dico = (t_dico){
		.firstelem = NULL,
		.hashmap = (t_dico *)new_dico + 1,
	};
	return (new_dico);
}
