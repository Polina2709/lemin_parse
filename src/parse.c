#include "lem_in.h"

/*
**	Смотрим сколько всего у нас дано связок. Надо пройти по всей карте и посчитать количество строк которые не начинаются со знака '#'
**	и в которых есть знак '-' и в которых нет пробелов.
*/

int	count_links(char **map)
{

}

/*
**	Смотрим сколько нам данно комнат. Проходим по карте и считаем сколько строк соответствуют условиям: не начинается на '#', имеет всего 2 пробела
**
*/

int	count_rooms(char **map)
{

}

/*
**	Муравьи должны пройти несколько чеков: не должно быть минуса, количество должно не выходить за рамки MAXINT и должно быть вообще числом. Потом через 
**	ft_atoi просто вносим куда надо
*/

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
    return (0);
}

/*int find_start(char **map, t_room *rooms)
{
    int i;

    i = 1;
    while (map[i])
    {
        if (ft_strcmp(map[i], "##start\n") == 0)
        {

        }
    }
}
*/

int parse(char **map)
{
    t_room   *rooms;
    t_ant    *ants;

    rooms = NULL;
    check_ants(map, ants);

    return (0);
}
