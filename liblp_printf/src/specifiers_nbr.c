/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:52:02 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/16 15:08:45 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_printf.h"

bool	specifier_ulong_base(unsigned long number, t_array *pbuff, char *base,
							t_printf_flags flags)
{
	t_array	f_buff;
	char	*nbr_str;

	nbr_str = lp_ultoa_base(number, base);
	f_buff = array_new(1, sizeof(char));
	if (number && flags.hashtag && (lp_str_isequal(base, BASE16_MIN)
			|| lp_str_isequal(base, BASE16_MAJ)))
	{
		if (lp_str_isequal(base, BASE16_MIN))
			array_pushback_tab(&f_buff, "0x", 2);
		else
			array_pushback_tab(&f_buff, "0X", 2);
	}
	else if (number > 0 && flags.plus)
		f_buff = array_pushback(&f_buff, "+");
	else if (number < 0)
		f_buff = array_pushback(&f_buff, "-");
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
	if (number && flags.hashtag && (lp_str_isequal(base, BASE16_MIN)
			|| lp_str_isequal(base, BASE16_MAJ)))
	{
		if (lp_str_isequal(base, BASE16_MIN))
			array_pushback_tab(&f_buff, "0x", 2);
		else
			array_pushback_tab(&f_buff, "0X", 2);
	}
	if (number < 0)
		f_buff = array_pushback(&f_buff, "-");
	else if (flags.plus)
		f_buff = array_pushback(&f_buff, "+");
	else if (flags.space)
		array_pushback(&f_buff, " ");
	precision = flags.precision;
	while (precision-- > (ssize_t)lp_strlen(nbr_str))
		array_pushback(&f_buff, "0");
	if (flags.zero
		&& flags.field_width > (ssize_t)array_size(f_buff)
		&& (flags.precision == -1 || flags.precision < (ssize_t)array_size(f_buff))
		&& flags.precision != -2)
	{
		if (flags.field_width > (ssize_t)lp_strlen(nbr_str))
			add_margin(&f_buff, '0',
				flags.field_width - lp_strlen(nbr_str), true);
		array_pushback_tab(&f_buff, nbr_str, lp_strlen(nbr_str));
		array_pushback_tab(pbuff, f_buff, array_size(f_buff));
		return (free(nbr_str), array_free(f_buff), false);
	}
	array_pushback_tab(&f_buff, nbr_str, lp_strlen(nbr_str));
	add_margin(&f_buff, ' ', flags.field_width, flags.minus);
	array_pushback_tab(pbuff, f_buff, array_size(f_buff));
	return (free(nbr_str), array_free(f_buff), true);
}

bool	specifier_int(int number, t_array *pbuff, t_printf_flags flags)
{
	t_array	field_buff;
	size_t	margin_len;
	char	*nbr_str;
	long	precision;

	nbr_str = lp_strdup("");
	if (number || (!number && (flags.precision != -2 && flags.precision)))
		nbr_str = (free(nbr_str), lp_itoa(number));
	if (nbr_str[0] == '-')
		lp_strlcpy(nbr_str, nbr_str + 1, lp_strlen(nbr_str));
	field_buff = array_new(1, sizeof(char));
	if (number < 0)
		array_pushback(&field_buff, "-");
	else if (flags.plus)
		array_pushback(&field_buff, "+");
	else if (flags.space)
		array_pushback(&field_buff, " ");
	precision = flags.precision;
	while (precision-- > (ssize_t)lp_strlen(nbr_str))
		array_pushback(&field_buff, "0");
	if (flags.zero
		&& flags.field_width > (ssize_t)array_size(field_buff)
		&& (flags.precision == -1 || flags.precision < (ssize_t)array_size(field_buff))
		&& flags.precision != -2)
	{
		margin_len = 0;
		if (flags.field_width > (ssize_t)lp_strlen(nbr_str))
			margin_len = flags.field_width - lp_strlen(nbr_str);
		if (flags.precision > (ssize_t)lp_strlen(nbr_str))
			margin_len = flags.precision - lp_strlen(nbr_str);
		add_margin(&field_buff, '0', margin_len, true);
		array_pushback_tab(&field_buff, nbr_str, lp_strlen(nbr_str));
		array_pushback_tab(pbuff, field_buff, array_size(field_buff));
		return (array_free(field_buff), free(nbr_str), false);
	}
	array_pushback_tab(&field_buff, nbr_str, lp_strlen(nbr_str));
	add_margin(&field_buff, ' ', flags.field_width, flags.minus);
	array_pushback_tab(pbuff, field_buff, array_size(field_buff));
	return (free(nbr_str), array_free(field_buff), true);
}
