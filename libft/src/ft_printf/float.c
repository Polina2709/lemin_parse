/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:38:20 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/20 11:43:35 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_float_rounded(char **str, int *size)
{
	char	*s;
	int		t;

	t = *size;
	s = *str;
	while (--t >= 0)
	{
		if (s[t] >= '0' && s[t] < '9')
		{
			s[t]++;
			return ;
		}
		else if (s[t] == '9')
			s[t] = '0';
		else if (s[t] != '.')
			return ;
	}
}

double		ft_module(long double nb, int *size)
{
	double module;

	module = 1;
	while ((int)(nb /= 10) != 0 && (*size)++)
		module *= 10;
	return (module);
}

void		ft_integer(long double *nb, char **str, int *i, double module)
{
	char *s;

	s = *str;
	while ((int)module != 0)
	{
		s[(*i)++] = (char)((*nb / module) + 48);
		*nb -= (int)(*nb / module) * module;
		module /= 10;
	}
}

void		ft_decimals(char **str, int *i, long double nb, int precision)
{
	int			j;
	char		*s;

	precision -= 1;
	j = 0;
	s = *str;
	s[(*i)++] = '.';
	while (j++ < precision)
	{
		s[(*i)++] = '0' + (unsigned long long)(nb * 10) % 10;
		nb *= 10;
	}
	if ((unsigned long long)(nb * 10) % 10 >= 5)
		ft_float_rounded(&s, i);
}

int			ft_float_to_string(long double nb, char **s, int precision)
{
	int		i;
	int		size;
	char	*str;
	double	module;

	if (nb < 0)
		nb = -nb;
	size = 1;
	i = 0;
	precision++;
	module = ft_module(nb, &size);
	size += precision;
	if (!(str = malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_integer(&nb, &str, &i, module);
	ft_decimals(&str, &i, nb, precision);
	*s = str;
	return (size);
}
