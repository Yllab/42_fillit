/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:06:16 by hbally            #+#    #+#             */
/*   Updated: 2018/11/14 10:32:40 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	i;

	if (s != 0)
	{
		ret = ft_strnew(len);
		if (ret == NULL)
			return (NULL);
		i = 0;
		while (i < len)
		{
			ret[i] = s[start + i];
			i++;
		}
		return (ret);
	}
	return (NULL);
}
