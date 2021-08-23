/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:24:41 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/01 17:24:41 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t		len;
	const char	*osrc;

	len = size;
	osrc = src;
	if (size != 0)
	{
		while (--len && *src)
			*dst++ = *src++;
		if (len)
			*dst++ = *src++;
	}
	if (len == 0 && size != 0)
		*dst = '\0';
	return (ft_strlen(osrc));
}
