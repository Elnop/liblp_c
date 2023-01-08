/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_putnbr_fdpc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 03:30:52 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/07 03:53:53 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_print.h"

bool	lp_putnbr_fdpc(int n, int fd, size_t *pcount)
{
	if (n == -2147483648)
	{
		if (!lp_putstr_fdpc("-2147483648", fd, pcount))
			return (false);
		return (true);
	}
	if (n < 0)
	{
		n *= -1;
		if (!lp_putchar_fdpc('-', fd, pcount))
			return (false);
	}
	if (n > 9)
		if (!lp_putnbr_fdpc(n / 10, fd, pcount))
			return (false);
	if (!lp_putchar_fdpc(n % 10 + '0', fd, pcount))
		return (false);
	return (true);
}
