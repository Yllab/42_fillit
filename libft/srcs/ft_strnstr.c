/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 17:54:53 by hbally            #+#    #+#             */
/*   Updated: 2018/11/14 15:40:50 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	size_t			len_haystack;
	size_t			len_needle;

	i = 0;
	if (!needle[i] && !haystack[i])
		return ((char*)haystack);
	len_needle = ft_strlen(needle);
	len_haystack = ft_strlen(haystack);
	while (haystack[i] && i < len && len_needle <= len - i)
	{
		if (ft_strncmp(&haystack[i], needle, len_needle) == 0)
			return ((char*)&haystack[i]);
		i++;
	}
	return (NULL);
}
