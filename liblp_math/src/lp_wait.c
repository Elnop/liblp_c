/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lp_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 09:40:38 by lperroti          #+#    #+#             */
/*   Updated: 2023/06/16 13:35:50 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../liblp_math.h"

void	lp_wait(long long ms)
{
	long long	start;
	long long	now;

	start = lp_get_timestamp();
	now = lp_get_timestamp();
	while (now - start < ms)
		now = lp_get_timestamp();
}
