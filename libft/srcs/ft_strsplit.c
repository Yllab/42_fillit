/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:35:00 by hbally            #+#    #+#             */
/*   Updated: 2018/11/16 14:59:55 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

static	size_t		ft_tabsize(char const *s, char c)
{
	unsigned int	i;
	size_t			counter;

	i = 0;
	counter = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			counter++;
		i++;
	}
	return (counter);
}

static	char		**ft_tabfree(char **tab, int i)
{
	while (i--)
	{
		free(tab[i]);
		tab[i] = NULL;
	}
	free(tab);
	tab = NULL;
	return (NULL);
}

static	char		**ft_tabfill(char **tab, char const *s, char c)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	j;

	size = 0;
	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			size++;
			if (s[i + 1] == c || s[i + 1] == '\0')
			{
				if ((tab[j++] = ft_strnew((size_t)size)) == NULL)
					return (ft_tabfree(tab, j - 1));
				ft_strncpy(tab[j - 1], &s[i - size + 1], size);
				size = 0;
			}
		}
		i++;
	}
	return (tab);
}

char				**ft_strsplit(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (NULL);
	tab = (char**)ft_memalloc(sizeof(char*) * (ft_tabsize(s, c) + 1));
	if (!tab)
		return (NULL);
	tab = ft_tabfill(tab, s, c);
	if (!tab)
		return (NULL);
	return (tab);
}
