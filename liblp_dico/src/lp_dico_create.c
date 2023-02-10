/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_dico_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:27:16 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/27 15:48:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_dico.h"

t_dico	*lp_dico_create(void)
{
	t_dico	*new_dico;

	new_dico = malloc(sizeof(t_dico));
	new_dico->firstelem = NULL;
	return (new_dico);
}
