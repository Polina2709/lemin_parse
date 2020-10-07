/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:22:42 by jconcent          #+#    #+#             */
/*   Updated: 2020/10/07 10:09:41 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		rt_error(char *str, int key)
{
	ft_putstr_fd(str, key);
	return (-1);
}

int		ft_free_int_tab(int **tab, int size, int status)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (status);
}

int		ft_free_nodes(t_node *rooms, int size, int status)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(rooms[i].name);
		i++;
	}
	free(rooms);
	return (status);
}

void	free_sols_and_cmds(t_array **sols, t_array cmds, int nb_sols)
{
	int i;

	i = 0;
	while (i < nb_sols)
	{
		ft_array_clear(sols[i]);
		free(sols[i]);
		i++;
	}
	ft_array_clear(&cmds);
	free(sols);
}
