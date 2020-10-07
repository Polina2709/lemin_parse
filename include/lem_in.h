/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:38:31 by jconcent          #+#    #+#             */
/*   Updated: 2020/10/07 10:30:25 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/include/libft.h"

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

typedef struct	s_node
{
	int		index;
	char	*name;
	int		col;
	int		row;
}				t_node;

/*
** utilities_1.c
*/

int				ft_count_rooms(char **map);
int				count_spaces(char *line);
int				ft_count_links(char **map);
int				get_ant_nb(char **map, t_lm_data *lem);

/*
** parse.c
*/

int				parse(char **map, t_lm_data *lem);

/*
** utilities_2.c
*/

int				get_start_get_end(char **map, t_lm_data *lem, int s_e);
int				get_room_get_link(char *line, t_lm_data *lem, int r_l);
void			ft_array_add_space(t_array *self, char *data);
void			ft_print_tab(char **tab);

/*
** coord.c
*/

int				check_coordinates(t_lm_data *lem);
void			remove_coordinates(t_lm_data *lem);
void			add_coordinates(char *room);
int				first_coord(char *room);
int				second_coord(char *room);

/*
** check_rooms_and_links.c
*/

int				check_identical_rooms(t_lm_data *lem);
int				check_first_link(t_lm_data *lem);
int				check_second_link(t_lm_data *lem);

/*
**	path_finding.c
*/

int				path_finding(char **map, t_lm_data *lem);

/*
** pathfinder.c
*/

int				run_pathfinder(int **route, t_array ***sol,
									t_node *r, t_lm_data *lem);

/*
**	free.c
*/

int				ft_free_nodes(t_node *rooms, int size, int status);
int				ft_free_int_tab(int **tab, int size, int status);
void			free_sols_and_cmds(t_array **sols, t_array cmds, int nb_sols);
int				rt_error(char *str, int key);

/*
**	route.c
*/

int				get_prev_node(char **cmd, int i, int j, int start);
char			*get_nodes_name(t_node *rooms, t_lm_data *l, int index);
int				get_ind(t_node *rooms, t_lm_data *l, char *name);

/*
**	result_commands.c
*/

void			ft_print_solutions(t_array com, t_node *rooms, t_lm_data *lem);
void			solutions_to_cmds(t_array **sols, t_array *cmds,
												int nb_ants, int n);
int				turns_counter(t_array **sols, int nb_ants, int n);

#endif
