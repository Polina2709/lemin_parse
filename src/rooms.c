#include "lem_in.h"

int check_space_in_rooms(t_lm_data *lem)
{
	int i;
	int count_rooms;
	int spaces;

	i = 0;
	count_rooms = 0;
	spaces = 0;
	while (lem->rooms[count_rooms])
	{
		while (lem->rooms[count_rooms][i])
		{
			if (lem->rooms[count_rooms][i++] == ' ')
				spaces++;
		}
		count_rooms++;
	}
	return (spaces == 2 ? 0 : -1);
}

int check_rooms(t_lm_data *lem)
{
	int i;

	i = 0;
	if (lem->start == NULL || lem->end == NULL)
		return (-1);
	while (lem->rooms)
	{
		if (lem->rooms[i][0] == 'L' || lem->rooms[i][0] == ' ')/// ' '? , мб  в record_rooms последняя строчка это проверят
			return (-1);
		i++;
	}
	return (0);
}

int record_rooms(t_lm_data *lem, char **map)  ///// а что если у комнаты название " 1". Нам надо, чтобы вылетало вроде
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
			lem->rooms[count_room++] = map[i++];//// мб тут и в end надо вместо \n \0 ставить
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
	if (count_room != lem->nb_rooms)
		return (-1);
	return (0);
}

int check_coordinates(t_lm_data *lem)  ////  не учитывает знак
{
	int i;
	int c_rooms;

	i = 0;
	c_rooms = 0;
	lem->x = 0;
	lem->y = 0;
	if (lem->rooms[c_rooms][i] != '+')
		i++;
	while (lem->rooms[c_rooms][++i] != ' ')
	{
		if ((lem->rooms[c_rooms][i] - '0' >= 0 && lem->rooms[c_rooms][i] - '0' <= 9) ||
		((lem->rooms[c_rooms][i] == '-' || lem->rooms[c_rooms][i] == '+') && lem->rooms[c_rooms][i - 1] == ' '))
			lem->x = lem->rooms[c_rooms][i] - '0';
		else
			return (-1);
	}
	while (lem->rooms[c_rooms][++i] != '\n')
	{
		if (lem->rooms[c_rooms][i] - '0' >= 0 && lem->rooms[c_rooms][i] - '0' <= 9)
			lem->y = lem->rooms[c_rooms][i] - '0';
		else
			return (-1);
	}
}