/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:07:43 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/16 20:07:43 by groubaud         ###   ########.fr       */
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

static int	ft_check_atoi(const char *nbr, const char *base)
{
	int	index;
	int	len_base;

	index = 0;
	while (ft_isspace(nbr[index]) == 1)
		index++;
	if (nbr[index] == '+' || nbr[index] == '-')
		index++;
	if (ft_isinstr(nbr[index], base) == -1)
		return (0);
	len_base = ft_strlen(base);
	if (len_base < 2 || len_base > 16)
		return (0);
	index = 0;
	return (1);
}

int	ft_atoi_base_two(const char *nbr, const char *base, int index, int neg)
{
	int		len_base;
	int		c;
	long	nb;
	long	limit;

	nb = 0;
	limit = LONG_MAX / 10;
	len_base = ft_strlen(base);
	c = ft_isinstr(nbr[index], base);
	while (nbr[index] && c != -1)
	{
		if (nb > limit)
			return (extreme_value(neg));
		nb = (nb * len_base) + c;
		if (nb < 0)
			return (extreme_value(neg));
		index++;
		c = ft_isinstr(nbr[index], base);
	}
	return ((int)nb * neg);
}

int	ft_atoi_base(const char *nbr, const char *base)
{	
	int		index;
	int		neg;

	index = 0;
	neg = 1;
	if (ft_check_atoi(nbr, base) == 0)
		return (ATOI_ERROR);
	while (ft_isspace(nbr[index]) == 1)
		index++;
	if (nbr[index] == '+' || nbr[index] == '-')
		if (nbr[index++] == '-')
			neg = -1;
	return (ft_atoi_base_two(nbr, base, index, neg));
}
