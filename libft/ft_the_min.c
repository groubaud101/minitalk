/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_the_min.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 21:45:28 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/28 21:45:28 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>

int	ft_the_min(int size, ...)
{
	va_list	numbers;
	int		min;
	int		nb;
	int		i;

	i = 1;
	va_start(numbers, size);
	min = (int)va_arg(numbers, int);
	while (i < size)
	{
		nb = (int)va_arg(numbers, int);
		if (min > nb)
			min = nb;
		i++;
	}
	va_end(numbers);
	return (min);
}
