/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_putstr_fdpc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 03:44:08 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/07 05:03:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_print.h"

bool	lp_putstr_fdpc(char *s, int fd, size_t *pcount)
{
	ssize_t	count;

	count = write(fd, s, lp_strlen(s));
	if (count == -1)
		return (false);
	*pcount += count;
	return (true);
}
