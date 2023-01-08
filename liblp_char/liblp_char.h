/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblp_char.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 20:34:43 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/07 05:03:39 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLP_CHAR_H
# define LIBLP_CHAR_H
# include <stddef.h>

int	lp_isalpha(int c);
int	lp_isdigit(int c);
int	lp_isalnum(int c);
int	lp_isascii(int c);
int	lp_isprint(int c);
int	lp_toupper(int c);
int	lp_tolower(int c);

#endif