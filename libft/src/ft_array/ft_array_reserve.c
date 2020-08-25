/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_reserve.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:50:41 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/17 13:06:32 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"

int		ft_array_reserve(t_array *ar, size_t size)
{
	size_t total_size;
	size_t new_size;

	total_size = size + ar->size;
	if (total_size > ar->size)
	{
		new_size = (ar->size > 0 ? ar->max : 16);
		while (new_size < total_size)
			new_size *= 2;
		return (ft_array_resize(ar, new_size));
	}
	return (0);
}
