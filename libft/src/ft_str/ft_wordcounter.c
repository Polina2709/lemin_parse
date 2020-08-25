/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcounter.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:08:06 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/17 13:08:46 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_wordcounter(const char *str, char c)
{
	int i;
	int wcount;
	int state;

	i = 0;
	wcount = 0;
	state = 0;
	while (str[i])
	{
		if (c == str[i])
			state = 0;
		else if (state == 0)
		{
			state = 1;
			wcount++;
		}
		i++;
	}
	return (wcount);
}
