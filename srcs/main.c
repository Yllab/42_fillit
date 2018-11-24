/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:56:51 by hbally            #+#    #+#             */
/*   Updated: 2018/11/24 19:58:08 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <fcntl.h>

int		main(int argc, char **argv)
{
	argc = 0;
	int fd;
	fd = open(argv[1], O_RDONLY);
	char *line;
	while (get_next_line(fd, &line))
		ft_putstr(line);
	return (0);
}
