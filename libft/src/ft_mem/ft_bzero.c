/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:05:53 by jconcent          #+#    #+#             */
/*   Updated: 2019/09/06 14:15:18 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char *temp;

	temp = (unsigned char *)s;
	while (n-- > 0)
	{
		*(temp++) = 0;
	}
}
