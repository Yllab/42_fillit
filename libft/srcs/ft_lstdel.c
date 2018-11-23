/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 10:59:56 by hbally            #+#    #+#             */
/*   Updated: 2018/11/15 12:20:23 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*iter;
	t_list	*holder;

	if (alst && *alst && del)
	{
		iter = *alst;
		while (iter)
		{
			holder = iter->next;
			if (iter->content)
				del(iter->content, iter->content_size);
			free(iter);
			iter = holder;
		}
		*alst = NULL;
	}
}
