/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/24 16:27:44 by hbally            #+#    #+#             */
/*   Updated: 2018/11/24 20:00:32 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc)
		if(argv[argc] != NULL)
			return (0);

	print_tetro(convert_tetro("#...#...#...#..."));
}
