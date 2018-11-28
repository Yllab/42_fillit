/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:42:07 by hbally            #+#    #+#             */
/*   Updated: 2018/11/28 17:41:06 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function is for debug only

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

void				print_field(t_field *field, t_short *tetro, int pos, int print_tetro)
{
	int	i;
	int j;
	int k;
	t_short iter;
	t_short ref;
	t_short boundary;
	t_short *tmp;
	char	*result;
	
	i = 0;
	j = 0;
	boundary = 1;
	result = ft_strnew(16 * 16);

	k = 0;
	tmp = tetro;
		
	while (*(++tmp) != 0)
		k++;
	k += print_tetro == 1 ? 1 : 2;
	ft_putstr("Tetros to place : "); ft_putnbr(k); ft_putstr("\n\n");
	while (i < 16)
	{	
		ref = 0x8000;
		while (ref)
		{
			if (i < field->size)
			{
			if ((field->tab[i] & ref) && ref > (boundary << (15 - field->size)))
				result[j] = '#';
			else if ((field->tab[i] & ref) && ref <= (boundary << (15 - field->size)))
				result[j] = 'E';
			else if (!(field->tab[i] & ref) && ref > (boundary << (15 - field->size)))
				result[j] = '.';
			else if (!(field->tab[i] & ref) && ref <= (boundary << (15 - field->size)))
				result[j] = ' ';
			}
			else if (!(field->tab[i] & ref))
				result[j] = ' ';
			else
				result[j] = 'E';
			j++;
			ref /= 2;
		}
		i++;
	}

	iter = 0x8000;
	while (iter > 0)
	{
		if (*tetro & iter)
			result[(pos / field->size) * 16 + pos % field->size] = print_tetro ? 'O' : 'X';
		pos += iter & 0x1111 ? field->size - 3: 1;
		iter /= 2;
	}

	int				len;

	i = 0;
	len = 16 * 16;
	while (i < len)
	{
		if (i % 16 == 0 && i / 16 < field->size)
			ft_putchar('\n');
		if (result[i] != ' ')
			ft_putchar(result[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
	ft_putchar('\n');
	getchar();
}
