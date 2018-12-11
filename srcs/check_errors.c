/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 15:49:41 by hbally            #+#    #+#             */
/*   Updated: 2018/12/11 16:40:07 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			print_error(char *str)
{
	ft_putendl(str);
	return (1);
}

int			check_links(char *str)
{
	int		block;
	int		i;

	block = 0;
	i = 0;
	while (i < 20)
	{
		if (str[i] == '#')
		{
			if ((i + 1) < 20 && str[i + 1] == '#')
				block++;
			if ((i - 1) >= 0 && str[i - 1] == '#')
				block++;
			if ((i + 5) < 20 && str[i + 5] == '#')
				block++;
			if ((i - 5) >= 0 && str[i - 5] == '#')
				block++;
		}
		i++;
	}
	return (block == 6 || block == 8);
}

int			check_counts(char *str, int count)
{
	int		i;
	int		blocks;

	blocks = 0;
	i = 0;
	while (i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && ++blocks > 4)
				return (1);
		}
		else if (str[i] != '\n')
			return (1);
		i++;
	}
	if (count == 21 && str[20] != '\n')
		return (1);
	if (!check_links(str))
		return (1);
	return (0);
}

char		*remove_lines(char *buf)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_strnew(sizeof(buf)); // necessary ?  
	if (str)
	{
		while (i < 16)
		{
			if (buf[j] != '\n')
			{
				str[i] = buf[j];
				i++;
				j++;
			}
			else
				j++;
		}
		str[i] = '\0';
		return (str);
	}
	return (NULL);
}
