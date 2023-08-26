/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblp_array.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:22:16 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/16 17:09:50 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLP_ARRAY_H
# define LIBLP_ARRAY_H

# include "../liblp.h"

typedef void	*t_array;

typedef struct s_array_header {
	void	(*elem_destructor)(void *);
	void	*(*elem_copy)(void *);
	size_t	capacity;
	size_t	size;
	size_t	elem_size;
	t_array	tab[0];
}	t_array_header;

// ========================================================================== //
// ------------------------- INFORMATIONS ----------------------------------- //
// ========================================================================== //
t_array_header	*array_header(t_array	array);
size_t			array_capacity(t_array	array);
size_t			array_size(t_array	array);
size_t			array_elemsize(t_array	array);
size_t			array_indexof(t_array array, void *value);
bool			array_has(t_array array, void *value);
bool			array_issort(t_array array, bool (*f)(void *a, void *b));
// ========================================================================== //
// ------------------------- CREATE ARRAY ----------------------------------- //
// ========================================================================== //
t_array			array_new(size_t capacity, size_t elem_size,
					void	*(*elem_copy)(void *),
					void	(*elem_destructor)(void *));
t_array			array_dup(t_array array);
t_array			str_to_array(const char str[]);
t_array			strtab_to_intarray(char **str_tab, size_t size);
// ========================================================================== //
// ------------------------- EDIT ARRAY ------------------------------------- //
// ========================================================================== //
t_array			array_grow(t_array *array, size_t grow);
void			array_set_size(t_array array, size_t size);
t_array			array_sort(t_array array, bool (*f)(void *a, void *b));
void			array_rotate(t_array array);
void			array_rrotate(t_array array);
void			array_swap(t_array array, size_t index1, size_t index2);
void			array_reverse(t_array array);
// ========================================================================== //
// ------------------------- INSERT ELEMENTS -------------------------------- //
// ========================================================================== //
t_array			array_pushfront(t_array	*parray, void	*elem);
t_array			array_pushback(t_array *array, void *elem);
t_array			array_pushback_tab(t_array *parray, void *elems,
					size_t elems_count);
t_array			array_pushfront_tab(t_array *parray, void *elems,
					size_t elems_count);
// ========================================================================== //
// ------------------------- REMOVE ELEMENTS -------------------------------- //
// ========================================================================== //
void			array_remove(t_array array, size_t index);
// ========================================================================== //
// ------------------------- GET ELEMENTS ----------------------------------- //
// ========================================================================== //
void			*array_get(t_array array, size_t index);
void			array_foreach(t_array array, void (f)(void *));
// ========================================================================== //
// ------------------------- PRINT ELEMENTS --------------------------------- //
// ========================================================================== //
ssize_t			array_int_print(t_array array);
// ========================================================================== //
// ------------------------- FREE MEMORY !!! -------------------------------- //
// ========================================================================== //
void			array_destroy(t_array	array);

#endif