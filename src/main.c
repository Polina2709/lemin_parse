/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:38:02 by jconcent          #+#    #+#             */
/*   Updated: 2020/09/06 12:05:51 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

/*
**	Initializie all structure variables and allocate memmory
*/

static int		init_struct(t_lm_data *lem, char **map)
{
	lem->i = 0;
	lem->r = 0;
	lem->l = 0;
	lem->nb_ants = 0;
	if ((lem->nb_rooms = ft_count_rooms(map)) == -1)
		return (-1);
	lem->nb_links = ft_count_links(map);
	lem->start = NULL;
	lem->end = NULL;
	if ((lem->rooms = (char **)malloc(sizeof(char *) * lem->nb_rooms + 1)) == NULL)
		return (-1);
	lem->rooms[lem->nb_rooms] = 0;
	if ((lem->links = (char **)malloc(sizeof(char *) * lem->nb_links + 1)) == NULL)
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
	}
	return (0);
}

/*
**	We check that there are no empty lines and make matrix **map
*/

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

/*
**	Read from file descriptor and form one solid line
*/

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

/*
**	Open and read "file.map" -> write to the matrix **map ->
**	initialize struct t_lm_data -> fill the structure with data ->
**	and run the algorithm.
*/

int				main(int argc, char **argv)
{
	char		**map;
	int			fd_map;
	t_lm_data	lem;

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
	if (parse(map, &lem) == -1 || path_finding(map, &lem) == -1)
    {
        ft_putstr_fd("ERROR\n", 2);
        return (-1);
    }
	ft_printf("Выведем для начала карту: \nНАЧАЛО КАРТЫ\n");
	for (size_t i = 0; i < ft_tablen(map); i++)
		ft_printf("%s\n", map[i]);
	ft_printf("КОНЕЦ КАРТЫ\n");
	ft_printf("Количество муравьев: %d\nКоличество комнат: %d\nКомната старт: %s\nКомната end: %s\n", lem.nb_ants, lem.nb_rooms, lem.start, lem.end);
	ft_printf("Здесь будут комнаты: \n");
	for (int i = 0; i < lem.nb_rooms; i++)
		ft_printf("%d: %s\n", i, lem.rooms[i]);
	ft_printf("Здесь будут линки: \n");
	for (int i = 0; i < lem.nb_links; i++)
		ft_printf("%d: %s\n", i, lem.links[i]);
	return (0);
}