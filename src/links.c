

#include "lem_in.h"

int record_links(t_lm_data *lem, char **map)
{
	int i;
	int count_links;

	i = 1;
	count_links = 0;
	while (ft_strchr(map[i], ' ') != NULL || ft_strchr(map[i], '#') != NULL)
		i++;
	while (map[i])
		lem->links[count_links++] = map[i++];
	if (count_links != lem->nb_links) /// мб и лишнее, но пока вижу в этом логику
		return (-1);
	return (0);
}


