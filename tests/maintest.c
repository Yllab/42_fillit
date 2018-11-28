/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:27:44 by hbally            #+#    #+#             */
/*   Updated: 2018/11/28 12:01:00 by hbally           ###   ########.fr       */
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
	   	0x8888,
	   	0x8888,
	   	0x8888,
	   	0x8888,
	   	0xCC00,
		0x8888,
	   	0x8888,
	   	0
	};
	
	int size = 0;
	int i = 0;
	while (tetro[++i] != 0)
		size++;
	move_tetros_pilot(&tetro[1], size);

	return 0;
}
