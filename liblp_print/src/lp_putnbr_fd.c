/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 06:34:19 by leon              #+#    #+#             */
/*   Updated: 2023/01/07 05:03:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_print.h"

ssize_t	lp_putnbr_fd(int n, int fd)
{
	ssize_t	count;
	ssize_t	lastwrite;

	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	if (n < 0)
	{
		n *= -1;
		write(fd, "-", 1);
	}
	count = 0;
	if (n > 9)
	{
		lastwrite = lp_putnbr_fd(n / 10, fd);
		if (lastwrite == -1)
			return (-1);
		count += lastwrite;
	}
	n = n % 10 + '0';
	lastwrite = write(fd, &n, 1);
	if (lastwrite == -1)
		return (-1);
	count += lastwrite;
	return (count);
}
