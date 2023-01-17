/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 09:27:50 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/10 05:31:25 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_mem.h"

void	*lp_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size && __SIZE_MAX__ / size < nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	lp_bzero(ptr, nmemb * size);
	return (ptr);
}
