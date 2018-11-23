/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:08:21 by hbally            #+#    #+#             */
/*   Updated: 2018/11/14 19:11:33 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nb, int fd)
{
	unsigned int abs_nb;

	if (nb >= 0)
		abs_nb = nb;
	else
	{
		abs_nb = nb * -1;
		ft_putchar_fd('-', fd);
	}
	if (abs_nb / 10 == 0)
		ft_putchar_fd((abs_nb % 10) + 48, fd);
	else
	{
		ft_putnbr_fd(abs_nb / 10, fd);
		ft_putnbr_fd(abs_nb % 10, fd);
	}
}
