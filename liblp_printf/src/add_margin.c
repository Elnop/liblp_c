/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_margin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 09:45:58 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/15 14:48:53 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_printf.h"

char	*gen_margin(t_array buff, ssize_t field_width, char spacer)
{
	char	*margin;
	size_t	margin_length;

	if (!field_width || array_size(buff) >= (size_t)field_width)
		return (NULL);
	margin_length = field_width - array_size(buff);
	margin = malloc((margin_length + 1) * sizeof(char));
	if (!margin)
		return (NULL);
	margin[margin_length] = 0;
	while (margin_length-- > 0)
		margin[margin_length] = spacer;
	return (margin);
}

bool	add_margin(t_array *pbuff, char chr, ssize_t field_width,
		bool is_revers)
{
	char	*margin;

	if (field_width <= 0)
		return (true);
	margin = gen_margin(*pbuff, field_width, chr);
	if (is_revers)
		array_pushback_tab(pbuff, margin, lp_strlen(margin));
	else
		array_pushfront_tab(pbuff, margin, lp_strlen(margin));
	free(margin);
	return (true);
}
