/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:16:53 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/24 12:27:40 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 16000
# define GNL_CONTENT(x) ((t_file*)((x->content)))->content
# define GNL_START(x) ((t_file*)((x->content)))->content_start

typedef struct	s_file
{
	int			fd;
	char		*content;
	char		*content_start;
}				t_file;

int				get_next_line(int fd, char **line);

#endif
