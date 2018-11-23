/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:10:00 by hbally            #+#    #+#             */
/*   Updated: 2018/11/14 10:31:48 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	i;
	unsigned int	j;
	char			*ret;

	if (s1 != 0 && s2 != 0)
	{
		i = 0;
		j = 0;
		ret = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (ret == NULL)
			return (NULL);
		while (s1[i])
		{
			ret[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			ret[i + j] = s2[j];
			j++;
		}
		return (ret);
	}
	return (NULL);
}
