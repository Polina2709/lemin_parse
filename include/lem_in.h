/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:38:31 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/31 13:04:18 by jconcent         ###   ########.fr       */
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
	long int nb_ants; //// мб тут лонг инт сделать (есть мысля, если что объясню ВК)
	int nb_rooms;
	int nb_links;
	int nb_comments;
	char *start;
	char *end;
	char **rooms;
	long int x;
	long int y;
	char **links;
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
	int index;
	char *name;
	int col;
	int row;
}				t_node;



int				main(int argc, char **argv);
char		**read_map(int fd_map);
char		**check_and_save_map(char *file);
int		check_empty_line(char *file);
int		init_struct(t_lm_data *lem, char **map);

int	count_spaces(char *line);
int	ft_count_links(char **map);
int	ft_count_rooms(char **map);
int count_rows(char **map);
int count_comments(t_lm_data *lem, char **map);

int	parse(char **map, t_lm_data *lem);
int get_data(char **map, t_lm_data *lem);
int check_ants(t_lm_data *lem, char **map);

int record_rooms(t_lm_data *lem, char **map);
int check_rooms(t_lm_data *lem);
int check_space_in_rooms(t_lm_data *lem);

int record_links(t_lm_data *lem, char **map);


void remove_coordinates(t_lm_data *lem);


#endif
