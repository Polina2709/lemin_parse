/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:38:36 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/20 11:44:02 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_precision(char **str, t_spec *specifier, va_list args)
{
	int precision;

	if (**str == '.')
	{
		*str += 1;
		if (!ft_isdigit(**str) && **str != '*')
		{
			specifier->precision = -1;
			return (1);
		}
		precision = (**str == '*') ? va_arg(args, int) : ft_atoi(*str);
		specifier->precision = (precision == 0 ? -1 : precision);
		if (specifier->precision < 0 && specifier->precision != -1)
			specifier->precision = 0;
		if (**str == '*')
			precision = 1;
		else if (precision == 0)
			*str += 1;
		if (**str == '0')
			*str += 1;
		while (precision > 0 && (*str = *str + 1))
			precision /= 10;
		return (1);
	}
	return (0);
}

int		ft_width(char **str, t_spec *specifier, va_list args)
{
	int width;

	if ((width = ft_atoi(*str)) > 0 || **str == '*')
	{
		if (**str == '*')
		{
			width = va_arg(args, int);
			if (width < 0)
				specifier->minus = 1;
			specifier->width = (width < 0 ? width * -1 : width);
			width = 1;
		}
		else
			specifier->width = width;
		while (width > 0 && (*str += 1))
			width /= 10;
		return (1);
	}
	return (0);
}

int		ft_flags(char **str, t_spec *specifier)
{
	if (**str == '-')
		specifier->minus = 1;
	else if (**str == '+')
		specifier->plus = 1;
	else if (**str == ' ')
		specifier->space = 1;
	else if (**str == '#')
		specifier->sharp = 1;
	else if (**str == '0')
		specifier->zero = 1;
	else
		return (0);
	*str += 1;
	return (1);
}

void	ft_length_type(char **str, t_spec *specifier, int type, int type_size)
{
	*str += type_size;
	specifier->multi_lt++;
	if (specifier->length_type < type)
		specifier->length_type = type;
}

int		ft_length(char **str, t_spec *specifier)
{
	if (**str == 'h' && *(*str + 1) == 'h')
		ft_length_type(str, specifier, LENGTH_HH, 2);
	else if (**str == 'h')
		ft_length_type(str, specifier, LENGTH_H, 1);
	else if (**str == 'l' && *(*str + 1) == 'l')
		ft_length_type(str, specifier, LENGTH_LL, 2);
	else if (**str == 'l')
		ft_length_type(str, specifier, LENGTH_L, 1);
	else if (**str == 'j')
		ft_length_type(str, specifier, LENGTH_J, 1);
	else if (**str == 'z')
		ft_length_type(str, specifier, LENGTH_Z, 1);
	else if (**str == 'L')
		ft_length_type(str, specifier, LENGTH_FL, 1);
	else
		return (0);
	return (1);
}
