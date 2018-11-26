/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 09:28:50 by hbally            #+#    #+#             */
/*   Updated: 2018/11/26 09:30:27 by hbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int min;
	int mid;
	int max;

	mid = 0;
	min = 0;
	max = nb;
	if (nb <= 0)
		return (0);
	while (max - min > 1)
	{
		mid = (min + max) / 2;
		if (mid * mid == nb)
			return (mid);
		else if (mid * mid > nb || mid > 46340)
			max = mid;
		else
			min = mid;
	}
	return (0);
}
