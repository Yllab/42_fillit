/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:15:55 by hbally            #+#    #+#             */
/*   Updated: 2018/11/13 19:40:41 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned int	i;

	i = 0;
	if (dst >= src)
		while (--len + 1 != 0)
			*(unsigned char*)(dst + len) = *(unsigned char*)(src + len);
	else
		while (i++ < len)
			*(unsigned char*)(dst + (i - 1)) = *(unsigned char*)(src + (i - 1));
	return (dst);
}
