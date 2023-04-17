/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:52:02 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/17 19:26:45 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_printf.h"

static void	put_sign(t_array *pbuff, int sign, bool base_is_upper,
	t_printf_flags flags)
{
	if (sign && flags.hashtag)
	{
		if (base_is_upper)
			array_pushback_tab(pbuff, "0X", 2);
		else
			array_pushback_tab(pbuff, "0x", 2);
	}
	else if (sign < 0)
		array_pushback(pbuff, "-");
	else if (flags.plus)
		array_pushback(pbuff, "+");
	else if (flags.space)
		array_pushback(pbuff, " ");
}

bool	specifier_ulong_base(unsigned long number, t_array *pbuff, char *base,
							t_printf_flags flags)
{
	t_array	f_buff;
	char	*nbr_str;

	nbr_str = lp_ultoa_base(number, base);
	f_buff = array_new(1, sizeof(char));
	put_sign(&f_buff,
		(number != 0) - 2 * (number < 0),
		lp_str_isequal(base, BASE16_MAJ),
		flags);
	while (flags.precision-- > (ssize_t)lp_ulong_lenbase(number, base))
		array_pushback(&f_buff, "0");
	if (flags.zero)
	{
		if (flags.field_width > (ssize_t)lp_ulong_lenbase(number, base))
			add_margin(&f_buff, '0',
				flags.field_width - lp_ulong_lenbase(number, base), true);
		array_pushback_tab(&f_buff, nbr_str, lp_ulong_lenbase(number, base));
		array_pushback_tab(pbuff, f_buff, array_size(f_buff));
		return (free(nbr_str), array_free(f_buff), false);
	}
	array_pushback_tab(&f_buff, nbr_str, lp_ulong_lenbase(number, base));
	add_margin(&f_buff, ' ', flags.field_width, flags.minus);
	array_pushback_tab(pbuff, f_buff, array_size(f_buff));
	return (free(nbr_str), array_free(f_buff), true);
}

bool	specifier_uint_base(unsigned int number, t_array *pbuff, char *base,
		t_printf_flags flags)
{
	t_array	f_buff;
	char	*nbr_str;
	long	precision;

	nbr_str = lp_strdup("");
	if (number || (!number && flags.precision != -2 && flags.precision))
		nbr_str = (free(nbr_str), lp_uitoa_base(number, base));
	f_buff = array_new(1, sizeof(char));
	put_sign(&f_buff, (number > 0), lp_str_isequal(base, BASE16_MAJ), flags);
	precision = flags.precision;
	while (precision-- > (ssize_t)lp_strlen(nbr_str))
		array_pushback(&f_buff, "0");
	if (flags.zero
		&& flags.field_width > (ssize_t)array_size(f_buff)
		&& (flags.precision < (ssize_t)array_size(f_buff))
		&& flags.precision != -2)
	{
		if (flags.field_width > (ssize_t)lp_strlen(nbr_str))
			add_margin(&f_buff, '0',
				flags.field_width - lp_strlen(nbr_str), true);
	}
	array_pushback_tab(&f_buff, nbr_str, lp_strlen(nbr_str));
	add_margin(&f_buff, ' ', flags.field_width, flags.minus);
	array_pushback_tab(pbuff, f_buff, array_size(f_buff));
	return (free(nbr_str), array_free(f_buff), true);
}

bool	specifier_int(int number, t_array *pbuff, t_printf_flags flags)
{
	t_array	field_buff;
	char	*nbr_str;
	long	precision;

	nbr_str = lp_strdup("");
	if (number || (!number && (flags.precision != -2 && flags.precision)))
		nbr_str = (free(nbr_str), lp_uitoa_base(lp_abs(number), BASE10));
	field_buff = array_new(1, sizeof(char));
	put_sign(&field_buff, (number > 0) - (number < 0), true, flags);
	precision = flags.precision;
	while (precision-- > (ssize_t)lp_strlen(nbr_str))
		array_pushback(&field_buff, "0");
	if (flags.zero
		&& flags.field_width > (ssize_t)array_size(field_buff)
		&& (flags.precision < (ssize_t)array_size(field_buff))
		&& flags.precision != -2)
	{
		if (flags.field_width > (ssize_t)lp_strlen(nbr_str))
			add_margin(&field_buff, '0',
				flags.field_width - lp_strlen(nbr_str), true);
	}
	array_pushback_tab(&field_buff, nbr_str, lp_strlen(nbr_str));
	add_margin(&field_buff, ' ', flags.field_width, flags.minus);
	array_pushback_tab(pbuff, field_buff, array_size(field_buff));
	return (free(nbr_str), array_free(field_buff), true);
}
