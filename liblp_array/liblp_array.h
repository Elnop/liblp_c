/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblp_array.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:22:16 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/15 09:49:14 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLP_ARRAY_H
# define LIBLP_ARRAY_H
# include "../liblp.h"

typedef void	*t_array;

typedef struct s_array_header {
	size_t	capacity;
	size_t	size;
	size_t	elem_size;
	t_array	tab[0];
}	t_array_header;

t_array_header	*array_header(t_array	array);
size_t			array_capacity(t_array	array);
size_t			array_size(t_array	array);
void			array_set_size(t_array array, size_t size);
size_t			array_elemsize(t_array	array);
t_array			array_new(size_t size, size_t elem_size);
t_array			array_dup(t_array array);
void			array_pushfront(t_array array, void	*elem);
void			array_remove(t_array array, size_t index);
size_t			array_indexof(t_array array, void *value);
void			array_free(t_array	array);
void			*array_get(t_array array, size_t index);
void			array_reverse(t_array array);
ssize_t			array_int_print(t_array array);
void			array_rotate(t_array array);
void			array_rrotate(t_array array);
void			array_swap(t_array array, size_t index1, size_t index2);
bool			array_issort(t_array array, bool (*f)(void *a, void *b));
t_array			array_sort(t_array array, bool (*f)(void *a, void *b));
t_array			strtab_to_intarray(char **char_tab, size_t size);
bool			array_has(t_array array, void *value);
void			array_foreach(t_array array, void (f)(void *));

#endif