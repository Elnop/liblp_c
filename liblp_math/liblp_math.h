/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblp_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:04:24 by lperroti          #+#    #+#             */
/*   Updated: 2023/06/16 09:53:25 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLP_MATH_H
# define LIBLP_MATH_H
# include "../liblp.h"

size_t			lp_abs(int number);
float			lp_power(int nbr, int power);
size_t			lp_int_len(int nbr);
size_t			lp_uint_len(unsigned int nbr);
size_t			lp_int_lenbase(int n, char *base);
size_t			lp_uint_lenbase(unsigned int n, char *base);
size_t			lp_ulong_lenbase(unsigned long n, char *base);
float			lp_fabs(float number);
long long		lp_get_timestamp(void);
void			lp_wait(long long ms);

#endif