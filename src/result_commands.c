/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result_commands.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 11:22:17 by jconcent          #+#    #+#             */
/*   Updated: 2020/10/07 10:26:03 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	ft_print_solutions(t_array com, t_node *rooms, t_lm_data *lem)
{
	int		i;
	int		j;
	char	**cmds;
	char	**icmds;
	int		c;

	i = -1;
	cmds = ft_strsplit(((char*)com.data), '\n');
	while (cmds[++i])
	{
		icmds = ft_strsplit(cmds[i], ' ');
		j = -1;
		c = (i > 0) ? ft_printf("\n") : 0;
		while (++j < ft_wordcounter(cmds[i], ' '))
			if (get_prev_node(cmds, i, j, 1) != ft_atoi(icmds[j]) &&
				get_ind(rooms, lem, lem->start) != ft_atoi(icmds[j]))
			{
				(c++ != 1) ? ft_printf(" ") : 0;
				ft_printf("L%d-%s", j + 1,
							get_nodes_name(rooms, lem, ft_atoi(icmds[j])));
			}
		ft_clear_table(icmds);
	}
	ft_printf("\n");
	ft_clear_table(cmds);
}

#define LAST(A) sols[A]->size - 1

/*
**	Checking how many moves the ant will have to make
**	along this path.
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
			if ((off + row) >= 0 && ((off + row) <= (int)LAST(col % n)) && end)
				end = 0;
		}
		row = end ? -1 : row + 1;
		c++;
	}
	return (c);
}

void	solutions_to_cmds(t_array **sols, t_array *cmds, int nb_ants, int n)
{
	int		col;
	int		row;
	int		offset;
	char	*temp;

	row = -1;
	while (++row < turns_counter(sols, nb_ants, n))
	{
		col = -1;
		offset = 1;
		while (++col < nb_ants)
		{
			offset = (col % n == 0) ? offset - 1 : offset;
			if ((offset + row) < 0)
				temp = ft_itoa(((int*)sols[col % n]->data)[0]);
			else
				temp = ((offset + row) > (int)LAST(col % n)) ?
						ft_itoa(((int*)sols[col % n]->data)[LAST(col % n)]) :
						ft_itoa(((int*)sols[col % n]->data)[offset + row]);
			ft_array_add_space(cmds, temp);
			free(temp);
		}
		ft_array_add(cmds, "\n", 1);
	}
	ft_array_add(cmds, "\0", 1);
}
