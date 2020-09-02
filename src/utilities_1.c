/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 12:56:05 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/31 12:56:40 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int count_rows(char **map)
{
	int i;

	i = 0;
	while(map[i])
		i++;
	return (i);
}

int count_comments(t_lm_data *lem, char **map)
{
	int i;

	i = 0;
	while(map[i])
	{
		if (map[i][0] == '#' && map[i][1] != '#')
			lem->nb_comments++;
		i++;
	}
	return (0);
}

int	count_spaces(char *line)
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

int	ft_count_links(char **map)
{
	int i;
	int links;

	i = 0;
	links = 0;
	while (map[i])
	{
		if (map[i][0] != '#' && (count_spaces(map[i]) == 0) && ft_strchr(map[i], '-'))  /// может ли комната быть связана сама с собой
			links++;
		i++;
	}
	return (links);
}

int	ft_count_rooms(char **map)
{
	int i;
	int rooms;

	i = 0;
	rooms = 0;
	while (map[i])
	{
		if (map[i][0] != '#' && count_spaces(map[i]) == 2)  /// тогда будем считать, что комната "Big room" невалидна?
			////  а если тут будут коряво указаны линки с пробелами, по типу "А - В". тоже не с #, но при этом 2 пробела, тогда комнат больше покажет. (мб это потом проверяется, просто пишу сразу  мысли)
			rooms++;
		else if (map[i][0] != '#' && (count_spaces(map[i]) == 1 || count_spaces(map[i]) > 2)) //// если 0 пробелов это чтобы пропустило с количеством муравьев, я так понимаю,  а если будет просто название комнаты без координат, то тогда он не вылетит.
		/// также вопрос. Комнаты с одинаковыми названиями это норм?
			return (-1);
		i++;
	}
	return (rooms);
}