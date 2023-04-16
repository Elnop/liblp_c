/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblp_print.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:53:24 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/12 16:19:04 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLP_PRINT_H
# define LIBLP_PRINT_H

# include "../liblp.h"

ssize_t	lp_putnbr_fd(int n, int fd);
ssize_t	lp_putendl_fd(char *s, int fd);
ssize_t	lp_putchar_fd(char c, int fd);
ssize_t	lp_putstr_fd(char *s, int fd);
ssize_t	lp_putnbr_base(long long int nbr, char *base);
bool	lp_putnbr_fdpc(int n, int fd, size_t *pcount);
bool	lp_putchar_fdpc(char c, int fd, size_t *pcount);
bool	lp_putendl_fdpc(char *s, int fd, size_t *pcount);
bool	lp_putstr_fdpc(char *s, int fd, size_t *pcount);

#endif