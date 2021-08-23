/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_no_overflow.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/16 18:13:33 by user42            #+#    #+#             */
/*   Updated: 2021/08/13 17:59:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	ft_atoi_no_overflow(const char *nbr)
{
	int	index;
	int	neg;
	int	nb;
	int	limit;

	index = 0;
	nb = 0;
	neg = 1;
	while (ft_isspace(nbr[index]) == 1)
		index++;
	if (nbr[index] == '+' || nbr[index] == '-')
		if (nbr[index++] == '-')
			neg = -1;
	limit = INT_MAX / 10;
	while (ft_isdigit(nbr[index]) == 1)
	{
		if (nb > limit)
			return (0);
		nb = (nb * 10) + (nbr[index] - '0');
		if (nb < 0)
			if (!(nb == INT_MIN && neg == -1))
				return (0);
		index++;
	}
	return ((int)(nb * neg));
}
