/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:07:00 by hbally            #+#    #+#             */
/*   Updated: 2018/11/26 12:17:51 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_free(t_short *tetro, int pos, t_short field[], int size)
{
	int i;

	if ((pos % size + 4 >= size && tetro & 0x1111 << 3 - (size - pos % size)) ||
		(pos / size + 4 >= size && tetro & 15 << 4 * (3 - (size - pos / size))))
		return (0);	
	i = 0;
	while (i <= 3 && pos / size + i != size)
	{
		if ((tetro & 0xF000 >> 4 * i) >> pos % size & field[i])
			return (0);
		i++;
	}
	return (1);
}

static void	place_tetro(t_short *tetro, int pos, t_short field[], int size)
{
	int 	i;

	i = 0;
	while (i <= 3 && pos / size + i != size)
	{
		field[i] += tetro & 0xF000 >> 4 * i >> pos % size;
		i++;
	}
}

//TODO Remove redundancy
static int	remove_tetro(t_short *tetro, int pos, t_short field[], int size)
{
	int 	i;

	i = 0;
	while (i <= 3 && pos / size + i != size)
	{
		field[i] -= tetro & 0xF000 >> 4 * i >> pos % size;
		i++;
	}
}

int			move_tetros(t_short *tetro, t_short field[], int size)
{
	int		pos;

	if (!*tetro)
		return (1);
	else
	{
		pos = 0;
		while (pos < size * size)
		{
			print_field(field);
			if (is_free(tetro, pos, &field[pos / size], size))
			{
				place_tetro(tetro, pos, &field[pos / size], size);
				if (move_tetros(tetro + 1, field, size))
				{
					// + add to result string
					return (1);
				}
				remove_tetro(tetro, pos, &field[pos / size], size);
			}
			pos++;
		}
		return (0);
	}
}
