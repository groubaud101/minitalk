/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:24:14 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/06 19:05:13 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t					index;
	unsigned char			*tmp;
	const unsigned char		*tmp2;
	unsigned char			my_c;

	my_c = (unsigned char)c;
	index = 0;
	if (n == 0)
		return (NULL);
	tmp = (unsigned char *)dest;
	tmp2 = (const unsigned char *)src;
	while (index < n)
	{
		tmp[index] = tmp2[index];
		if (tmp2[index] == my_c)
		{
			dest = (void *)tmp;
			return (dest + index + 1);
		}
		index++;
	}
	return (NULL);
}
