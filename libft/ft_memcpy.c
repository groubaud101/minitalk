/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:24:18 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/01 17:24:18 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		index;
	char		*tmp;
	const char	*tmp2;

	index = 0;
	if (!dest && !src)
		return (NULL);
	tmp = (char *)dest;
	tmp2 = (const char *)src;
	while (index < n)
	{
		tmp[index] = tmp2[index];
		index++;
	}
	dest = (void *)tmp;
	return (dest);
}
