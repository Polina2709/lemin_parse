/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_and_decimal.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:38:43 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/20 11:43:40 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_percent(va_list args, t_spec *specifier)
{
	int size;

	size = 1;
	(void)args;
	if (!specifier->minus)
		size = ft_alignment(specifier, size);
	ft_record_in_buffer("%", 1, specifier);
	if (specifier->minus)
		size = ft_alignment(specifier, size);
	return (size);
}

int		ft_type_f(va_list args, t_spec *specifier)
{
	char		*number;
	int			size;
	int			total_size;
	int			sign;
	long double num;

	sign = 0;
	ft_precision_float(specifier);
	if (specifier->length_type == LENGTH_FL)
		num = va_arg(args, long double);
	else
		num = va_arg(args, double);
	size = ft_float_to_string(num, &number, specifier->precision);
	if (specifier->multi_lt == 42)
		size = ft_rounded(&number, specifier);
	total_size = ft_total_size_float(num, specifier, size, &sign);
	ft_record_in_buffer(number, size, specifier);
	total_size = specifier->minus ? ft_alignment(specifier,
									size + sign) : total_size;
	free(number);
	return (total_size);
}

int		ft_type_o(va_list args, t_spec *specifier)
{
	int			size;
	int			nb_size;
	uintmax_t	number;

	if (specifier->precision != 0)
		specifier->zero = 0;
	size = 0;
	number = ft_get_number_u(args, *specifier);
	if (specifier->precision >= 0 || number > 0)
		ft_get_number_size_u(number, 8, &size);
	if (specifier->sharp && (number > 0 || specifier->precision < 0))
		size += 1;
	nb_size = size;
	size = (specifier->precision > size) ? specifier->precision : size;
	if (specifier->width && !specifier->minus)
		size = ft_alignment(specifier, size);
	if (specifier->sharp && (number > 0 || specifier->precision < 0))
		ft_record_in_buffer("0", 1, specifier);
	while (nb_size++ < specifier->precision)
		ft_record_in_buffer("0", 1, specifier);
	if (specifier->precision >= 0 || number > 0)
		ft_putnbr_base(number, "01234567", 8, specifier);
	if (specifier->width && specifier->minus)
		size = ft_alignment(specifier, size);
	return (size);
}

int		ft_type_d(va_list args, t_spec *specifier)
{
	int			size;
	intmax_t	number;
	int			precision;

	if (specifier->precision != 0)
		specifier->zero = 0;
	number = ft_get_number(args, *specifier);
	size = 0;
	ft_get_number_size_u((uintmax_t)(number < 0 ? -number : number), 10, &size);
	precision = specifier->precision - size;
	size = (specifier->precision > size) ? specifier->precision : size;
	size = (specifier->precision == -1 && number == 0) ? 0 : size;
	size += (number >= 0 && (specifier->plus || specifier->space));
	if (number == 0 && precision < -1)
		size -= 1;
	if (number < 0)
		size += 1;
	size = ft_display_d(specifier, size, precision, number);
	if (number == 0 && precision < -1)
		size = (specifier->minus) ? ft_alignment(specifier, size + 1) : size;
	else
		size = (specifier->minus) ? ft_alignment(specifier, size) : size;
	return (size);
}

int		ft_type_u(va_list args, t_spec *specifier)
{
	return (ft_base_processing(args, specifier, "0123456789", ""));
}
