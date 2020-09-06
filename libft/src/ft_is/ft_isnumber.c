/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 15:12:36 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/26 15:13:13 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isnumber(char *str)
{
	int i;
	int sign;
	int digit;

	i = 0;
	sign = 0;
	digit = 0;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
		{
			sign++;
			if (sign > 1 || digit > 0)
				return (0);
		}
		else if (ft_isdigit(str[i]))
			digit++;
		else
			return (0);
		i++;
	}
	if (digit > 0)
		return (1);
	return (0);
}