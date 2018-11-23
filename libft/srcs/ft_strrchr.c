/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:38:02 by hbally            #+#    #+#             */
/*   Updated: 2018/11/14 10:34:01 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t		len;
	int			i;

	len = ft_strlen(s);
	i = len;
	if (s[i] == '\0' && (char)c == '\0')
		return ((char*)&s[i]);
	while (--i >= 0)
		if (s[i] == (char)c)
			return ((char*)&s[i]);
	return (NULL);
}
