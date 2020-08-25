/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:38:02 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/25 12:26:54 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
	int byte;
	char *file[2];
	char buf[BUFF_SIZE + 1];

	file[0] = ft_strnew(0);
	while ((byte = read(fd_map, &buf, BUFF_SIZE)) > 0)
	{
		buf[byte] = '\0';
		file[1] = file[0];
		file[0] = ft_strjoin(file[1], buf);
		free(file[1]);
	}
	return (check_and_save_map(buf));
}

int				main(int argc, char **argv)
{
	char **map;
	int fd_map;

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
	int i;

	i = 0;
	while (i < 234)
	{
		ft_printf("%s\n", map[i]);
		i++;
	}
	return (0);
}