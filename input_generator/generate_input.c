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
#include <stdio.h>
#define SIZE 4

void	make_tetromino(int matrix[][4], char tetromino[])
{	
	int j;

	j = 0;
	while (j < 16)
	{
		if (matrix[j / 4][j % 4] == 1)
			tetromino[j] = '#';
		else
			tetromino[j] = '.';
		j++;
	}	
}

/*
** This function has a bug with pieces shaped like this :
**   #
**  ###
** 50% of the time it will make this one, otherwise it will make
** another random pieces so this function is biased and the output
** map will reflect this :/
*/
void		placepixel(int matrix[][4], int position[], int r, int c)
{
	int 	move;

	while ((r == position[0] && c == position[1]) || matrix[r][c] == 1)
	{	
		move = arc4random_uniform(4);
		if (move == 0)
			r += r == 3 ? 0 : 1;
		if (move == 1)
			r -= r == 0 ? 0 : 1;
		if (move == 2)
			c += c == 3 ? 0 : 1;
		if (move == 3)
			c -= c == 0 ? 0 : 1;
	}

	matrix[r][c] = 1;
}

void	make_matrix(int matrix[][4])
{
	int		i;
	int		r;
	int		c;
	int		startpos;
	int		seed;
	int		position[2];
	
	ft_bzero(matrix, sizeof(int) * 16);

	startpos = arc4random_uniform(16);
	r = startpos / 4;
	c = startpos % 4;

	matrix[r][c] = 1;
	seed = arc4random_uniform(5);

	i = 1;
	while (i < SIZE)
	{
		if (!(seed == 0 && i == 2)) // SPECIAL CASE
		{
			position[0] = r;
			position[1] = c;
		}
		placepixel(matrix, position, r, c);
		i ++;
	}
}

int		main(int argc, char **argv)
{
	int		i1;
	int 	i2;
	char	tetromino[16];
	int		matrix[4][4];
	int		size;
	
	argc = 0;
	i1 = 0;
	size = ft_atoi(argv[1]);

	while (i1++ < size)
	{
		make_matrix(matrix);
		make_tetromino(matrix, tetromino);
		i2 = 0;
		while (i2 < 16)
		{
			ft_putchar(tetromino[i2]);
			if (++i2 % 4 == 0)
				ft_putchar('\n');
		}
		if (i1 != size)
			ft_putchar('\n');
	}

	return (0);	
}
