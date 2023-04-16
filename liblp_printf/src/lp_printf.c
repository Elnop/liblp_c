/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 23:46:19 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/15 14:45:05 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_printf.h"

bool	specifier_ptr(void *ptr, t_array *pbuff, t_printf_flags flags)
{
	flags.hashtag = true;
	if (!ptr)
		return (specifier_str("(nil)", pbuff, flags));
	return (specifier_ulong_base((size_t)ptr, pbuff,
			BASE16_MIN, flags));
}

static int	arg_to_buff(const char **pstr, t_array *pbuff, va_list args)
{
	t_printf_flags	flags;

	flags = parse_flags(pstr);
	while (**pstr && !lp_strchr(TYPE_FLAGS, (int)**pstr))
		(*pstr)++;
	if (**pstr == '%')
		return (array_size(array_pushback((void *)pbuff, "%")));
	if (**pstr == 's')
		return (specifier_str(va_arg(args, char *), pbuff, flags));
	if (**pstr == 'c')
		return (specifier_chr((char)va_arg(args, int), pbuff, flags));
	if (**pstr == 'd' || **pstr == 'i')
		return (specifier_int(va_arg(args, int), pbuff, flags));
	if (**pstr == 'u')
		return (specifier_uint_base(va_arg(args, unsigned int), pbuff,
				BASE10, flags));
	if (**pstr == 'x')
		return (specifier_uint_base(va_arg(args, unsigned int), pbuff,
				BASE16_MIN, flags));
	if (**pstr == 'X')
		return (specifier_uint_base(va_arg(args, unsigned int), pbuff,
				BASE16_MAJ, flags));
	if (**pstr == 'p')
		return (specifier_ptr(va_arg(args, void *), pbuff, flags));
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	i;
	t_array	buffer;
	size_t	write_size;

	buffer = array_new(1, sizeof(char));
	va_start(args, str);
	while (*str)
	{
		i = 0;
		while (str[i] && str[i] != '%')
			i++;
		if (i)
		{
			if (!array_pushback_tab(&buffer, (void *)str, i))
				return (-1);
			str += i;
		}
		if (*str == '%')
		{
			str++;
			arg_to_buff(&str, &buffer, args);
			if (!buffer)
				return (-1);
			str++;
		}
	}
	write(1, buffer, array_size(buffer));
	va_end(args);
	write_size = array_size(buffer);
	return (array_free(buffer), write_size);
}
