/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:07:57 by hbally            #+#    #+#             */
/*   Updated: 2018/11/14 10:32:17 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*ret;
	unsigned int	i;

	if (s != 0 && f != 0)
	{
		ret = ft_strnew(ft_strlen(s));
		if (ret == NULL)
			return (NULL);
		i = 0;
		while (s[i])
		{
			ret[i] = f(i, s[i]);
			i++;
		}
		return (ret);
	}
	return (0);
}
