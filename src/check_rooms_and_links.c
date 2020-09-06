/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_rooms_and_links.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 10:56:54 by jconcent          #+#    #+#             */
/*   Updated: 2020/09/06 11:53:13 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int check_second_link_c(char *second_link, t_lm_data *lem)
{
	int i;
	int stop;

	i = 0;
	stop = 0;
	while (lem->rooms[i])
	{
		if (ft_strequ(second_link, lem->rooms[i]))
			stop++;
		i++;
	}
	if (stop == 0)
		return (-1);
	return (0);
}

/*
**	Check that links have '-' between rooms and check second links to valid.
*/

int check_second_link(t_lm_data *lem)
{
	int i;
	int j;

	i = 0;
	while (lem->links[i])
	{
		j = 0;
		while (lem->rooms[j])
		{
			if (ft_strnequ(lem->rooms[j], lem->links[i], ft_strlen(lem->rooms[j])) && lem->links[i][ft_strlen(lem->rooms[j])] == '-')
				if (check_second_link_c(&lem->links[i][ft_strlen(lem->rooms[j]) + 1], lem) == -1)
					return (-1);
			j++;
		}
		i++;
	}
	return (0);
}

/*
**	We check that the link points to an existing room
*/

int check_first_link(t_lm_data *lem)
{
	int i;
	int j;
	int stop;

	i = 0;
	while (lem->links[i])
	{
		j = 0;
		stop = 0;
		while (lem->rooms[j])
		{
			if (ft_strnequ(lem->rooms[j], lem->links[i], ft_strlen(lem->rooms[j])))
				stop++;
			j++;
		}
		if (stop == 0)
			return (-1);
		i++;
	}
	return (0);
}

/*
**	We are looking for rooms with the same name
*/

int		check_identical_rooms(t_lm_data *lem)
{
	int i;
	int j;

	i = 0;
	while (lem->rooms[i])
	{
		j = 0;
		while (lem->rooms[j])
		{
			if (ft_strequ(lem->rooms[i], lem->rooms[j]) && i != j)
				return (-1);
			j++;
		}
		i++;
	}
	return (0);
}