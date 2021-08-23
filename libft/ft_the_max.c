/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_the_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:21:27 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/28 19:21:27 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_the_max(int size, ...)
{
	va_list	numbers;
	int		max;
	int		nb;
	int		i;

	i = 1;
	va_start(numbers, size);
	max = (int)va_arg(numbers, int);
	while (i < size)
	{
		nb = (int)va_arg(numbers, int);
		if (max < nb)
			max = nb;
		i++;
	}
	va_end(numbers);
	return (max);
}
