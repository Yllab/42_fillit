/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrealloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:20:43 by hbally            #+#    #+#             */
/*   Updated: 2018/11/19 11:32:19 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memrealloc(void *old, size_t old_size, size_t new_size)
{
	unsigned int	i;
	void			*new;

	i = 0;
	new = (void*)ft_memalloc(new_size);
	if (!new || !old)
		return (NULL);
	ft_memcpy(new, old, old_size);
	free(old);
	old = NULL;
	return (new);
}
