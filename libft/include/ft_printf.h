/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 12:37:39 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/24 12:18:10 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

# define ARCOUNT 14

# define LENGTH_HH 1
# define LENGTH_H 2
# define LENGTH_L 3
# define LENGTH_LL 4
# define LENGTH_Z 5
# define LENGTH_J 6
# define LENGTH_FL 7

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <stddef.h>

# define BUFF_SIZE 16000

typedef struct	s_spec
{
	int		minus;
	int		plus;
	int		space;
	int		sharp;
	int		zero;
	int		precision;
	int		width;
	int		length_type;
	int		multi_lt;
	char	type;
	char	buffer[BUFF_SIZE];
	int		bytes;
	int		total_bytes;
}				t_spec;

typedef struct	s_types
{
	char	type_name;
	int		(*f)();
}				t_types;

int				ft_printf(const char *format, ...);
int				ft_search_flags(char **str, va_list arguments,
												t_spec *specifier);
void			ft_init_specifier(t_spec *specifier);
int				ft_str_until_percent(char **str, t_spec *specifier);

int				ft_length(char **str, t_spec *specifier);
int				ft_flags(char **str, t_spec *specifier);
int				ft_width(char **str, t_spec *specifier, va_list args);
int				ft_precision(char **str, t_spec *specifier, va_list args);
int				ft_check_type(char **str, t_spec *specifier, va_list arguments);
void			ft_length_type(char **str, t_spec *specifier,
									int type, int type_size);

int				ft_record_in_buffer(void *s, int size, t_spec *specifier);
int				ft_alignment(t_spec *specifier, int size);
int				ft_base_processing(va_list args, t_spec *specifier,
								char *base, char *sharp_content);
intmax_t		ft_get_number(va_list args, t_spec specifier);
uintmax_t		ft_get_number_u(va_list args, t_spec specifier);
void			ft_get_number_size_u(uintmax_t number, uintmax_t str_length,
																int *size);
int				ft_sharp_accounting(uintmax_t nb, t_spec *specifier,
								int *size, char *sharp_content);
void			ft_display_padding(t_spec *sp, uintmax_t nb,
								int *size, char *base);
void			ft_putnbr_base(uintmax_t nbr, char *str, uintmax_t str_length,
														t_spec *specifier);
void			ft_display_sign(intmax_t number, t_spec *specifier);
int				ft_display_d(t_spec *specifier, int size,
							int precision, intmax_t number);
int				ft_float_to_string(long double nb, char **s, int precision);
int				ft_total_size_float(long double nb, t_spec *specifier,
									int size, int *sign);
int				ft_rounded(char **str, t_spec *specifier);
void			ft_precision_float(t_spec *specifier);
void			ft_record_sharp(t_spec *specifier);

int				ft_type_c(va_list args, t_spec *specifier);
int				ft_type_s(va_list args, t_spec *specifier);
int				ft_type_f(va_list args, t_spec *specifier);
int				ft_type_d(va_list args, t_spec *specifier);
int				ft_type_p(va_list args, t_spec *specifier);
int				ft_type_o(va_list args, t_spec *specifier);
int				ft_type_o_upper(va_list args, t_spec *specifier);
int				ft_type_x(va_list args, t_spec *specifier);
int				ft_type_x_upper(va_list args, t_spec *specifier);
int				ft_type_u(va_list args, t_spec *specifier);
int				ft_type_u_upper(va_list args, t_spec *specifier);
int				ft_type_percent(va_list args, t_spec *specifier);

#endif
