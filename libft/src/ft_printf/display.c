/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:38:15 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/20 11:43:30 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_display_sign(intmax_t number, t_spec *specifier)
{
	if (number < 0)
		ft_record_in_buffer("-", 1, specifier);
	if (specifier->plus && number >= 0)
		ft_record_in_buffer("+", 1, specifier);
	else if (specifier->space && number >= 0)
		ft_record_in_buffer(" ", 1, specifier);
}

int		ft_display_d(t_spec *specifier, int size,
					int precision, intmax_t number)
{
	int width_size;
	int width;

	width = 0;
	width_size = 0;
	if (!specifier->minus)
	{
		if (specifier->width && specifier->zero)
			ft_display_sign(number, specifier);
		if (number == 0 && precision < -1)
			width_size = ft_alignment(specifier, size + 1) - size;
		else
			width_size = ft_alignment(specifier, size) - size;
	}
	if ((specifier->width && (specifier->minus ||
							!specifier->zero)) || !specifier->width)
		ft_display_sign(number, specifier);
	while (width++ < precision)
		ft_record_in_buffer("0", 1, specifier);
	if (size > 0)
		ft_putnbr_base((uintmax_t)(number < 0 ? -number :
									number), "0123456789", 10, specifier);
	return (size + width_size);
}

void	ft_display_padding(t_spec *sp, uintmax_t nb, int *size,
							char *base)
{
	int width;
	int precision;

	if (sp->precision <= 0 && sp->width <= 0)
	{
		*size += (sp->type == 'p' && *size <= 0) ? 2 : 0;
		return ;
	}
	width = 0;
	precision = sp->precision - *size;
	*size = (sp->precision > *size) ? sp->precision : *size;
	while (sp->minus && width++ < precision)
		ft_record_in_buffer("0", 1, sp);
	if (sp->minus && sp->precision != -1)
		ft_putnbr_base(nb, base, ft_strlen(base), sp);
	width = 0;
	while (width++ < sp->width - (*size +
			((sp->type == 'p' || sp->sharp) ? 2 : 0)))
		ft_record_in_buffer((sp->zero && !sp->minus) ? "0" : " ", 1, sp);
	width = 0;
	if (sp->sharp && !sp->minus && sp->width && !sp->zero)
		ft_record_sharp(sp);
	while (!sp->minus && width++ < precision)
		ft_record_in_buffer("0", 1, sp);
	*size += (*size > 0 && sp->type == 'p') ? 2 : 0;
}

void	ft_putnbr_base(uintmax_t nbr, char *str,
						uintmax_t str_length, t_spec *specifier)
{
	if (nbr >= str_length)
		ft_putnbr_base(nbr / str_length, str, str_length, specifier);
	if (specifier->type == 'p' && specifier->precision == -1 && !nbr)
		return ;
	else
		ft_record_in_buffer(&str[nbr % str_length], 1, specifier);
}
