/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:56:33 by hbally            #+#    #+#             */
/*   Updated: 2018/11/14 10:33:30 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int			i;
	int			j;
	size_t		len;
	char		*ret;

	if (s != 0)
	{
		len = ft_strlen(s);
		i = 0;
		j = (int)len - 1;
		while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			i++;
		while ((s[j] == ' ' || s[j] == '\t' || s[j] == '\n') && j)
			j--;
		ret = ft_strnew(s[i] != 0 ? j - i + 1 : 0);
		if (ret == NULL)
			return (NULL);
		ft_strncpy(ret, &s[i], s[i] != 0 ? j - i + 1 : 1);
		return (ret);
	}
	return (0);
}
