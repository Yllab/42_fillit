/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:27:44 by hbally            #+#    #+#             */
/*   Updated: 2018/11/28 17:52:14 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	//Does nothing
	if (argc)
		if(argv[argc] != NULL)
			return (0);

	unsigned short	tetro[] =
	{
	   	0,

		0xF000,
		0x8888,

		0xCC00,	

		0xC600,
		0x4C80, 

		0x6C00,
		0x8C40,

		0xC880,
		0xE200,
		0x44C0,
		0x8E00,

		0x88C0,
		0x2E00,
		0xC440, 
		0xE800,	

		0xE400, 
		0x4C40, 
		0x4E00, 
		0x8C80,
		
		0x88C0,
		0x2E00,
		0xC440, 
		0xE800,	
		0xC880,
		0xE200,
		0x44C0,

		0
	};

	move_tetros_pilot(tetro + 1);
	return 0;
}
