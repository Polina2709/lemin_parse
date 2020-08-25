/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:49:23 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/17 17:36:28 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ARRAY_H
# define FT_ARRAY_H

# include <stddef.h>

typedef struct	s_array
{
	void		*data;
	size_t		size;
	size_t		max;
	size_t		type_size;
}				t_array;

# define INIT_ARRAY(T) (t_array){NULL, 0, 0, sizeof(T)}
# define CONTENT_ARRAY(C, I) ((int *)(C)->data)[I]
# define ARRAY_START(A) ((A)->data)
# define ARRAY_STEP(A) ((A)->type_size)
# define GET_ARRAY_ELEM(A, I) (ARRAY_START(A) + ARRAY_OFFSET(A, I))
# define ARRAY_OFFSET(A, I) ((I) * ARRAY_STEP(A))
# define ARRAY_END(A) ((A)->data + (A)->size * (A)->type_size)

void			ft_array_clear(t_array *ar);
int				ft_array_insert(t_array *ar, void const *data,
								size_t dlen, size_t index);
int				ft_array_resize(t_array *ar, size_t new_size);
int				ft_array_reserve(t_array *ar, size_t size);
void			ft_array_print(t_array *v);
int				ft_array_add(t_array *ar, void const *data, size_t datalen);
void			ft_array_pop(t_array *ar, size_t len);
int				ft_array_pop_index(t_array *ar, size_t index, size_t len);

#endif
