/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 19:12:47 by hbally            #+#    #+#             */
/*   Updated: 2018/11/17 18:42:24 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	void	*ret;

	ret = (void*)malloc(size);
	if (ret == NULL)
		return (NULL);
	while (size > 0)
	{
		*(unsigned char*)(ret + size - 1) = 0;
		size--;
	}
	return (ret);
}
