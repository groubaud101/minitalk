/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:04:15 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/12 17:57:32 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_len_uint_base(unsigned int n, int len_base)
{
	int	len;

	len = 1;
	while (n >= (unsigned int)len_base)
	{
		n = n / len_base;
		len++;
	}
	return (len);
}

int	ft_len_ulong_base(unsigned long n, int len_base)
{
	int	len;

	len = 1;
	while (n >= (unsigned long)len_base)
	{
		n = n / len_base;
		len++;
	}
	return (len);
}

int	ft_len_ulonglong_base(unsigned long long n, int len_base)
{
	int	len;

	len = 1;
	while (n >= (unsigned long long)len_base)
	{
		n = n / len_base;
		len++;
	}
	return (len);
}

int	ft_len_int_base(int n, int len_base)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n = n / len_base;
		len++;
	}
	return (len);
}
