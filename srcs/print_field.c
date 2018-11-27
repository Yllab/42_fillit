/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_field.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 13:42:07 by hbally            #+#    #+#             */
/*   Updated: 2018/11/27 13:47:14 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// This function is for debug only

#include "fillit.h"
#include <stdio.h>

void				print_field(t_field *field)
{
	int	i;
	t_short ref;

	i = 0;
	while (i < 16)
	{	
		if (i < 10)
		printf("%d | ", i);
		else
		printf("%d| ", i);
		ref = 0x8000;
		while (ref)
		{
			if (field->tab[i] & ref)
				printf("# ");
			else
				printf(". ");
			ref /= 2;
		}
		printf("\n");
		i++;
	}
	printf("\n");	
}
