/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:38:50 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/20 11:44:17 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sharp_accounting(uintmax_t nb, t_spec *specifier,
							int *size, char *sharp_content)
{
	int precision;

	precision = 0;
	if (nb == 0 && specifier->type != 'p')
		specifier->sharp = 0;
	if (specifier->sharp && (!specifier->width ||
		specifier->minus || specifier->zero))
		ft_record_in_buffer(sharp_content, ft_strlen(sharp_content), specifier);
	precision = specifier->precision > *size;
	return (precision);
}

int		ft_base_processing(va_list args, t_spec *specifier,
							char *base, char *sharp_content)
{
	int			size;
	uintmax_t	number;
	int			precision;

	if (specifier->precision != 0)
		specifier->zero = 0;
	size = 0;
	number = ft_get_number_u(args, *specifier);
	ft_get_number_size_u(number, (int)ft_strlen(base), &size);
	precision = ft_sharp_accounting(number, specifier, &size, sharp_content);
	if (specifier->precision == -1 && number == 0)
		size = 0;
	ft_display_padding(specifier, number, &size, base);
	if ((!specifier->width || !specifier->minus) && size > 0)
		ft_putnbr_base(number, base, (int)ft_strlen(base), specifier);
	if (specifier->sharp && size > 0 && ((!specifier->width ||
		specifier->minus) || precision) && specifier->type != 'p')
		size += (int)ft_strlen(sharp_content);
	if (size == 0 && specifier->type == 'p')
		size = 2;
	if (specifier->type == 'p' && !specifier->minus && !specifier->precision)
		size += 2;
	return (specifier->width - size > 0 ? specifier->width : size);
}

int		ft_alignment(t_spec *specifier, int size)
{
	int width;

	if (specifier->width <= 0)
		return (size);
	width = 0;
	while (width++ < specifier->width - size)
		ft_record_in_buffer((specifier->zero &&
							!specifier->minus) ? "0" : " ", 1, specifier);
	return (size + width - 1);
}

int		ft_str_until_percent(char **str, t_spec *specifier)
{
	int bytes;

	if (ft_strchr(*str, '%'))
		bytes = (int)(ft_strchr(*str, '%') - *str);
	else
		bytes = ft_strlen(*str);
	ft_record_in_buffer(*str, bytes, specifier);
	*str += bytes;
	return (bytes);
}

int		ft_record_in_buffer(void *s, int size, t_spec *specifier)
{
	int		i;
	char	*str;

	i = 0;
	str = s;
	while (i < size)
		specifier->buffer[specifier->bytes++] = str[i++];
	specifier->total_bytes += size;
	return (size);
}
