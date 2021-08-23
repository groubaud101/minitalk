/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conversion_diuxx.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 21:11:37 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/28 21:11:37 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_conv_di(t_printf *ptr, va_list params)
{
	int				nb;
	unsigned int	u_nb;
	int				len;
	int				len_uint;

	nb = (int)va_arg(params, int);
	u_nb = ft_abs(nb);
	len_uint = ft_len_uint_base(u_nb, 10);
	if (ptr->minus != 1)
		ft_aff_di(ptr, len_uint, nb);
	len = len_uint - (nb == 0 && ptr->precis == 0);
	if (ptr->minus == 1 && nb < 0)
		ft_putchar('-');
	while (ptr->precis > len++)
		ft_putchar('0');
	if (!(ptr->precis == 0 && nb == 0))
		ft_put_uint_base(u_nb, "0123456789");
	else if (ptr->field <= 0)
		ptr->ret--;
	if (ptr->minus == 1)
		ft_aff_di(ptr, len_uint, nb);
	ptr->ret += ft_the_max(3, ptr->field, ptr->precis + (nb < 0),
			ft_len_int_base(nb, 10));
	return (1);
}

int	ft_conv_u(t_printf *ptr, va_list params)
{
	int				len_uint;
	unsigned int	nb;
	int				len;
	int				not_exist;

	nb = (unsigned int)va_arg(params, unsigned int);
	len_uint = ft_len_uint_base(nb, 10);
	not_exist = (nb == 0 && ptr->precis == 0);
	if (ptr->minus != 1)
		ft_aff_uxx(ptr, len_uint, not_exist);
	len = len_uint - not_exist;
	while (ptr->precis > len++)
		ft_putchar('0');
	if (!(ptr->precis == 0 && nb == 0))
		ft_put_uint_base(nb, "0123456789");
	else if (ptr->field <= 0)
		ptr->ret--;
	if (ptr->minus == 1)
		ft_aff_uxx(ptr, len_uint, not_exist);
	ptr->ret += ft_the_max(3, ptr->field, ptr->precis, len_uint);
	return (1);
}

int	ft_conv_x(t_printf *ptr, va_list params)
{
	int				len_uint;
	unsigned int	nb;
	int				len;
	int				not_exist;

	nb = (unsigned int)va_arg(params, unsigned int);
	len_uint = ft_len_uint_base(nb, 16);
	not_exist = (nb == 0 && ptr->precis == 0);
	if (ptr->minus != 1)
		ft_aff_uxx(ptr, len_uint, not_exist);
	len = len_uint - not_exist;
	while (ptr->precis > len++)
		ft_putchar('0');
	if (!(ptr->precis == 0 && nb == 0))
		ft_put_uint_base(nb, "0123456789abcdef");
	else if (ptr->field <= 0)
		ptr->ret--;
	if (ptr->minus == 1)
		ft_aff_uxx(ptr, len_uint, not_exist);
	ptr->ret += ft_the_max(3, ptr->field, ptr->precis, len_uint);
	return (1);
}

int	ft_conv_xup(t_printf *ptr, va_list params)
{
	int				len_uint;
	unsigned int	nb;
	int				len;
	int				not_exist;

	nb = (unsigned int)va_arg(params, unsigned int);
	len_uint = ft_len_uint_base(nb, 16);
	not_exist = (nb == 0 && ptr->precis == 0);
	if (ptr->minus != 1)
		ft_aff_uxx(ptr, len_uint, not_exist);
	len = len_uint - not_exist;
	while (ptr->precis > len++)
		ft_putchar('0');
	if (!(ptr->precis == 0 && nb == 0))
		ft_put_uint_base(nb, "0123456789ABCDEF");
	else if (ptr->field <= 0)
		ptr->ret--;
	if (ptr->minus == 1)
		ft_aff_uxx(ptr, len_uint, not_exist);
	ptr->ret += ft_the_max(3, ptr->field, ptr->precis, len_uint);
	return (1);
}
