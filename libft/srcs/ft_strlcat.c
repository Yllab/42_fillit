/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 18:47:35 by hbally            #+#    #+#             */
/*   Updated: 2018/11/15 13:46:02 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = 0;
	i = 0;
	if (size)
	{
		while (dst[len] && len < size)
			len++;
		while (src[i] && len + i < size - 1)
		{
			dst[len + i] = src[i];
			i++;
		}
		if (len + i < size)
			dst[len + i] = '\0';
	}
	return (len + ft_strlen(src));
}
