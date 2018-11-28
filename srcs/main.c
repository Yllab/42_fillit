/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:56:51 by hbally            #+#    #+#             */
/*   Updated: 2018/11/28 16:38:44 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <fcntl.h>

int				main(int argc, char **argv)
{
	int 		fd;
	int			ret;
	int			count;
	t_short 	*tetro;

	fd = open(argv[1], O_RDONLY);
	tetro = get_input(fd, &tetro);
	if (!tetro)
	{
		print_error();
		return (0);
	}
	ret = move_tetros_pilot(

	return (0);
}
