/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 11:11:32 by hbally            #+#    #+#             */
/*   Updated: 2018/11/13 12:37:44 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t			len;
	unsigned int	i;
	unsigned int	j;

	len = ft_strlen(s1);
	i = 0;
	j = len;
	while (s2[i])
		s1[j++] = s2[i++];
	s1[j] = '\0';
	return (s1);
}
