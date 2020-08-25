/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_pop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:50:04 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/17 13:07:43 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include "libft.h"

void	ft_array_pop(t_array *ar, size_t len)
{
	ar->size -= len < ar->size ? len : ar->size;
}

int		ft_array_pop_index(t_array *ar, size_t index, size_t len)
{
	size_t n;

	n = len < ar->size - index ? len : ar->size - index;
	if (index > ar->size)
		return (1);
	ft_memmove(GET_ARRAY_ELEM(ar, index),
				GET_ARRAY_ELEM(ar, index + n),
				ARRAY_OFFSET(ar, ar->size - n - index));
	ar->size -= n;
	return (0);
}
