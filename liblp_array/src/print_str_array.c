/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_str_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:13:54 by lperroti          #+#    #+#             */
/*   Updated: 2023/11/29 18:14:05 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

void	print_str_array(t_array arr)
{
	size_t	i;

	i = 0;
	while (i < array_size(arr))
		lp_putendl_fd(((char **)arr)[i++], 2);
}
