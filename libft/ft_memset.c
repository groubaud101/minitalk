/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:24:21 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/01 17:24:21 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			index;
	char			*tmp;
	unsigned char	my_c;

	my_c = (unsigned char)c;
	index = 0;
	tmp = (char *)s;
	while (index < n)
	{
		tmp[index] = my_c;
		index++;
	}
	s = (void *)tmp;
	return (s);
}
