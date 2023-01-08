/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 04:10:14 by leon              #+#    #+#             */
/*   Updated: 2023/01/07 05:03:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_print.h"

ssize_t	lp_putendl_fd(char *s, int fd)
{
	ssize_t	count;
	ssize_t	lastwrite;

	lastwrite = lp_putstr_fd(s, fd);
	if (lastwrite == -1)
		return (-1);
	count = lastwrite;
	if (lp_putchar_fd('\n', fd) == -1)
		return (-1);
	count += 1;
	return (count);
}
