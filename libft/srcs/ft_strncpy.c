/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:52:01 by hbally            #+#    #+#             */
/*   Updated: 2018/11/15 13:56:35 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (src_len < len)
	{
		while (i < len)
		{
			if (i < src_len)
				dst[i] = src[i];
			else
				dst[i] = '\0';
			i++;
		}
	}
	else
	{
		while (i < len && src[i])
		{
			dst[i] = src[i];
			i++;
		}
	}
	return (dst);
}
