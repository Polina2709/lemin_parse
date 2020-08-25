/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_numbers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:38:31 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/20 11:43:55 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t		ft_get_number(va_list args, t_spec specifier)
{
	intmax_t number;

	number = va_arg(args, intmax_t);
	if (specifier.length_type == LENGTH_HH)
		number = (char)number;
	else if (specifier.length_type == LENGTH_H)
		number = (short int)number;
	else if (specifier.length_type == LENGTH_L)
		number = (long int)number;
	else if (specifier.length_type == LENGTH_LL)
		number = (long long int)number;
	else if (specifier.length_type == LENGTH_J)
		number = (intmax_t)number;
	else if (specifier.length_type == LENGTH_Z)
		number = (size_t)number;
	else
		number = (int)number;
	return (number);
}

uintmax_t		ft_get_number_u(va_list args, t_spec specifier)
{
	uintmax_t number;

	number = va_arg(args, uintmax_t);
	if (specifier.length_type == LENGTH_HH)
		number = (unsigned char)number;
	else if (specifier.length_type == LENGTH_H)
		number = (unsigned short int)number;
	else if (specifier.length_type == LENGTH_L)
		number = (unsigned long int)number;
	else if (specifier.length_type == LENGTH_LL)
		number = (unsigned long long int)number;
	else if (specifier.length_type == LENGTH_J)
		number = (uintmax_t)number;
	else if (specifier.length_type == LENGTH_Z)
		number = (size_t)number;
	else
		number = (unsigned int)number;
	return (number);
}

void			ft_get_number_size_u(uintmax_t number,
									uintmax_t str_length, int *size)
{
	*size += 1;
	while (number >= str_length)
	{
		number /= str_length;
		*size += 1;
	}
}
