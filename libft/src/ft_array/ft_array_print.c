/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_array_print.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 12:50:16 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/20 11:59:44 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_array.h"
#include "libft.h"
#include "stdio.h"

void	ft_array_print(t_array *v)
{
	int i;

	i = 0;
	while (i < (int)v->size)
	{
		ft_printf("%d ", ((int *)v->data)[i]);
		i++;
	}
	ft_printf("\n");
}
