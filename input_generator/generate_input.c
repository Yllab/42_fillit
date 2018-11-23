/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 11:01:22 by hbally            #+#    #+#             */
/*   Updated: 2018/11/23 17:09:27 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void 	print(unsigned short tetromino)
{
	int i;
	unsigned short ref;

	i = 16;
	ref = 1;
	while (--i >= 0)
	{
		ft_putchar((tetromino & ref << i) != 0 ? '#' : '.');
		if (i % 4 == 0)
			ft_putchar('\n');
	}
}

unsigned short	make_tetromino(unsigned short tetromino)
{
	if (!(tetromino & 0x4444))
		tetromino = tetromino >> arc4random_uniform(4);
	else if (!(tetromino & 0x2222))
		tetromino = tetromino >> arc4random_uniform(3);
	else if (!(tetromino & 0x1111))
		tetromino = tetromino >> arc4random_uniform(2);
	
	if (!(tetromino & 0xF00))
		tetromino = tetromino >> arc4random_uniform(4) * 4;
	else if (!(tetromino & 0xF0))
		tetromino = tetromino >> arc4random_uniform(3) * 4;
	else if (!(tetromino & 0xF))
		tetromino = tetromino >> arc4random_uniform(2) * 4;

	return (tetromino);
}

int		main(int argc, char **argv)
{
	int				i;
   	unsigned short	tetrominoes[] =
	{
		0xF000, 0x8888, 0xCC00, 0xC600, 0x4C80, 0xC880, 0xE200,
		0x44C0, 0x8E00, 0xE400, 0x4C40, 0x4E00, 0x8C80
	};
	
	// Weighted Array (Same probability for each of the 5 shapes)
   	unsigned short	tetrominoes_weighted[] =
	{
		0xF000, 0xF000, 0x8888, 0x8888,	0xCC00, 0xCC00, 0xCC00, 0xCC00, 
		0xC600, 0xC600, 0x4C80, 0x4C80, 0xC880, 0xE200, 0x44C0, 0x8E00,
		0xE400, 0x4C40, 0x4E00, 0x8C80
	};

	if (argc == 1)
	{
		ft_putstr("Usage : ./input_generator [-w] [size]");
		ft_putstr("\n-w    : Same probability for the 5 base shapes");
		ft_putstr("\nsize  : The amount of tetrominoes to generate\n");
	}
	else if (!ft_strcmp(argv[1], "-w"))
	{
		i = ft_atoi(argv[2]);
		while (i-- > 0)
		{	
			print(make_tetromino(tetrominoes_weighted[arc4random_uniform(20)]));
			if (i)
				ft_putchar('\n');
		}
	}
	else
	{
		i = ft_atoi(argv[1]);
		while (i-- > 0)
		{
			print(make_tetromino(tetrominoes[arc4random_uniform(13)]));
			if (i)
				ft_putchar('\n');
		}	
	}
	return(0);
}

