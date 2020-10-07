/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:56:05 by jconcent          #+#    #+#             */
/*   Updated: 2020/10/07 10:13:44 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	If if positive and it number - we got it.
*/

static int	check_valid_ants(char *line)
{
	if (line[0] == '-')
		return (0);
	else if (!ft_isint(line))
		return (0);
	else
		return (ft_atoi(line));
}

/*
**	Number of ants - is first line in the whole map.
**	It's only number without '#' and other char.
*/

int			get_ant_nb(char **map, t_lm_data *lem)
{
	int i;
	int nb_ants;

	i = -1;
	nb_ants = 0;
	while (map[i++])
	{
		if (ft_strequ(map[i], "##start") || ft_strequ(map[i], "##end"))
			return (-1);
		else if (map[i][0] == '#')
			;
		else
		{
			if (!(nb_ants = check_valid_ants(map[i])))
				return (-1);
			break ;
		}
	}
	if (map[i])
	{
		lem->i = i + 1;
		return (nb_ants);
	}
	else
		return (-1);
}

int			count_spaces(char *line)
{
	int i;
	int spaces;

	i = 0;
	spaces = 0;
	while (line[i])
	{
		if (ft_isspace(line[i]))
			spaces++;
		i++;
	}
	return (spaces);
}

/*
**	Links - is a line without spaces, not starting with '#' and have one '-'.
**	Other check will follow
*/

int			ft_count_links(char **map)
{
	int i;
	int links;

	i = 0;
	links = 0;
	while (map[i])
	{
		if (map[i][0] != '#' && (count_spaces(map[i]) == 0)
									&& ft_strchr(map[i], '-'))
			links++;
		i++;
	}
	return (links);
}

/*
**	Rooms - is a line with only two spaces and not starting with '#'.
**	Other checks will follow
*/

int			ft_count_rooms(char **map)
{
	int i;
	int rooms;

	i = 0;
	rooms = 0;
	while (map[i])
	{
		if (map[i][0] != '#' && count_spaces(map[i]) == 2)
			rooms++;
		else if (map[i][0] != '#' && (count_spaces(map[i]) == 1 ||
											count_spaces(map[i]) > 2))
			return (-1);
		i++;
	}
	return (rooms);
}
