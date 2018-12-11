/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tetro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:28:40 by hbally            #+#    #+#             */
/*   Updated: 2018/12/11 15:46:35 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static t_short	shift(t_short tetro)
{
	while (!(tetro & 0xF000))
		tetro = tetro << 4;
	while (!(tetro & 0x8888))
		tetro = tetro << 1;
	return (tetro);
}

t_short			convert_tetro(char *s)
{
	int			i;
	t_short		tetro;

	i = 0;
	tetro = 0x0;
	while (s[i])
	{
		if (s[i] == '#')
			tetro += (i == 15) ? 1 : 2 << (14 - i);
		i++;
	}
	return (shift(tetro));
}
