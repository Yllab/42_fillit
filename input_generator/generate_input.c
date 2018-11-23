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

/*
** To print our tetromino (represented as 16 bits, for instance
**
** 0000
** 1100
** 0110
** 0000
** 
** or on the same line :
**
** 0000 1100 0110 0000
**
** We'll loop on it using a reference, whose initial value is 
** 0000 0000 0000 0001
** 
** If any bit is set to '1' at the same position in both numbers, we print '#'
**
** (In the second iteration of the loop, ref << 2 returns
** 0000 0000 0000 0010
** then ref << 3 returns
** 0000 0000 0000 0100
** ... until
** 0000 0000 0010 0000 > here we print '#' (see above)
*/

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

/*
** Here we're taking a fresh tetromino as parameter (any of the 13 possible
** shapes), and moving it randomly to another possible position on the 4x4 grid.
** [For the randomizing function, man 3 arc4random.]
** In the first block we want to know how many blank rows are 'under' our piece,
** and shift the piece downwards by a random amount within that space.
** If the first if(..) triggers, there are 3 blank rows available.
** (which is only possibe with the '####' piece).
** (Here 0xF00 = 0000 1111 0000 0000 -- if any bit in our tetromino 
** on the 2nd nibble from the left is set to 1, the condition is false)
** We'll shift the piece downwards
** by moving all the bits to the right 4 times, and repeat 1 or 2 times depending
** on the random function output (if output is zero the piece doesn't move).
** In the second block we check the blank columns to the right of the piece,
** and shift to the right in the same fashion.
** 
*/

unsigned short	make_tetromino(unsigned short tetromino)
{
	if (!(tetromino & 0xF00))
		tetromino = tetromino >> arc4random_uniform(4) * 4;
	else if (!(tetromino & 0xF0))
		tetromino = tetromino >> arc4random_uniform(3) * 4;
	else if (!(tetromino & 0xF))
		tetromino = tetromino >> arc4random_uniform(2) * 4;
	
	if (!(tetromino & 0x4444))
		tetromino = tetromino >> arc4random_uniform(4);
	else if (!(tetromino & 0x2222))
		tetromino = tetromino >> arc4random_uniform(3);
	else if (!(tetromino & 0x1111))
		tetromino = tetromino >> arc4random_uniform(2);

	return (tetromino);
}

/*
** Here the tetrominoes[] array contains the 13 different seeds at the top-most,
** left-most position, written in hexadecimal notation for convenience.
*/

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

	// Fluff
	if (argc == 1)
	{
		ft_putstr("Usage : ./input_generator [-w] [size]");
		ft_putstr("\n-w    : Same probability for the 5 base shapes");
		ft_putstr("\nsize  : The amount of tetrominoes to generate\n");
	}
	// More fluff
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

