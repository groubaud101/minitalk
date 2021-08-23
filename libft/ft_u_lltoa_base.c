/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_lltoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 20:21:35 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/23 20:21:35 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_rec_u_lltoa_base(unsigned long long n, char *nbr, int i,
								char *base)
{
	if (n > 9)
		nbr = ft_rec_u_lltoa_base(n / ft_strlen(base), nbr, i - 1, base);
	nbr[i] = base[n % ft_strlen(base)];
	return (nbr);
}

char	*ft_u_lltoa_base(unsigned long long n, char *base)
{
	int		len_nbr;
	char	*nbr;

	len_nbr = ft_len_ulonglong_base(n, ft_strlen(base));
	nbr = (char *)ft_calloc(sizeof(*nbr), len_nbr + 1);
	if (!nbr)
		return (NULL);
	nbr = ft_rec_u_lltoa_base(n, nbr, len_nbr - 1, base);
	return (nbr);
}
