/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/28 19:17:56 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/28 19:17:56 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_put_int_base_fd(int n, const char *base, int len, int fd)
{
	if (n >= len || n <= -len)
		ft_put_int_base_fd(n / len, base, len, fd);
	if (n > -len && n < 0)
		ft_putchar_fd('-', fd);
	ft_putchar_fd(base[ft_abs(n % len)], fd);
}

void	ft_put_int_base(int n, const char *base)
{
	ft_put_int_base_fd(n, base, ft_strlen(base), 1);
}
