/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 10:10:36 by hbally            #+#    #+#             */
/*   Updated: 2018/11/16 10:30:23 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_itoa(int n)
{
	size_t			len;
	char			*ret;
	unsigned int	neg;

	len = 0;
	neg = n < 0 ? 1 : 0;
	ret = ft_strnew(!neg ? len : ++len);
	if (ret == NULL)
		return (NULL);
	ret[0] = !neg ? 0 : '-';
	while (len == 0 ? !len : n != 0)
	{
		ret = ft_str_realloc(ret, ++len);
		if (ret == NULL)
			return (NULL);
		ft_memmove(&ret[!neg ? 1 : 2], !neg ? ret : &ret[1], len);
		ret[!neg ? 0 : 1] = '0' + (!neg ? (n % 10) : (-1 * (n % 10)));
		n /= 10;
	}
	return (ret);
}
