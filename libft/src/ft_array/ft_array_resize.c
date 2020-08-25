/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_resize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:50:49 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/17 13:05:25 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include "libft.h"

int		ft_array_resize(t_array *ar, size_t new_size)
{
	void *tmp;

	tmp = malloc(new_size * ar->type_size);
	if (tmp == NULL)
		return (1);
	if (ar->size > new_size)
		ar->size = new_size;
	ft_memcpy(tmp, ar->data, ar->size * ar->type_size);
	free(ar->data);
	ar->data = tmp;
	ar->max = new_size;
	return (0);
}
