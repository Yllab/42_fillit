/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetros_pilot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:02:47 by hbally            #+#    #+#             */
/*   Updated: 2018/12/12 12:41:48 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int					check_field(t_tetros *tetros)
{
	t_field			field;
	int				ret;

	field.size = upper_perfect_square(tetros->size * 4);
	bzero(&field, sizeof(t_short) * 16);
	while ((ret = check_tetro(tetros, &field, field.size)) == 0)
		field.size += 1;
	return (ret);
}
