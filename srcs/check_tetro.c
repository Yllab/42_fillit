/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:06:36 by hbally            #+#    #+#             */
/*   Updated: 2018/12/11 16:27:05 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		update_field(t_short *tetro, t_field *field, int col, int row)
{
	int 		i;

	i = 0;
	while (i <= 3 && row + i != field->size)
	{
		field->tab[row + i] ^= (((*tetro & (0xF000 >> 4 * i)) << 4 * i) >> col);
		i++;
	}
}

static int		is_free(t_short *tetro, t_field *field, int col, int row)
{
	int 		i;

	i = 0;

	if (((col + 4 >= field->size &&
			*tetro & 0x1111 << (3 - (field->size - col)))) ||
		(row + 4 >= field->size &&
			*tetro & 0xF << 4 * (3 - (field->size - row))))
		return (0);	
	while (i <= 3 && row + i != field->size)
	{
		if ((((*tetro & 0xF000 >> 4 * i) << 4 * i) >> col) &
				field->tab[row + i])
			return (0);
		i++;
	}
	return (1);
}

int				check_tetro(t_short *tetro, t_field *field, int size)
{
	int			pos;

	if (*tetro == 0)
		return (1);
	else
	{
		pos = 0;
		while (pos < size * size)
		{
			if (is_free(tetro, field, pos % size, pos / size))
			{
				update_field(tetro, field, pos % size, pos / size);
				if (check_tetro(tetro + 1, field, size))
					return(fill_result(tetro, pos, size));
				update_field(tetro, field, pos % size, pos / size);
			}
			pos++;
		}
		return (0);
	}
}
