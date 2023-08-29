/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array_pushback_tab.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 16:28:46 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/29 17:05:20 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../test_array.h"

bool	test_array_pushback_tab(void)
{
	t_array		array;
	const char	str[] = "Test lala blabla";

	array = array_new(1, sizeof(char), NULL, NULL);
	if (array_pushback_tab(&array, (void *)str, lp_strlen(str) + 1))
		lp_printf(GREEN"array_pushback_tab return OK" RESET"\n");
	else
		return ((void)lp_printf(RED"array_pushback_tab return KO"RESET"\n"), false);
	if (!lp_strncmp((char *)array, str, lp_strlen(str) + 1))
		lp_printf(GREEN"cmp array & base tab OK" RESET"\n");
	else
		return ((void)lp_printf(RED"cmp array & base tab KO"RESET"\n"), false);
	array_free(array);
	return (true);
}
