/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetros_pilot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:07:05 by hbally            #+#    #+#             */
/*   Updated: 2018/11/26 12:09:56 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

//-------------------------------------------------------
//TODO Remove when debug is done
#include <stdio.h>
void				print_field(t_short field[])
{
	int	i;
	t_short ref;

	i = 0;
	while (i < 16)
	{	
		if (i < 10)
		printf("%d | ", i);
		else
		printf("%d| ", i);
		ref = 0x8000;
		while (ref)
		{
			if (field[i] & ref)
				printf("1 ");
			else
				printf("0 ");
			ref /= 2;
		}
		printf("\n");
		i++;
	}
	printf("\n");	
}

//-------------------------------------------------------

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

static void			field_init(t_short field[], int size)
{
	int 			i;

	i = 0;
	while (i < size)
		field[i++] = 0xFFFF >> size;
	while (i < 16)
		field[i++] = 0xFFFF;
}

int					move_tetros_pilot(t_short *tetro, int tetro_count)
{
	t_short	field[16];
	int				size;

	size = upper_perfect_square(tetro_count * 4);
	field_init(field, size);
	
	//DEBUG
	if (tetro == 0)
	print_field(field);

	while(!move_tetros(tetro, field, size))
	{
		size++;
		field_init(field, size);
	}
	return (size);
}
