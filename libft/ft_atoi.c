/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:23:20 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/01 17:23:20 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	extreme_value(int neg)
{
	if (neg == -1)
		return (0);
	return (-1);
}

int	ft_atoi(const char *nbr)
{
	int		index;
	int		neg;
	long	nb;
	long	limit;

	index = 0;
	nb = 0;
	neg = 1;
	while (ft_isspace(nbr[index]) == 1)
		index++;
	if (nbr[index] == '+' || nbr[index] == '-')
		if (nbr[index++] == '-')
			neg = -1;
	limit = LONG_MAX / 10;
	while (ft_isdigit(nbr[index]) == 1)
	{
		if (nb > limit)
			return (extreme_value(neg));
		nb = (nb * 10) + (nbr[index] - '0');
		if (nb < 0)
			return (extreme_value(neg));
		index++;
	}
	return ((int)(nb * neg));
}
