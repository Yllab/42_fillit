/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetros_pilot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:07:05 by hbally            #+#    #+#             */
/*   Updated: 2018/11/27 14:54:35 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

static int			upper_perfect_square(int nb)
{
	int				i;
	int				ret;
	
	i = 1;
	ret = ft_sqrt(nb);
	while (!ret)
		ret = ft_sqrt(nb + i++);
	return (ret);
}

static void			field_init(t_field *field)
{
	int 			i;

	i = 0;
	
	while (i < 16)
		field->tab[i++] = 0;
}





//DEBUG
#include <stdio.h>
//
int					move_tetros_pilot(t_short *tetro, int tetro_count)
{
	t_field			field;

	field.size = upper_perfect_square(tetro_count * 4);
	field_init(&field);
	while(!move_tetros(tetro, &field))
	{
		field.size += 1;
		field_init(&field);
	}
	return (field.size);
}
