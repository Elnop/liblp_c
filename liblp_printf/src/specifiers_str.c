/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifiers_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 01:12:25 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/16 01:17:55 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_printf.h"

bool	specifier_str(char *str, t_array *pbuff, t_printf_flags flags)
{
	t_array	field_buff;

	if (!str && flags.precision != -1 && flags.precision < 6)
		return (true);
	if (!str)
		str = "(null)";
	field_buff = str_to_array(str);
	array_set_size(field_buff, array_size(field_buff) - 1);
	if (flags.precision != -1 && flags.precision < (ssize_t)lp_strlen(str))
	{
		if (flags.precision < 0)
			flags.precision = 0;
		array_set_size(field_buff, flags.precision);
	}
	add_margin(&field_buff, ' ', flags.field_width, flags.minus);
	array_pushback_tab(pbuff, field_buff, array_size(field_buff));
	return (array_free(field_buff), true);
}

bool	specifier_chr(char c, t_array *pbuff, t_printf_flags flags)
{
	t_array	field_buff;
	size_t	field_len;

	field_buff = array_new(2, sizeof(char));
	if (!field_buff)
		return (false);
	array_pushback(&field_buff, (char []){c});
	add_margin(&field_buff, ' ', flags.field_width, flags.minus);
	field_len = 1;
	if (flags.field_width > 1)
		field_len = flags.field_width;
	array_pushback_tab(pbuff, field_buff, field_len);
	return (array_free(field_buff), true);
}
