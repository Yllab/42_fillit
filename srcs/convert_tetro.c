/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tetro.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:28:40 by hbally            #+#    #+#             */
/*   Updated: 2018/11/24 20:20:06 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Converts a tetromino from char* representation to unsigned short
**
** Input for convert_tetro should be a null terminated string
** with strlen == 16 and containing only '#' or '.'
*/ 

static unsigned short	shift(unsigned short tetro)
{
	while (!(tetro & 0xF000))
		tetro = tetro << 4;
	while (!(tetro & 0x8888))
		tetro = tetro << 1;
	return (tetro);
}

unsigned short			convert_tetro(char *s)
{
	int 				i;
	unsigned short 		tetro;

	i = 0;
	tetro = 0x0;
	while (s[i])
	{
		if (s[i] == '#')
			ret += i == 15 ? 1 : 2 << (14 - i);
		i++;
	}
	return (shift(tetro));
}
