/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblp_array.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 18:22:16 by lperroti          #+#    #+#             */
/*   Updated: 2023/11/30 00:08:12 by lperroti         ###   ########.fr       */
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
	bool	((*copy_elem)(void *pelem, void *dest));
	void	(*destroy_elem)(void *pelem);
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
					bool (*copy_elem)(void *pelem, void *dest),
					void (*destroy_elem)(void *pelem));
t_array			array_dup(t_array array);
t_array			str_to_array(char *str);
t_array			strtab_to_intarray(char **str_tab, size_t size);
// ========================================================================== //
// --------------------------- HANDLERS ------------------------------------- //
// ========================================================================== //
bool			array_str_copy(void *pelem, void *dest);
void			array_str_destroy(void *pelem);
// ========================================================================== //
// ------------------------- EDIT ARRAY ------------------------------------- //
// ========================================================================== //
t_array			array_grow(t_array *array, size_t grow);
t_array			array_sort(t_array array, bool (*f)(void *a, void *b));
void			array_rotate(t_array array);
void			array_rrotate(t_array array);
void			array_swap(t_array array, size_t index1, size_t index2);
void			array_reverse(t_array array);
// ========================================================================== //
// ------------------------- INSERT ELEMENTS -------------------------------- //
// ========================================================================== //
t_array			array_pushfront(t_array	*parray, void *elem);
t_array			array_pushback(t_array *array, void *elem);
t_array			array_pushback_tab(t_array *parray, void *elems,
					size_t elems_count);
t_array			array_pushfront_tab(t_array *parray, void *elems,
					size_t elems_count);
// ========================================================================== //
// ------------------------- REMOVE ELEMENTS -------------------------------- //
// ========================================================================== //
void			array_remove(t_array array, size_t index);
void			array_set_size(t_array array, size_t size);
// ========================================================================== //
// ------------------------- GET ELEMENTS ----------------------------------- //
// ========================================================================== //
void			*array_get(t_array array, size_t index);
void			array_foreach(t_array array, void (f)(void *pelem));
// ========================================================================== //
// -------------------------- TRANSFORM ------------------------------------- //
// ========================================================================== //
char			**array_to_strtab(t_array arr);
// ========================================================================== //
// ------------------------- PRINT ELEMENTS --------------------------------- //
// ========================================================================== //
ssize_t			array_int_print(t_array array);
void			print_str_array(t_array arr);
// ========================================================================== //
// ------------------------- FREE MEMORY !!! -------------------------------- //
// ========================================================================== //
void			array_free(t_array	array);

// ========================================================================== //
// ------------------------- SOON ------------------------------------------- //
// ========================================================================== //

// array_foreach(t_array, void (*handler)(void *pelem))

#endif