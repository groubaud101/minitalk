/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:48:14 by groubaud          #+#    #+#             */
/*   Updated: 2021/06/12 12:17:54 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int	ft_aff_di(t_printf *ptr, int len_uint, int nb)
{
	int		len;

	len = ft_the_max(2, len_uint, ptr->precis) + (nb < 0)
		- (nb == 0 && ptr->precis == 0);
	if (ptr->minus != 1)
	{
		if (ptr->zero == 1)
		{
			if (nb < 0)
				ft_putchar('-');
			while (ptr->field > len++)
				ft_putchar('0');
		}
		else
		{
			while (ptr->field > len++)
				ft_putchar(' ');
			if (nb < 0)
				ft_putchar('-');
		}
	}
	else
		while (ptr->field > len++)
			ft_putchar(' ');
	return (1);
}

int	ft_aff_uxx(t_printf *ptr, int len_uint, int exist)
{
	int		len;

	len = ft_the_max(2, len_uint, ptr->precis) - exist;
	if (ptr->minus != 1)
	{
		if (ptr->zero == 1)
			while (ptr->field > len++)
				ft_putchar('0');
		else
			while (ptr->field > len++)
				ft_putchar(' ');
	}
	else
		while (ptr->field > len++)
			ft_putchar(' ');
	return (1);
}

int	ft_aff_p(t_printf *ptr, int len, unsigned long long n)
{
	int		i;
	char	c;

	c = ' ';
	if (ptr->zero == 1)
		c = '0';
	i = ft_the_max(2, ptr->precis, ptr->field)
		+ (ptr->precis == 0 && n == 0);
	if (ptr->minus == 1)
	{
		if (ptr->zero != 1)
			ft_putstr("0x");
		if (!(ptr->precis == 0 && n == 0))
			ft_put_ulonglong_base(n, "0123456789abcdef");
	}
	while (i > 0 && i-- > len)
		ft_putchar(c);
	if (ptr->minus != 1)
	{
		if (ptr->zero != 1)
			ft_putstr("0x");
		if (!(ptr->precis == 0 && n == 0))
			ft_put_ulonglong_base(n, "0123456789abcdef");
	}
	return (ft_the_max(3, ptr->precis, ptr->field, len));
}

int	ft_aff_s(t_printf *ptr, const char *str)
{
	int		len;
	int		i;

	len = ft_strlen(str);
	if (ptr->precis > -1 && !(ptr->field > -1 && ptr->precis == -1))
		len = ft_the_min(2, ft_strlen(str), ptr->precis);
	i = ptr->field;
	if (ptr->minus == 1)
		write(1, str, len);
	while (i-- > len)
		ft_putchar(' ');
	if (ptr->minus != 1)
		write(1, str, len);
	return (ft_the_max(2, len, ptr->field));
}
