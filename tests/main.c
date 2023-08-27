/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 15:35:18 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/27 16:08:02 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/liblp_tests.h"

int	main(void)
{
	if (!test_array_create())
		return (1);
	if (!test_array_grow())
		return (1);
	if (!test_array_pushback_tab())
		return (1);
	return (0);
}
