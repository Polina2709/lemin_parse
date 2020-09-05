#include "lem_in.h"

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

void remove_coordinates(t_lm_data *lem)
{
	int i;
	int count_rooms;

	i = 0;
	count_rooms = 0;
	while (lem->rooms[count_rooms])
	{
		while (lem->rooms[count_rooms][i] != ' ')
			i++;
		lem->rooms[count_rooms][i] = '\0';
		count_rooms++;
		i = 0;
	}
}