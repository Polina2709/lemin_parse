/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:55:50 by jconcent          #+#    #+#             */
/*   Updated: 2020/09/19 09:50:45 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
					ft_printf("%d %d %d \n", i, j, col);
					route[i][col] = route[j][col] + route[i][j];
					update = 1;
				}
				col++;
			}
			j = update ? 0 : j + 1;
		}
	}
}

static int		get_connections(int i, int j, t_lm_data *lem)
{
	int k;

	k = 0;
	while (lem->links[k])
	{
		if (ft_strstr(lem->links[k], lem->rooms[i]) && ft_strstr(lem->links[k], lem->rooms[j]))
			return (1);
		k++;
	}
	return (lem->nb_rooms + 1);
}

static int		**init_route(t_lm_data *lem)
{
	int i;
	int j;
	int **connections;

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
		rooms[i].col = ft_atoi(&lem->rooms[i][first_coordinates(lem->rooms[i])]);
		rooms[i].row = ft_atoi(&lem->rooms[i][second_coordinates(lem->rooms[i])]);
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

	(void)map;
	if (!(rooms = init_nodes(lem)))
		return (-1);
	if (!(route = init_route(lem)))
		return (-1);
	if ((nb_solutions = run_puthfinder(route, &solutions, rooms, lem)) == 0)
	{
		free_nodes(rooms, lem->nb_rooms, -1); // эта функция будет в файле free
		return (free_int_tab(route, lem->nb_rooms, -1)); // эта тоже
	}
	return (0);
}