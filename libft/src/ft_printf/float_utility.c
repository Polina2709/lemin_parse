/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_utility.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:38:24 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/20 11:43:45 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_float_sign(t_spec *specifier, int *size, long double nb)
{
	if (nb < 0 && *size++)
		ft_record_in_buffer("-", 1, specifier);
	if (specifier->plus && nb >= 0 && *size++)
		ft_record_in_buffer("+", 1, specifier);
	else if (specifier->space && nb >= 0 && *size++)
		ft_record_in_buffer(" ", 1, specifier);
}

int		ft_total_size_float(long double nb, t_spec *specifier,
							int size, int *sign)
{
	int total_size;

	total_size = 0;
	if (!specifier->minus)
	{
		if (specifier->width && specifier->zero)
			ft_float_sign(specifier, &size, nb);
		if (nb < 0 || specifier->plus || specifier->space)
			total_size = ft_alignment(specifier, size + 1);
		else
			total_size = ft_alignment(specifier, size);
	}
	if ((specifier->width && (specifier->minus ||
								!specifier->zero)) || !specifier->width)
	{
		if (nb < 0 && size++ && (*sign = 1) == 1)
			ft_record_in_buffer("-", 1, specifier);
		if (specifier->plus && nb >= 0 && size++ && (*sign = 1) == 1)
			ft_record_in_buffer("+", 1, specifier);
		else if (specifier->space && nb >= 0 && size++ && (*sign = 1) == 1)
			ft_record_in_buffer(" ", 1, specifier);
	}
	return (total_size);
}

int		ft_rounded(char **str, t_spec *specifier)
{
	char	*s;
	int		i;

	s = *str;
	i = 0;
	while (s[i] != '.')
		i++;
	if (s[i + 1] == '5')
	{
		if (s[i - 1] % 2 != 0)
			s[i - 1] += 1;
	}
	else if (s[i + 1] > '5')
		s[i - 1] += 1;
	if (specifier->sharp)
	{
		s[i + 1] = '\0';
		i++;
	}
	else
		s[i] = '\0';
	*str = s;
	return (i);
}

void	ft_precision_float(t_spec *specifier)
{
	if (specifier->precision <= 0)
	{
		if (specifier->precision == -1)
			specifier->multi_lt = 42;
		specifier->precision = 6;
	}
}
