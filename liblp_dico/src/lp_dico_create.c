/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_dico_create.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:27:16 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 18:33:07 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_dico.h"

t_dico	lp_dico_create(void)
{
	t_dico	new_dico;

	new_dico.firstelem = NULL;
	return (new_dico);
}
