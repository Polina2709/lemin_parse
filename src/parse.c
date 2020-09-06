/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 13:04:44 by jconcent          #+#    #+#             */
/*   Updated: 2020/09/06 11:37:30 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

/*
**	1. Getting nb_ants
**	2. Getting start-rooms and end-rooms
**	3. Getting all rooms and all links
*/

static int get_data(char **map, t_lm_data *lem)
{
	int rt;

	rt = 0;
	if ((lem->nb_ants = get_ant_nb(map, lem)) == -1)
		rt = -1;
	while (map[lem->i])
	{
		if (ft_strequ(map[lem->i], "##start"))
			if (get_start_get_end(map, lem, 1) == -1)
				rt = -1;
		if (ft_strequ(map[lem->i], "##end"))
			if (get_start_get_end(map, lem, 2) == 1)
				rt = -1;
		if (map[lem->i][0] != '#' && count_spaces(map[lem->i]) == 2)
			if (get_room_get_link(map[lem->i], lem, 1) == -1)
				rt = -1;
		if (map[lem->i][0] != '#' && count_spaces(map[lem->i]) != 2 && ft_strchr(map[lem->i], '-'))
			get_room_get_link(map[lem->i], lem, 2);
		if ((map[lem->i][0] != '#' && count_spaces(map[lem->i]) != 2 && !ft_strchr(map[lem->i], '-')) || map[lem->i][0] == 'L')
			rt = -1;
		lem->i++;
	}
	return (rt);
}

/*
**	Filling the structure with data and checking it for validity
*/

int	parse(char **map, t_lm_data *lem)
{
	if (get_data(map, lem) == -1)
		return (-1);
	if (check_coordinates(lem) == -1)
		return (-1);
	if (!lem->start || !lem->end || !ft_tablen(lem->rooms) || !ft_tablen(lem->links))
		return (-1);
	remove_coordinates(lem);
	if (check_identical_rooms(lem) == -1)
		return (-1);
	if (check_first_link(lem) == -1)
		return (-1);
	if (check_second_link(lem) == -1)
		return (-1);
	return (0);
}
