/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   liblp_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lperroti <lperroti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 08:06:37 by lperroti          #+#    #+#             */
/*   Updated: 2023/04/13 03:06:49 by lperroti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLP_STR_H
# define LIBLP_STR_H
# include "../liblp.h"

char		*lp_strtrim(char const *s1, char const *set);
char		*lp_strmapi(char const *s, char (*f)(unsigned int, char));
void		lp_striteri(char *s, void (*f)(unsigned int, char *));
size_t		lp_strlen(const char *s);
int			lp_strncmp(const char *s1, const char *s2, size_t n);
size_t		lp_strlcpy(char *dst, const char *src, size_t size);
size_t		lp_strlcat(char *dst, const char *src, size_t size);
char		*lp_strchr(char const *s, int c);
char		*lp_strrchr(char const *s, int c);
char		*lp_strnstr(const char *big, const char *little, size_t len);
char		*lp_strdup(const char *s);
char		*lp_strjoin(char const *s1, char const *s2);
char		**lp_split(char const *s, char c);
char		*lp_strdup(const char *s);
char		*lp_strjoin(char const *s1, char const *s2);
char		**lp_split(char const *s, char c);
char		*lp_substr(char const *s, unsigned int start, size_t len);
char		*lp_itoa(int n);
int			lp_atoi(const char *nptr);
long long	lp_atol(const char *nptr);
double		lp_atof(char *nptr);
bool		lp_str_isequal(const char *s1, const char *s2);
bool		lp_strcat(char **s1, char const *s2);
char		*lp_strfusion(char **p_s1, char *s2);
int			lp_atoi_base(char *str, char *base);
char		*lp_itoa_base(int nbr, char *base);
char		*lp_uitoa_base(unsigned int nbr, char *base);
char		*lp_ultoa_base(unsigned long nbr, char *base);

#endif