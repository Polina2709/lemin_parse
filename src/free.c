/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 14:22:42 by jconcent          #+#    #+#             */
/*   Updated: 2020/09/19 09:40:20 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		free_int_tab(int **tab, int size, int status)
{
	int i;
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			free(tab[i][j]);
			j++;
		}
		i++;
	}
	free(tab);
}

int	free_nodes(t_node *rooms, int size, int status)
{
	int i;
	i = 0;
	while (i < size)
	{
		free(rooms[i].name);
		i++;
	}
	free(rooms);
}