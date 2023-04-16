/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 01:02:47 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/14 08:57:22 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_mem.h"

void	*lp_realloc(void **ptrptr, size_t size, size_t new_size)
{
	void	*new_ptr;

	new_ptr = malloc(new_size);
	if (new_ptr)
		return (NULL);
	lp_memcpy(new_ptr, new_ptr, size);
	*ptrptr = new_ptr;
	return (new_ptr);
}
