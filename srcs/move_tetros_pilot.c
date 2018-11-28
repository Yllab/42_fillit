/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tetros_pilot.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 10:07:05 by hbally            #+#    #+#             */
/*   Updated: 2018/11/27 17:11:52 by hbally           ###   ########.fr       */
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

int					move_tetros_pilot(t_short *tetro, int tetro_count)
{
	t_field			field;
	int				ret;

	field.size = upper_perfect_square(tetro_count * 4);
	bzero(&field, sizeof(t_short) * 16);
	while((ret = move_tetros(tetro, &field, field.size)) == 0)
		field.size += 1;
	return (ret);
}
