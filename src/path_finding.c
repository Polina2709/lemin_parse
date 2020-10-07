/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:55:50 by jconcent          #+#    #+#             */
/*   Updated: 2020/10/07 10:18:28 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Adding to the matrix of links the number of transition
**	to rooms without a direct connection. For example:
**	if room-1 and room-2 have connection then it will be (1)
**	in matrix. If room-1 and room-3 don't have connection - it
**	will be (number of room + 1). And if room-2 and room-3 have
**	connection - room-1 and room-3 can be linked through room-2
**	and in matrix it will be (2);
*/

static void		distance(int **route, int size)
{
	int i;
	int j;
	int col;
	int update;

	i = -1;
	while (++i < size)
	{
		j = 0;
		while (j < size)
		{
			col = 0;
			update = 0;
			while (col < size)
			{
				if (route[j][col] + route[i][j] < route[i][col])
				{
					route[i][col] = route[j][col] + route[i][j];
					update = 1;
				}
				col++;
			}
			j = update ? 0 : j + 1;
		}
	}
}

/*
**	Checking an array of links for a match at two index.
**	For example: links: push_swap - lib. rooms[i]: push_swap
**	rooms[j]: lib. Than we return (1); If we don't find matches
**	we return number of rooms + 1;
*/

static int		get_connections(int i, int j, t_lm_data *lem)
{
	int k;

	k = 0;
	while (lem->links[k])
	{
		if (ft_strstr(lem->links[k], lem->rooms[i]) &&
				ft_strstr(lem->links[k], lem->rooms[j]))
			return (1);
		k++;
	}
	return (lem->nb_rooms + 1);
}

/*
**	Create a matrix in which we indicate the presence of a
**	connection between rooms or absence.
*/

static int		**init_route(t_lm_data *lem)
{
	int	i;
	int	j;
	int	**connections;

	i = -1;
	if (!(connections = (int **)malloc(sizeof(int*) * lem->nb_rooms + 1)))
		return (NULL);
	while (++i < lem->nb_rooms)
	{
		j = -1;
		if (!(connections[i] = (int *)malloc(sizeof(int) * lem->nb_rooms + 1)))
		{
			free(connections);
			return (NULL);
		}
		while (++j < lem->nb_rooms)
		{
			if (i == j)
				connections[i][j] = 0;
			else
				connections[i][j] = get_connections(i, j, lem);
		}
	}
	distance(connections, lem->nb_rooms);
	return (connections);
}

/*
**	Filling in the structure of the t_node data of the rooms.
**	For example: index = 1; rooms = push_swap; col = 10; row = 10;
*/

static t_node	*init_nodes(t_lm_data *lem)
{
	int		i;
	t_node	*rooms;

	i = 0;
	if (!(rooms = (t_node*)malloc(sizeof(t_node) * lem->nb_rooms)))
		return (NULL);
	while (i < lem->nb_rooms)
	{
		rooms[i].index = i;
		rooms[i].name = ft_strdup(lem->rooms[i]);
		add_coordinates(lem->rooms[i]);
		rooms[i].col = ft_atoi(&lem->rooms[i][first_coord(lem->rooms[i])]);
		rooms[i].row = ft_atoi(&lem->rooms[i][second_coord(lem->rooms[i])]);
		i++;
	}
	remove_coordinates(lem);
	return (rooms);
}

int				path_finding(char **map, t_lm_data *lem)
{
	t_node	*rooms;
	int		**route;
	int		nb_solutions;
	t_array	**solutions;
	t_array cmds;

	if (!(rooms = init_nodes(lem)))
		return (-1);
	if (!(route = init_route(lem)))
		return (-1);
	if ((nb_solutions = run_pathfinder(route, &solutions, rooms, lem)) == 0)
	{
		ft_free_nodes(rooms, lem->nb_rooms, -1);
		return (ft_free_int_tab(route, lem->nb_rooms, -1));
	}
	cmds = INIT_ARRAY(char);
	solutions_to_cmds(solutions, &cmds, lem->nb_ants, nb_solutions);
	ft_print_tab(map);
	ft_print_solutions(cmds, rooms, lem);
	free_sols_and_cmds(solutions, cmds, nb_solutions);
	ft_free_nodes(rooms, lem->nb_rooms, 0);
	ft_free_int_tab(route, lem->nb_rooms, 0);
	return (0);
}
