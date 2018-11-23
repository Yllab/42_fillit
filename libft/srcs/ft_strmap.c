/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 11:36:36 by hbally            #+#    #+#             */
/*   Updated: 2018/11/14 10:32:04 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
			ret[i] = f(s[i]);
			i++;
		}
		return (ret);
	}
	return (NULL);
}
