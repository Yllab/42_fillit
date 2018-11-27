/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:07:00 by hbally            #+#    #+#             */
/*   Updated: 2018/11/27 15:30:50 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_free(t_short tetro, t_field *field, int col, int row)
{
	int i;

	i = 0;
	/*
	if (((col + 4 >= field->size &&
			tetro & 0x1111 << (3 - (field->size - col)))) ||
		(row + 4 >= field->size &&
		 	tetro & 0xF << 4 * (3 - (field->size - row))))
		return (0);	
	*/
	while (i <= 3 && row + i != field->size)
	{
		if (((tetro & (t_short)0xF000 >> 4 * i) >> col) &
				field->tab[row + i])
			return (0);
		i++;
	}
	return (1);
}

static void	update_field(t_short tetro, t_field *field, int col, int row)
{
	int 	i;
	

	i = 0;
	while (i <= 3 && row + i != field->size)
	{
		field->tab[row + i] ^= ((tetro & (0xF000 >> 4 * i)) >> col);
		i++;
	}
}

//DEBUG
#include <stdio.h>
int			move_tetros(t_short *tetro, t_field *field)
{
	int		pos;
	int		size;

	print_tetro(*tetro);
	printf("\n");

	size = field->size;
	if (!*tetro)
		return (1);
	else
	{
		pos = 0;
		while (pos < size * size)
		{
			if (is_free(*tetro, field, pos % size, pos / size))
			{
				update_field(*tetro, field, pos % size, pos / size);
				print_field(field);
				if (move_tetros(tetro + 1, field))
					return (1);
				else
					update_field(*tetro, field, pos % size, pos / size);
			}
			pos++;
		}
		return (0);
	}
}
