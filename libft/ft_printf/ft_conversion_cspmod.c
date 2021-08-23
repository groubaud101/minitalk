/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_csp.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 21:13:22 by groubaud          #+#    #+#             */
/*   Updated: 2021/06/12 12:33:31 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_conv_c(t_printf *ptr, va_list params)
{
	char	c;
	int		i;

	c = (unsigned char)va_arg(params, int);
	i = 1;
	if (ptr->minus == -1)
	{
		while (i++ < ptr->field)
			ft_putchar(' ');
		ft_put_uchar(c);
	}
	else
	{
		ft_put_uchar(c);
		while (i++ < ptr->field)
			ft_putchar(' ');
	}
	ptr->ret += i - 1;
	return (1);
}

static int	ft_conv_s(t_printf *ptr, va_list params)
{
	const char	*str;

	str = (const char *)va_arg(params, const char *);
	if (str == NULL)
		str = "(null)";
	ptr->ret += ft_aff_s(ptr, str);
	return (1);
}

static int	ft_conv_p(t_printf *ptr, va_list params)
{
	unsigned long long	nb;

	nb = (unsigned long long)va_arg(params, void *);
	if (ptr->zero == 1)
		ft_putstr("0x");
	ptr->ret += ft_aff_p(ptr, ft_len_ulonglong_base(nb, 16) + 2, nb);
	return (1);
}

int	ft_conv_mod(t_printf *ptr)
{
	char	c;
	int		i;

	c = ' ';
	if ((ptr->minus <= 0 && (ptr->precis > 0 && ptr->zero == 0))
		|| ptr->zero == 1)
		c = '0';
	i = 1;
	if (ptr->minus == -1)
		while (i++ < ptr->field)
			ft_putchar(c);
	ft_putchar('%');
	if (ptr->minus != -1)
		while (i++ < ptr->field)
			ft_putchar(c);
	ptr->ret += i - 1;
	return (1);
}

int	ft_conversion(t_printf *ptr, va_list params)
{
	int	(*tab[8])(t_printf *ptr, va_list params);

	tab[0] = &ft_conv_c;
	tab[1] = &ft_conv_s;
	tab[2] = &ft_conv_p;
	tab[3] = &ft_conv_di;
	tab[4] = &ft_conv_di;
	tab[5] = &ft_conv_u;
	tab[6] = &ft_conv_x;
	tab[7] = &ft_conv_xup;
	return (tab[ptr->num_conv](ptr, params));
}
