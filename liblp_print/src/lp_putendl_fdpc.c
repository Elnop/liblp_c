/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_putendl_fdpc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:41:10 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/07 05:03:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_print.h"

bool	lp_putendl_fdpc(char *s, int fd, size_t *pcount)
{
	if (!lp_putstr_fdpc(s, fd, pcount))
		return (false);
	if (!lp_putchar_fdpc('\n', fd, pcount))
		return (false);
	return (true);
}
