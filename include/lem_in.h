/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:38:31 by jconcent          #+#    #+#             */
/*   Updated: 2020/09/10 14:23:32 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/include/libft.h"

/*
**	TO DO LIST
**	1: Реализовать функцию get_data
**	2: Реализовать функцию check_coordinates
**	3: Реализовать функцию remove_coordinates
**	4: Реализовать фуннкцию check_identical_rooms
**	5: Реализовать функцию check_fisrt_link
**	6: Реализовать функцию check_second_link
**	7: Убедиться что всё работает :D
**	8: Убедиться, что в рамках этих функций ничто не течёт (valgrind)
**	9: Написать make
*/

typedef struct	s_lm_data
{
	int		i;
	int		r;
	int		l;
	int		nb_ants;
	int		nb_rooms;
	int		nb_links;
	char	*start;
	char	*end;
	char	**rooms;
	char	**links;
}				t_lm_data;

typedef struct s_room
{
    char    *name;
    int     x;
    int     y;
 //   unsigned int visited;
    struct s_room *next;
    struct s_room *previous;
    struct s_room **link;            // **
}              t_room;

typedef struct s_ant
{
    int     count;
    int     number;
    int     x;
    int     y;
}              t_ant;

typedef struct	s_node
{
	int		index;
	char	*name;
	int		col;
	int 	row;
}				t_node;

int				ft_count_rooms(char **map);
int				count_spaces(char *line);
int				ft_count_links(char **map);
int				get_ant_nb(char **map, t_lm_data *lem);
int				get_start_get_end(char **map, t_lm_data *lem, int s_e);
int				get_room_get_link(char *line, t_lm_data *lem, int r_l);
int				check_coordinates(t_lm_data *lem);
void			remove_coordinates(t_lm_data *lem);
int				check_identical_rooms(t_lm_data *lem);
int				check_first_link(t_lm_data *lem);
int				check_second_link(t_lm_data *lem);
int				parse(char **map, t_lm_data *lem);
void			add_coordinates(char *room);
int				first_coordinates(char *room);
int				second_coordinates(char *room);
int				path_finding(char **map, t_lm_data *lem);
int				free_int_tab(int **tab, int size, int status);
int				free_nodes(t_node *rooms, int size, int status);

#endif
