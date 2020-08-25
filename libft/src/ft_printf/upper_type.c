/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upper_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:38:46 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/20 11:44:12 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_record_sharp(t_spec *specifier)
{
	if (specifier->type == 'x')
		ft_record_in_buffer("0x", 2, specifier);
	if (specifier->type == 'X')
		ft_record_in_buffer("0X", 2, specifier);
	if (specifier->type == 'u')
		ft_record_in_buffer("", 2, specifier);
	if (specifier->type == 'p')
		ft_record_in_buffer("0x", 2, specifier);
}

int		ft_type_o_upper(va_list args, t_spec *specifier)
{
	specifier->length_type = LENGTH_L;
	return (ft_type_o(args, specifier));
}

int		ft_type_u_upper(va_list args, t_spec *specifier)
{
	specifier->length_type = LENGTH_L;
	return (ft_type_u(args, specifier));
}
