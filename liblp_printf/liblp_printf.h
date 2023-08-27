/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblp_printf.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:48:21 by lperroti          #+#    #+#             */
/*   Updated: 2023/05/13 04:27:33 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLP_PRINTF_H
# define LIBLP_PRINTF_H

# include "../liblp.h"

typedef void	*t_array;

# define TYPE_FLAGS "%cidusxXp"
# define BASE10 "0123456789"
# define BASE16_MAJ "0123456789ABCDEF"
# define BASE16_MIN "0123456789abcdef"

typedef struct s_printf_flags {
	bool	zero;
	bool	minus;
	bool	plus;
	bool	hashtag;
	bool	space;
	bool	invalid;
	long	field_width;
	long	precision;
}	t_printf_flags;

int				lp_printf(const char *str, ...);
bool			add_margin(t_array *pbuff, char chr,
					ssize_t field_width, bool is_revers);
t_printf_flags	parse_flags(const char **pstr);
bool			specifier_str(char *str, t_array *pbuff, t_printf_flags flags);
bool			specifier_chr(char c, t_array *pbuff, t_printf_flags flags);
bool			specifier_int(int n, t_array *pbuff, t_printf_flags flags);
bool			specifier_ulong_base(unsigned long number, t_array *pbuff,
					char *base, t_printf_flags flags);
bool			specifier_uint_base(unsigned int number, t_array *pbuff,
					char *base, t_printf_flags flags);

#endif