/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_handlers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:20:41 by lperroti          #+#    #+#             */
/*   Updated: 2023/11/27 19:20:47 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

bool	array_str_copy(void *pelem, void *dest)
{
	if (!pelem || !*(char **)pelem)
		*(char **)dest = NULL;
	else
		*(char **)dest = lp_strdup(*(char **)pelem);
	return (true);
}

void	array_str_destroy(void *pelem)
{
	free(*(char **)pelem);
}
