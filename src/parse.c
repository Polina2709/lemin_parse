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

int check_ants(char **map, t_ant *ants)
{
    ants->count = 0;

    while (**map != '\n')
    {
        if (!(**map < '9' && **map > '0'))
        {
            ft_putstr_fd("ERROR\n", 2); // я бы предпочёл заморочиться ошибками по итогу, но если будет время и желание - изучи strerror и perror
            return (-1);
        }
        else
            ants->count = ants->count * 10 + (int)**map;
        **map++;
    }
    if (!(ants->count > 0 && ants->count < 2147483648))
    {
	    ft_putstr_fd("ERROR\n", 2);
	    return (-1);
    }
    return (0);
}

int	parse(char **map, t_lm_data *lem)
{
	if (get_data(map, lem) == -1)	//Эта функция должна заполнять структуру данными. По её завершению комнаты, линки, и прочее заполнены. Одновременно с заполнением - проверяем на валидность
		return (-1);
	if (check_coordinates(lem) == -1)	//Проверяем валидность координат. ПРосто чтобы они были нормы записаны в карту
		return (-1);
	if (!lem->start || !lem->end || !ft_tablen(lem->rooms) || !ft_tablen(lem->links))
		return (-1);
	remove_coordinates(lem); // избавляемся от координат просто поставив '\0' после названия комнаты в каждой комнате
	if (check_identical_rooms(lem) == -1) //ищем одинаковые комнаты
		return (-1);
	if (check_first_link(lem) == -1) //проверяем чтобы в ссылке первая комната существовала
		return (-1);
	if (check_second_link(lem) == -1) //проверяем чтобы в ссылке вторая комната существовала
		return (-1);
	return (0);
}
