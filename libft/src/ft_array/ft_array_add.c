/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:49:34 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/17 13:05:52 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include "libft.h"

int		ft_array_add(t_array *ar, void const *data, size_t datalen)
{
	if (ft_array_reserve(ar, datalen))
		return (1);
	ft_memcpy(ARRAY_END(ar), data, ARRAY_OFFSET(ar, datalen));
	ar->size += datalen;
	return (0);
}
