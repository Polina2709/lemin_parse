#include "lem_in.h"

int check_ants(char **map, t_ant *ants)
{
    ants->count = 0;

    while (**map != '\n')
    {
        if (!(**map < '9' && **map > '0'))
        {
            ft_putstr_fd("ERROR\n", 2); // можем писать не просто эррор, а в чем именно. Сразу как бонус. или в лог файл все кидать
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