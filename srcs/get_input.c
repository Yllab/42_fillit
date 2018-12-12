/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 16:27:47 by hbally            #+#    #+#             */
/*   Updated: 2018/12/12 12:58:51 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int				get_input(const int fd, t_tetros *tetros)
{
	char		buf[22];
	int			count;
	int			i;
	char		check;
	char		*tmp;

	i = 0;
	check = 0;
	while ((count = read(fd, buf, 21)))
	{
		if (count < 20 || check_counts(buf, count) != 0 ||
			!(tmp = remove_lines(buf)))
		  return (0);
		tetros->tab[i] = convert_tetro(tmp);
		tetros->size = i + 1;
		free(tmp);
		check = count;
		if (i++ > 25)
			return (0);
	}
	if (check != 20)
		return (0);
	return (1);
}
