/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_tetro.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 17:28:50 by hbally            #+#    #+#             */
/*   Updated: 2018/11/24 17:29:07 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Our tetro is represented as 16 bits, for instance
**
** 0000         							   ....
** 1100           >>  0000 1100 0110 0000 >>   ##..
** 0110										   .##.
** 0000										   ....
**
** We'll loop on it using a reference, whose initial value is 
** 1000 0000 0000 0000
** 
** If any bit is set to '1' at the same position in both numbers, we print '#'
**
** (In the second iteration of the loop, control is
** 0100 0000 0000 0000
** then next iteration control is
** 0010 0000 0000 0000
** ... until
** 0000 1000 0010 0000 > here we print '#' and keep going
*/

void 	print_tetro(unsigned short tetro)
{
	unsigned short control;

	control = 0x8000;
	while (control > 0)
	{
		ft_putchar(tetro & control ? '#' : '.');
		if (control & 0x1111)
			ft_putchar('\n');
		control /= 2;
	}
}
