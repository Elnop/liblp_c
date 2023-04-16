/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblp_mem.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 08:13:27 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/14 10:59:14 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLP_MEM_H
# define LIBLP_MEM_H

# include "../liblp.h"

typedef char	t_byte;

void	*lp_memset(void *s, int c, size_t n);
void	*lp_memcpy(void *dest, const void *src, size_t n);
void	lp_bzero(void *s, size_t n);
void	*lp_memmove(void *dest, const void *src, size_t n);
void	*lp_memchr(const void *s, int c, size_t n);
int		lp_memcmp(const void *s1, const void *s2, size_t n);
void	*lp_calloc(size_t nmemb, size_t size);
void	lp_memswap(void *dest, const void *src, size_t n);
void	*lp_realloc(void **old_ptr, size_t old_size, size_t new_size);

#endif