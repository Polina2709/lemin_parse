/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coord.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:49:58 by jconcent          #+#    #+#             */
/*   Updated: 2020/09/06 12:15:44 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		second_coordinates(char *room)
{
	int i;

	i = first_coordinates(room);
	while (room[i] != ' ')
		i++;
	return (i + 1);
}

int		first_coordinates(char *room)
{
	int i;

	i = 0;
	while (room[i] != ' ')
		i++;
	return (i + 1);
}

void	add_coordinates(char *room)
{
	int i;

	i = 0;
	while (room[i])
		i++;
	room[i] = ' ';
}

/*
**	Line with room can have only three strings - name of rooms, first coord and second coord.
**	If coord is not number - is not valid.
*/

int check_coordinates(t_lm_data *lem)
{
	int i;
	int j;
	int rt;
	char **split;

	i = 0;
	rt = 0;
	while (lem->rooms[i])
	{
		j = 1;
		split = ft_strsplit(lem->rooms[i], ' ');
		if (ft_tablen(split) != 3)
			rt = -1;
		while (split[j])
		{
			if (!ft_isnumber(split[j]))
				rt = -1;
			j++;
		}
		ft_clear_table(split);
		i++;
		if (rt == -1)
			break ;
	}
	return (rt);
}

/*
**	When we check coordinates we no longer need them.
**	We add '\0' after name of room.
*/

void remove_coordinates(t_lm_data *lem)
{
	int i;
	int j;

	i = 0;
	while (lem->rooms[i])
	{
		j = 0;
		while (lem->rooms[i][j] != ' ')
			j++;
		lem->rooms[i][j] = '\0';
		i++;
	}
	i = 0;
	while (lem->start[i] != ' ')
		i++;
	lem->start[i] = '\0';
	i = 0;
	while (lem->end[i] != ' ')
		i++;
	lem->end[i] = '\0';
}