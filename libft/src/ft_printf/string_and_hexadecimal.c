/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_and_hexadecimal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:38:39 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/20 11:44:07 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_c(va_list args, t_spec *specifier)
{
	int character;
	int width;

	character = va_arg(args, int);
	width = 0;
	if (specifier->width)
	{
		if (specifier->minus)
			ft_record_in_buffer(&character, 1, specifier);
		while (width++ < specifier->width - 1)
			ft_record_in_buffer((specifier->zero &&
								!specifier->minus) ? "0" : " ", 1, specifier);
	}
	if (!specifier->width || !specifier->minus)
		ft_record_in_buffer(&character, 1, specifier);
	return ((specifier->width) ? width : 1);
}

int		ft_type_s(va_list args, t_spec *specifier)
{
	char	*string;
	int		width;
	int		size;

	string = va_arg(args, char*);
	if (!string)
		size = 6;
	else
		size = ft_strlen(string);
	size = (specifier->precision == -1) ? 0 : size;
	if (specifier->precision > 0 && specifier->precision < size && size > 0)
		size = size - (size - specifier->precision);
	if (specifier->width)
	{
		if (specifier->minus)
			ft_record_in_buffer((string) ? string : "(null)", size, specifier);
		width = 0;
		while (width++ < specifier->width - size)
			ft_record_in_buffer((specifier->zero &&
								!specifier->minus) ? "0" : " ", 1, specifier);
	}
	if (!specifier->width || !specifier->minus)
		ft_record_in_buffer((string) ? string : "(null)", size, specifier);
	return (size + (specifier->width - size > 0 ? specifier->width - size : 0));
}

int		ft_type_p(va_list args, t_spec *specifier)
{
	specifier->length_type = LENGTH_L;
	specifier->sharp = 1;
	return (ft_type_x(args, specifier));
}

int		ft_type_x(va_list args, t_spec *specifier)
{
	return (ft_base_processing(args, specifier, "0123456789abcdef", "0x"));
}

int		ft_type_x_upper(va_list argc, t_spec *specifier)
{
	return (ft_base_processing(argc, specifier, "0123456789ABCDEF", "0X"));
}
