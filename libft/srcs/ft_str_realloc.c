/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_realloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 19:15:59 by hbally            #+#    #+#             */
/*   Updated: 2018/11/15 19:16:00 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_str_realloc(char *old, size_t size)
{
	unsigned int	i;
	char			*new;

	if (old != NULL)
	{
		new = (char*)malloc(++size);
		if (new == NULL)
			return (NULL);
		i = 0;
		while (old[i] && i < size - 1)
		{
			new[i] = old[i];
			i++;
		}
		while (i++ < size)
			new[i - 1] = '\0';
		free(old);
		return (new);
	}
	return (NULL);
}
