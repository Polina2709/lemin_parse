/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/31 13:04:44 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/31 13:04:45 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lem_in.h"

int check_ants(t_lm_data *lem, char **map)
{
    while (map != '\n')
    {
        if (!(map < '9' && map > '0'))
        {
            ft_putstr_fd("ERROR\n", 2); // я бы предпочёл заморочиться ошибками по итогу, но если будет время и желание - изучи strerror и perror
            return (-1);
        }
        else
            lem->nb_ants = lem->nb_ants * 10 + (int)map;
        map++;
    }
    if (!(lem->nb_ants > 0 && lem->nb_ants < 2147483648))
    {
	    ft_putstr_fd("ERROR\n", 2);
	    return (-1);
    }
    return (0);
}

int check_rooms(t_lm_data *lem, char **map)
{
	int i;

	i = 0;
	if (lem->start == NULL || lem->end == NULL)
		return (-1);
	while(lem->rooms)
	{
		if (lem->rooms[i++][0] == 'L')
			return (-1);
	}
	return (0);
}

 int record_rooms(t_lm_data *lem, char **map)
{
	int i;
	int count_room;

	i = 1;
	count_room = 0;
	while(map[i])
	{
		if (ft_strequ(map[i], "##start\n")) ////  \n не лишний?
		{
			lem->start = map[++i];
			lem->rooms[count_room++] = map[i++];
		}
		else if (ft_strequ(map[i], "##end\n"))  ////  \n не лишний?
		{
			lem->end = map[++i];
			lem->rooms[count_room++] = map[i++];
		}
		else if (map[i][0] == '#' && map[i][1] != '#')
			i++;
		else if (ft_strchr(map[i], '-') != NULL && ft_strchr(map[i], ' ') == NULL)
			break;
		else if (ft_strchr(map[i], '#') == NULL)
			lem->rooms[count_room++] = map[i++];
	}
	return (0);
}

int get_data(char **map, t_lm_data *lem)
{
	if (check_ants(lem, map) == -1)
		return (-1);
	record_rooms(lem, map);
	if (check_rooms(lem, map) == -1)
		return (-1);
	record_links(lem, map);

	if (count_rows(map) != (lem->nb_rooms + lem->nb_links + lem->nb_comments + 3)) //// 3= ants + start + end
		return (-1);
	return (0);
}

int	parse(char **map, t_lm_data *lem)
{
	if (get_data(map, lem) == -1)	//Эта функция должна заполнять структуру данными. По её завершению комнаты, линки, и прочее заполнены. Одновременно с заполнением - проверяем на валидность
		return (-1);
/*	if (check_coordinates(lem) == -1)	//Проверяем валидность координат. ПРосто чтобы они были нормы записаны в карту
		return (-1);
	if (!lem->start || !lem->end || !ft_tablen(lem->rooms) || !ft_tablen(lem->links))
		return (-1);
	remove_coordinates(lem); // избавляемся от координат просто поставив '\0' после названия комнаты в каждой комнате
	if (check_identical_rooms(lem) == -1) //ищем одинаковые комнаты
		return (-1);
	if (check_first_link(lem) == -1) //проверяем чтобы в ссылке первая комната существовала
		return (-1);
	if (check_second_link(lem) == -1) //проверяем чтобы в ссылке вторая комната существовала
		return (-1);*/
	return (0);
}
