/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 12:58:50 by jconcent          #+#    #+#             */
/*   Updated: 2020/10/07 10:25:39 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_prev_node(char **cmd, int i, int j, int start)
{
	char	**icmds;
	int		value;

	if (i == 0)
		return (start);
	else
	{
		icmds = ft_strsplit(cmd[i - 1], ' ');
		if (j >= ft_wordcounter(cmd[i - 1], ' '))
			j = 0;
		value = ft_atoi(icmds[j]);
		ft_clear_table(icmds);
		return (value);
	}
}

int		get_ind(t_node *rooms, t_lm_data *l, char *name)
{
	int i;

	i = 0;
	while (i < l->nb_rooms)
	{
		if (ft_strequ(rooms[i].name, name))
			break ;
		i++;
	}
	return (rooms[i].index);
}

char	*get_nodes_name(t_node *rooms, t_lm_data *l, int index)
{
	int i;

	i = 0;
	while (i < l->nb_rooms)
	{
		if (rooms[i].index == index)
			break ;
		i++;
	}
	return (rooms[i].name);
}
