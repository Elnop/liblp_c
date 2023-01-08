/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblp_dico.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 01:11:11 by lperroti          #+#    #+#             */
/*   Updated: 2023/01/08 17:48:41 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLP_DICO_H
# define LIBLP_DICO_H
# include "../liblp.h"

typedef char	*t_string;

typedef struct s_dico_elem {
	t_string			key;
	size_t				size;
	void				*value;
	void				(*destructor)(void *);
	struct s_dico_elem	*next;
}	t_dico_elem;

typedef struct s_dico {
	t_dico_elem	*firstelem;
}	t_dico;

typedef struct s_dico_insert {
	t_string	key;
	void		*value;
	size_t		size;
	void		(*destructor)(void *);
	void		*(*copyfunc)(void *);
	bool		destruct_original;
}	t_dico_insert;

t_dico	lp_dico_create(void);
void	*lp_dico_get(t_dico dico, t_string key);
bool	lp_dico_has(t_dico dico, t_string key);
void	*lp_dico_set(t_dico *dico, t_dico_insert data);
void	lp_dico_foreach(t_dico dico, void (*f)(t_string key, void *value));
void	lp_dico_set_many(t_dico *dico, t_dico_insert *datalist, size_t n);
void	lp_dico_delete(t_dico dico);
#endif