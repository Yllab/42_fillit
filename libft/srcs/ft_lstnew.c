/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:05:15 by hbally            #+#    #+#             */
/*   Updated: 2018/11/15 10:59:41 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ret;

	ret = (t_list*)malloc(sizeof(t_list));
	if (ret)
	{
		if (content && content_size)
		{
			ret->content = (void*)malloc(content_size);
			if (ret->content)
			{
				ret->content_size = content_size;
				ft_memmove(ret->content, content, content_size);
			}
		}
		else
		{
			ret->content = NULL;
			ret->content_size = 0;
		}
		ret->next = NULL;
	}
	return (ret);
}
