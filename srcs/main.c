/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:56:51 by hbally            #+#    #+#             */
/*   Updated: 2018/11/28 17:35:49 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <fcntl.h>

int				main(int argc, char **argv)
{
	int 		fd;
	int			ret;
	t_short 	*tetro;

	fd = open(argv[1], O_RDONLY);
	tetro = get_input(fd);
	if (!tetro)
		print_error();
	if (move_tetros_pilot(tetro) == -1)
		print_error();
	return (0);
}
