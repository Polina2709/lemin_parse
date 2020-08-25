/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:38:31 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/24 13:02:05 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/include/libft.h"

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

#endif