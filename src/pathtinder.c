/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathtinder.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:24:49 by jconcent          #+#    #+#             */
/*   Updated: 2020/09/19 09:50:59 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/* Эту функцию надо перенести в другой файл, делал тут чтобы было удобней)
*/
t_array	**append_solutions(t_array **sols, int nb_sols, t_array sol)
{
	t_array **temp;

	if ((temp = (t_array**)malloc(sizeof(t_array*) * nb_sols + 1)) == NULL)
		return (sols);
	if (nb_sols > 0)
	{
		ft_memcpy(temp, sols, sizeof(t_array*) * nb_sols);
		free(sols);
	}
	sols = temp; 
	if ((sols[nb_sols] = (t_array*)malloc(sizeof(t_array))) == NULL)
		return (sols);
	ft_memcpy(sols[nb_sols], &sol, sizeof(t_array));
	if ((sols[nb_sols]->data = (int*)malloc(sizeof(int) * sol.size)) == NULL)
		return (sols);
	ft_memcpy(sols[nb_sols]->data, sol.data, sizeof(int) * sol.size);
	return (sols);
}

/* Эту функцию надо перенести в другой файл, делал тут чтобы было удобней)
*/
int		turns_counter(t_array **sols, int nb_ants, int n)
{
	int col;
	int row;
	int c;
	int off;
	int end;

	if (n == 0)
		return (0);
	row = 0;
	c = -1;
	while (row != -1)
	{
		col = -1;
		off = 1;
		end = 1;
		while (++col < nb_ants)
		{
			off = (col % n == 0) ? off - 1 : off;
			if ((off + row) >= 0 && ((off + row) <= (int)sols[col % n]->size - 1) && end)
				end = 0;
		}
		row = end ? -1 : row + 1;
		c++;
	}
	return (c);
}

int in_solutions(t_array *sol, int node)
{
	int i;

	i = 0;
	while (i < (int)sol->size)
	{
		if (CONTENT_ARRAY(sol, i) == node)
			return (1);
		i++;
	}
	return (0);
}

int get_min_path(int **routetab, int size, int row, int end)
{
	int col;
	int min;
	int node;

	col = 0;
	min = size + 1;
	node = size;
	while (col < size)
	{
		if (routetab[row][col] == 1 && routetab[col][end] < min)
		{
			min = routetab[end][col];
			node = col;
		}
		col++;
	}
	return (node);
}

int pathfinder(int ***routetab, int size, t_array *sol, int end)
{
	int node;

	node = get_min_path(*routetab, size, CONTENT_ARRAY(sol, sol->size - 1), end);
	if (node == end)
	{
		if (sol->size == 1)
			(*routetab)[CONTENT_ARRAY(sol, sol->size -1)][end] = size + 1;
		ft_array_add(sol, &node, 1);
		return (1);
	}
	while (node < size && (*routetab)[end][node] < size + 1 && !in_solutions(sol, node))
	{
		(*routetab)[CONTENT_ARRAY(sol, sol->size - 1)][end] = size + 1;
		ft_array_add(sol, &node, 1);
		(*routetab)[end][node] = size + 1;
		if (pathfinder(routetab, size, sol, end))
			return (1);
		ft_array_pop(sol, 1);
		node = get_min_path(*routetab, size, CONTENT_ARRAY(sol, sol->size - 1), end);	
	}
	return (0);
}

int	get_nodes_index(t_node *rooms, t_lm_data *lem, char *name)
{
	int i;

	i = 0;
	while (i < lem->nb_rooms)
	{
		if (ft_strequ(rooms[i].name, name))
			break ; 
		i++;
	}
	return (rooms[i].index);
}

int	run_pathfinder(int **route, t_array ***solutions, t_node *r, t_lm_data *lem)
{
	t_array	sols;
	int		nb_sols;
	int		turns;
	int		start;

	sols = INIT_ARRAY(int);
	nb_sols = 0;
	turns = 0;
	start = get_nodes_index(r, lem, lem->start);
	ft_array_add(&sols, &start, 1);
	while (pathfinder(&route, lem->nb_rooms, &sols, get_nodes_index(r, lem, lem->end)))
	{
		*solutions = append_solutions((*solutions), nb_sols++, sols);
		if (turns_counter((*solutions), lem->nb_ants, nb_sols) > turns && turns != 0)
		{
			ft_array_clear((*solutions)[--nb_sols]);
			free((*solutions)[nb_sols]);
		}
		turns = turns_counter((*solutions), lem->nb_ants, nb_sols);
		ft_array_clear(&sols);
		sols = INIT_ARRAY(int);
		ft_array_add(&sols, &start, 1);
	}
	ft_array_clear(&sols);
	return (nb_sols);
}