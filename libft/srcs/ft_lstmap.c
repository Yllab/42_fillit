/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 12:33:19 by hbally            #+#    #+#             */
/*   Updated: 2018/11/15 13:31:20 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ret;
	t_list	*iter;

	if (!lst || !f)
		return (NULL);
	iter = f(lst);
	if (!iter)
		return (NULL);
	ret = iter;
	while (lst)
	{
		lst = lst->next;
		iter->next = lst ? f(lst) : NULL;
		if (lst && !(iter->next))
			return (NULL);
		iter = iter->next;
	}
	return (ret);
}
