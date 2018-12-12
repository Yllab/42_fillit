/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:31:43 by hbally            #+#    #+#             */
/*   Updated: 2018/12/12 12:36:52 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				main(int argc, char **argv)
{
	t_tetros	tetros;
	int			fd;

	if (argc != 2)
		return (print_error("usage: ./fillit [input_file]"));
	fd = open(argv[1], O_RDONLY);
	if (!(get_input(fd, &tetros)))// ||
//			check_field(&tetros) == -1 ||
//			fd <= 0)
	{
		print_error("error");
		close(fd);
		return (0);
	}
	close(fd);
	return (0);
}
