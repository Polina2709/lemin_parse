/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_insert.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:49:57 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/17 13:04:18 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include "libft.h"

int		ft_array_insert(t_array *ar, void const *data,
							size_t dlen, size_t index)
{
	if (ar->size < index || ft_array_reserve(ar, dlen))
		return (1);
	ft_memmove(GET_ARRAY_ELEM(ar, index + dlen),
				GET_ARRAY_ELEM(ar, index),
				ARRAY_OFFSET(ar, ar->size - index));
	ft_memcpy(GET_ARRAY_ELEM(ar, index), data, ARRAY_OFFSET(ar, dlen));
	ar->size += dlen;
	return (0);
}
