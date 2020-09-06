/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:55:50 by jconcent          #+#    #+#             */
/*   Updated: 2020/09/06 12:19:49 by jconcent         ###   ########.fr       */
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
	ft_printf("**********\n");
	ft_printf("ЗДЕСЬ ПРЕДСТАВЛЕНА МАТРИЦА СОЕДИНЕНИЙ! 1 - наличие соединения, а 9 - отсутствие\n");
	for (int i = 0; i < lem->nb_rooms; i++)
	{	
		ft_printf("%d: ", i);
		for (int j = 0; j < lem->nb_rooms; j++)
			ft_printf("%3d", connections[i][j]);
		ft_printf("\n");
	}
	ft_printf("**********\n");
	ft_printf("\n\n");
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

	(void)map;
	if (!(rooms = init_nodes(lem)))
		return (-1);
	if (!(route = init_route(lem)))
		return (-1);
	ft_printf("**********\n");
	ft_printf("ЗДЕСЬ ПРЕДСТАВЛЕНА МАТРИЦА СОЕДИНЕНИЙ С ВЫЧЕСЛЕНЫМИ РАССТОЯНИМИ. 1 - прямое соединение, иная цифра - количество переходов\n");
	for (int i = 0; i < lem->nb_rooms; i++)
	{	
		ft_printf("%d: ", i);
		for (int j = 0; j < lem->nb_rooms; j++)
			ft_printf("%3d", route[i][j]);
		ft_printf("\n");
	}
	ft_printf("**********\n");
	return (0);
}