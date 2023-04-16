/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 00:20:59 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/16 02:30:24 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_printf.h"

void	set_precision(const char *str, t_printf_flags *flags)
{
	flags->precision = -1;
	while (*str && !lp_strchr(TYPE_FLAGS, (int)*str) && *str != '.')
		str++;
	if (*str == '.')
	{
		str++;
		if (lp_isdigit(*str))
			flags->precision = lp_atoi(str);
		else
			flags->precision = -2;
	}
}

void	set_field_width(const char *str, t_printf_flags *flags)
{
	flags->field_width = 0;
	while (*str && !lp_strchr(TYPE_FLAGS, (int)*str)
		&& (!lp_isdigit(*str) || *str == '0') && *str != '.')
		str++;
	if (lp_isdigit(*str))
		flags->field_width = lp_atoi(str);
}

t_printf_flags	parse_flags(const char **pstr)
{
	t_printf_flags	flags;

	flags = (t_printf_flags){};
	set_field_width(*pstr, &flags);
	set_precision(*pstr, &flags);
	while (**pstr && !lp_strchr(TYPE_FLAGS, (int)**pstr) && **pstr != '.')
	{
		if (lp_isdigit(**pstr) && **pstr != '0')
			break ;
		if (**pstr == '0')
			flags.zero = true;
		else if (**pstr == '-')
			flags.minus = true;
		else if (**pstr == '+')
			flags.plus = true;
		else if (**pstr == '#')
			flags.hashtag = true;
		else if (**pstr == ' ')
			flags.space = true;
		else
			flags.invalid = true;
		(*pstr)++;
	}
	return (flags);
}
