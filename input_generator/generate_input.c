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
#include "generate_input.h"
#include <stdlib.h>

/*
** Here we're taking a fresh tetro as parameter (any of the 13 possible
** shapes), and moving it randomly to another possible position on the 4x4 grid.
** [For the randomizing function, man 3 arc4random.]
** In the first block we want to know how many blank rows are 'under' our piece,
** and shift the piece downwards by a random amount within that space.
** If the first if(..) triggers, there are 3 blank rows available.
** (which is only possibe with the '####' piece).
** (Here 0xF00 = 0000 1111 0000 0000 -- if any bit in our tetro 
** on the 2nd nibble from the left is set to 1, the condition is false)
** We'll shift the piece downwards
** by moving all the bits to the right 4 times, and repeat 1 or 2 times depending
** on the random function output (if output is zero the piece doesn't move).
** In the second block we check the blank columns to the right of the piece,
** and shift to the right in the same fashion.
** 
*/

unsigned short	make_tetro(unsigned short tetro)
{
	if (!(tetro & 0xF00))
		tetro = tetro >> arc4random_uniform(4) * 4;
	else if (!(tetro & 0xF0))
		tetro = tetro >> arc4random_uniform(3) * 4;
	else if (!(tetro & 0xF))
		tetro = tetro >> arc4random_uniform(2) * 4;
	
	if (!(tetro & 0x4444))
		tetro = tetro >> arc4random_uniform(4);
	else if (!(tetro & 0x2222))
		tetro = tetro >> arc4random_uniform(3);
	else if (!(tetro & 0x1111))
		tetro = tetro >> arc4random_uniform(2);

	return (tetro);
}

/*
** Here the tetros[] array contains the 13 different seeds at the top-most,
** left-most position, written in hexadecimal notation for convenience.
*/

int		main(int argc, char **argv)
{
	int				i;
   	unsigned short	tetros[] =
	{
		0xF000, 0x8888, 0xCC00, 0xC600, 0x4C80, 0xC880, 0xE200,
		0x44C0, 0x8E00, 0xE400, 0x4C40, 0x4E00, 0x8C80
	};
	
	// Weighted Array (Same probability for each of the 5 shapes)
   	unsigned short	tetros_weighted[] =
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
		ft_putstr("\nsize  : The amount of tetros to generate\n");
	}
	// More fluff
	else if (!ft_strcmp(argv[1], "-w"))
	{
		i = ft_atoi(argv[2]);
		while (i-- > 0)
		{	
			print_tetro(make_tetro(tetros_weighted[arc4random_uniform(20)]));
			if (i)
				ft_putchar('\n');
		}
	}
	else
	{
		i = ft_atoi(argv[1]);
		while (i-- > 0)
		{
			print_tetro(make_tetro(tetros[arc4random_uniform(13)]));
			if (i)
				ft_putchar('\n');
		}	
	}
	return(0);
}

