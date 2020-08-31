/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:38:02 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/31 12:55:11 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int		init_struct(t_lm_data *lem, char **map)
{
	lem->nb_ants = 0;
	if ((lem->nb_rooms = count_rooms(map)) == -1)
		return (-1);
	lem->nb_links = count_links(map);
	lem->start = NULL;
	lem->end = NULL;
	if ((lem->rooms = (char **)malloc(sizeof(char *) * lem->nb_rooms + 1)) == NULL)
		return (-1);
	lem->rooms[lem->nb_rooms] = 0;
	if ((lem->links = (char **)malloc(sizeof(char *) * lem->nb_links +1)) == NULL)
	{
		ft_clear_table(lem->rooms);
		return (-1);
	}
	lem->links[lem->nb_links] = 0;
	return (0);
}

static int		check_empty_line(char *file)
{
	int i;

	i = 0;
	if (!file)
		return (-1);
	while (file[i++])
	{
		if (file[i] == '\n' && file[i + 1] == '\n')
			return (-1);
		else if (file[i] == '\n' && ft_isspace(file[i + 1]) && ft_isspace(file[i + 2]))
			return (-1);
		i++;
	}
	return (0);
}

static char		**check_and_save_map(char *file)
{
	char **map;

	if (file && check_empty_line(file) == -1)
	{
		free(file);
		return (NULL);
	}
	else if (file)
	{
		map = ft_strsplit(file, '\n');
		free(file);
		return (map);
	}
	return (NULL);
}

static char		**read_map(int fd_map)
{
	int		byte;
	char	*file;
	char	buf[BUFF_SIZE + 1];

	file = ft_strnew(0);
	while ((byte = read(fd_map, &buf, BUFF_SIZE)) > 0)
	{
		buf[byte] = '\0';
		file = ft_strjoin(file, buf);
	}
	return (check_and_save_map(file));
}

int				main(int argc, char **argv)
{
	char		**map;
	int			fd_map;
	t_lm_data	*lem;

	if ((fd_map = open(argv[argc - 1], O_RDONLY)) == -1)
	{
		ft_putstr_fd("ERROR\n", 2);
		return (-1);
	}
	if ((map = read_map(fd_map)) == NULL)
	{
		ft_putstr_fd("ERROR\n", 2);
		return (-1);
	}
	if (init_struct(&lem, map) == -1)
	{
		ft_putstr_fd("ERROR\n", 2);
		ft_clear_table(map);
		return (-1);
	}
	parse(map, &lem);
	return (0);
}