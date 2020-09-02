

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
	return (0);
}
