/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:32:13 by jconcent          #+#    #+#             */
/*   Updated: 2020/10/07 10:04:08 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	'r_l' can have two values - 1 or 2.
**	1 - is rooms and 2 - is links.
*/

int			get_room_get_link(char *line, t_lm_data *lem, int r_l)
{
	if (r_l == 1)
	{
		lem->rooms[lem->r] = ft_strdup(line);
		lem->r++;
		if (lem->l)
			return (-1);
	}
	else if (r_l == 2)
	{
		lem->links[lem->l] = ft_strdup(line);
		lem->l++;
	}
	return (0);
}

static int	isroom(char *line)
{
	if (line[0] != '#' && count_spaces(line) == 2)
		return (1);
	return (0);
}

/*
**	's_e' can have two values - 1 or 2.
**	1 - is start and 2 - is end.
*/

int			get_start_get_end(char **map, t_lm_data *lem, int s_e)
{
	if (s_e == 1)
	{
		while (map[lem->i][0] == '#' && map[lem->i + 1])
			lem->i++;
		if (lem->start)
			return (-1);
		if (isroom(map[lem->i]))
			lem->start = ft_strdup(map[lem->i]);
	}
	else if (s_e == 2)
	{
		while (map[lem->i][0] == '#' && map[lem->i + 1])
			lem->i++;
		if (lem->end)
			return (-1);
		if (isroom(map[lem->i]))
			lem->end = ft_strdup(map[lem->i]);
	}
	return (0);
}

void		ft_array_add_space(t_array *self, char *data)
{
	ft_array_add(self, data, ft_strlen(data));
	ft_array_add(self, " ", 1);
}

void		ft_print_tab(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		ft_printf("%s\n", tab[i]);
		i++;
	}
}
