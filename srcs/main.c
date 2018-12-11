/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:31:43 by hbally            #+#    #+#             */
/*   Updated: 2018/12/11 16:47:36 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int argc, char **argv)
{
	t_short		tetro[27];
	int			fd;

	// check_tetro|check_field expect tetro to start and end with a 0
	if (argc != 2)
		return (print_error("usage: ./fillit [input_file]"));
	fd = open(argv[1], O_RDONLY); // check for open() return ?
	if (!(get_input(fd, tetro)) || check_field(tetro) == -1)
	{
		print_error("error");
		close(fd);
		return (0);
	}
	close(fd);
	return (0);
}
