/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_to_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 10:37:07 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/15 14:45:05 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_array.h"

t_array	str_to_array(char *str)
{
	return (array_pushback_tab(
			(t_array []){array_new(1, sizeof(char))}, str, lp_strlen(str) + 1)
	);
}
