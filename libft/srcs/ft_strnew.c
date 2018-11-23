/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 10:35:48 by hbally            #+#    #+#             */
/*   Updated: 2018/11/13 12:49:56 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*ret;

	ret = (char*)malloc(size + 1);
	if (ret == NULL)
		return (NULL);
	else
	{
		while (size > 0)
		{
			ret[size] = '\0';
			size--;
		}
		ret[size] = '\0';
		return (ret);
	}
}
