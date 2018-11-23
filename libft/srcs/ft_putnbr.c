/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 11:14:38 by hbally            #+#    #+#             */
/*   Updated: 2018/11/14 19:07:47 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int nb)
{
	unsigned int abs_nb;

	if (nb >= 0)
		abs_nb = nb;
	else
	{
		abs_nb = nb * -1;
		ft_putchar('-');
	}
	if (abs_nb / 10 == 0)
		ft_putchar((abs_nb % 10) + 48);
	else
	{
		ft_putnbr(abs_nb / 10);
		ft_putnbr(abs_nb % 10);
	}
}
