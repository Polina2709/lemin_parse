/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:38:27 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/20 11:43:50 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_types g_types[ARCOUNT] = {
	{'c', ft_type_c}, {'s', ft_type_s}, {'f', ft_type_f},
	{'F', ft_type_f}, {'d', ft_type_d}, {'i', ft_type_d},
	{'%', ft_type_percent}, {'p', ft_type_p}, {'o', ft_type_o},
	{'x', ft_type_x}, {'X', ft_type_x_upper}, {'u', ft_type_u},
	{'O', ft_type_o_upper}, {'U', ft_type_u_upper}
};

/*
** Comparison elements of g_types structs with character and
** use of the corresponding finction.
*/

int		ft_check_type(char **str, t_spec *specifier, va_list arguments)
{
	int i;
	int size;

	i = 0;
	while (i < ARCOUNT)
	{
		if (**str == g_types[i].type_name)
		{
			*str += 1;
			specifier->type = g_types[i].type_name;
			return (g_types[i].f(arguments, specifier));
		}
		i++;
	}
	size = 1;
	if (!specifier->minus)
		size = ft_alignment(specifier, size);
	ft_record_in_buffer(*str, 1, specifier);
	if (specifier->minus)
		size = ft_alignment(specifier, size);
	*str += 1;
	return (size);
}

void	ft_init_specifier(t_spec *specifier)
{
	specifier->length_type = 0;
	specifier->minus = 0;
	specifier->plus = 0;
	specifier->sharp = 0;
	specifier->space = 0;
	specifier->width = 0;
	specifier->precision = 0;
	specifier->zero = 0;
	specifier->multi_lt = 0;
}

/*
** Initialization t_spec struct and find length, width, flags, precision.
** After this - check type.
*/

int		ft_search_flags(char **str, va_list arguments, t_spec *specifier)
{
	int flags_found;

	ft_init_specifier(specifier);
	while (**str)
	{
		flags_found = 0;
		while (ft_length(str, specifier) ||
				ft_flags(str, specifier) ||
				ft_width(str, specifier, arguments) ||
				ft_precision(str, specifier, arguments))
			flags_found = 1;
		if (ft_isalpha(**str) || **str == '%')
			return (ft_check_type(str, specifier, arguments));
		else if (!*(*str + 1) || !flags_found)
			return (0);
	}
	return (0);
}

/*
** Start stdarg and percent sign search. If it's found -
** check all types, flags and other
*/

int		ft_printf(const char *format, ...)
{
	t_spec	specifier;
	va_list arguments;
	int		return_bytes;
	char	*format_str;

	return_bytes = 0;
	specifier.bytes = 0;
	specifier.total_bytes = 0;
	va_start(arguments, format);
	format_str = (char*)format;
	while (*format_str)
		if (*format_str == '%')
		{
			format_str++;
			return_bytes += ft_search_flags(&format_str, arguments, &specifier);
		}
		else
			return_bytes += ft_str_until_percent(&format_str, &specifier);
	if (specifier.bytes > 0)
		write(1, specifier.buffer, (size_t)specifier.bytes);
	va_end(arguments);
	return (return_bytes);
}
