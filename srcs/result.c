/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   result.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:57:58 by hbally            #+#    #+#             */
/*   Updated: 2018/12/12 15:32:38 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void			print_result(char *result, int size)
{
	int				len;
	int				i;

	i = 0;
	len = size * size;
	while (i < len)
	{
		if (i > 0 && i % size == 0)
			ft_putchar('\n');
		if (!result[i])
			ft_putchar('.');
		else
			ft_putchar(result[i]);
		i++;
	}
	ft_putchar('\n');
	ft_strdel(&result);
}

int					fill_result(t_tetros *tetros,
								int current,
								int pos,
								int field_size)
{
	static char		*result;
	t_short			iter;

	if (!result)
	{
		result = ft_strnew(field_size * field_size);
		if (!result)
			return (-1);
	}
	iter = 0x8000;
	while (iter > 0)
	{
		if (tetros->tab[current] & iter)
			result[pos] = 'A' + current;
		pos += iter & 0x1111 ? field_size - 3 : 1;
		iter /= 2;
	}
	if (current == 0)
		print_result(result, field_size);
	return (1);
}
