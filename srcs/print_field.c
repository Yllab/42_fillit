/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:42:07 by hbally            #+#    #+#             */
/*   Updated: 2018/11/27 14:53:41 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function is for debug only

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

void				print_field(t_field *field)
{
	int	i;
	t_short ref;
	t_short boundary;

	i = 0;
	boundary = 1;

	ft_putstr("\n");
	while (i < 16)
	{	
		ref = 0x8000;
		while (ref)
		{
			if (i < field->size)
			{
			if ((field->tab[i] & ref) && ref > (boundary << (15 - field->size)))
				ft_putstr("# ");
			else if ((field->tab[i] & ref) && ref <= (boundary << (15 - field->size)))
				ft_putstr("E ");
			else if (!(field->tab[i] & ref) && ref > (boundary << (15 - field->size)))
				ft_putstr(". ");
			else if (!(field->tab[i] & ref) && ref <= (boundary << (15 - field->size)))
				ft_putstr("| ");

			}
			else if (!(field->tab[i] & ref))
				ft_putstr("| ");
			else
				ft_putstr("E ");
			ref /= 2;
		}
		ft_putstr("\n");
		i++;
	}
	ft_putstr("\n");
}
