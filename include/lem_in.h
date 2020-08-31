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
	int nb_ants;
	int nb_rooms;
	int nb_links;
	char *start;
	char *end;
	char **rooms;
	char **links;
}				t_lm_data;

typedef struct s_room
{
    char    *name;
    int     x;
    int     y;
    unsigned int visited;
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

#endif
