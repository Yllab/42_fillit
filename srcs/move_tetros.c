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

static int	is_free(t_short *tetro, t_short field[], int size)
{

	return (1);
}

int			move_tetros(t_short *tetro, t_short field[], int size)
{
	int		translate;

	if (!*tetro)
		return (1);
	else
	{
		translate = 0;
		while (translate < size * size)
		{
			if (is_free(tetro, translate, field, size))
			{
				place_tetro(tetro, translate, field, size);
				move_tetros(tetro + 1, field, size)
				//add to result string
				return (1);
			}
			else
			{
				translate++;
			}
		}
		return (0);
	}
}
