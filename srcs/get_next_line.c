/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:37:23 by hbally            #+#    #+#             */
/*   Updated: 2018/11/24 16:16:52 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <unistd.h>
#include "libft.h"
#include "fillit.h"

static	int			ft_exit(int *n1, int *n2, int ret)
{
	*n1 = 0;
	*n2 = 0;
	return (ret);
}

static	int			ft_bufparse(char *buf, char **line, int fd)
{
	static int		i;
	static int		j;
	static int		size;
	static int		ret;

	if (i == 0)
		if ((ret = (int)read(fd, buf, BUFF_SIZE)) < 1)
			return (ft_exit(&j, &size, (ret == -1 ? -1 : 0 + *line[0] != 0)));
	while (buf[i] != '\n' && i < ret && i < BUFF_SIZE)
		(*line)[j++] = buf[i++];
	if (i == BUFF_SIZE && buf[i] != '\n')
	{
		size += BUFF_SIZE;
		*line = (char*)ft_memrealloc(*line, size + 1, size + BUFF_SIZE + 1);
		i = 0;
		if (!line)
			return (ft_exit(&j, &size, -1));
		return (ft_bufparse(buf, line, fd));
	}
	i = i < ret - 1 ? i + 1 : 0;
	return (ft_exit(&j, &size, 1));
}

int					get_next_line(const int fd, char **line)
{
	static char		*buf;
	int				ret;

	if (!buf)
		buf = (char*)ft_memalloc(BUFF_SIZE);
	if (line)
		*line = (char*)ft_memalloc(BUFF_SIZE + 1);
	if (!buf || !line || !*line || fd < 0)
	{
		if (buf)
			ft_memdel((void**)&buf);
		if (line && *line)
			ft_memdel((void**)line);
		return (-1);
	}
	ret = ft_bufparse(buf, line, fd);
	if (ret != 1)
	{
		ft_memdel((void**)&buf);
		ft_memdel((void**)line);
	}
	return (ret);
}
