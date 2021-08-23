/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:24:33 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/01 17:24:33 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	my_c;

	my_c = (unsigned char)c;
	while (*s)
	{
		if (*s == my_c)
			return ((char *)s);
		s++;
	}
	if (*s == my_c)
		return ((char *)s);
	return (NULL);
}
