/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:24:46 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/01 17:24:46 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t				index;
	const unsigned char	*tmp1;
	const unsigned char	*tmp2;

	if (n == 0 || (!s1 && !s2))
		return (0);
	index = 0;
	tmp1 = (const unsigned char *)s1;
	tmp2 = (const unsigned char *)s2;
	while (tmp1[index] && index < n && tmp1[index] == tmp2[index])
		index++;
	if (index == n)
		return (0);
	if (tmp1[index] > tmp2[index])
		return (1);
	else if (tmp1[index] < tmp2[index])
		return (-1);
	return (0);
}
