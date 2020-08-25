/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jconcent <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 12:17:22 by jconcent          #+#    #+#             */
/*   Updated: 2020/08/24 12:21:39 by jconcent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*handle_file(t_list **files, int fd)
{
	t_list	*file;
	t_file	f;

	file = *files;
	while (file)
	{
		if (((t_file*)((file->content)))->fd == fd)
			return (file);
		file = file->next;
	}
	f.fd = fd;
	f.content = ft_strnew(1);
	f.content_start = f.content;
	ft_lstadd((files), ft_lstnew((void*)&f, sizeof(t_file)));
	return (*files);
}

char	*retrive_line(char **content)
{
	char	*line;
	size_t	len;

	if (ft_strchr(*content, '\n'))
	{
		len = ft_strchr(*content, '\n') - *content;
		line = ft_strncpy(ft_strnew(len), *content, len);
		*content += (len + 1);
	}
	else
	{
		len = ft_strlen(*content);
		line = ft_strncpy(ft_strnew(len), *content, len);
		*content += len;
	}
	return (line);
}

int		get_next_line(int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	size_t			ret;
	static t_list	*files;
	t_list			*file;

	if ((fd < 0 || line == NULL || read(fd, buf, 0) < 0) || BUFF_SIZE < 1)
		return (-1);
	file = handle_file(&files, fd);
	while ((ret = read(fd, buf, BUFF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(GNL_CONTENT(file) = ft_strjoin(GNL_CONTENT(file), buf)))
			return (-1);
		free(GNL_START(file));
		GNL_START(file) = GNL_CONTENT(file);
		if (ft_strchr(GNL_CONTENT(file), '\n'))
			break ;
	}
	if (ret < BUFF_SIZE && !ft_strlen(GNL_CONTENT(file)))
		return (0);
	if (!(*line = retrive_line(&GNL_CONTENT(file))))
		return (-1);
	return (1);
}
