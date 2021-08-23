/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:17:27 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/28 19:17:27 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_uint_base_fd(unsigned int n, const char *base, int len, int fd)
{
	if (n >= (unsigned int)len)
		ft_put_uint_base_fd(n / len, base, len, fd);
	ft_putchar_fd(base[ft_abs(n % len)], fd);
}

void	ft_put_uint_base(unsigned int n, const char *base)
{
	ft_put_uint_base_fd(n, base, ft_strlen(base), 1);
}
