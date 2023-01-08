/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_putchar_fdpc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 02:35:30 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/07 03:10:13 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_print.h"

bool	lp_putchar_fdpc(char c, int fd, size_t *pcount)
{
	if (write(fd, &c, 1) == -1)
		return (false);
	*pcount += 1;
	return (true);
}
