/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_array.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/26 12:40:43 by lperroti          #+#    #+#             */
/*   Updated: 2023/08/29 17:42:55 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_ARRAY_H
# define TEST_ARRAY_H

# include "../includes/liblp_tests.h"
# include "../../liblp_array/liblp_array.h"

bool	test_array_grow(void);
bool	test_array_create(void);
bool	test_array_pushback_tab(void);
bool	test_array_remove(void);

#endif