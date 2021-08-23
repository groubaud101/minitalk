/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:24:47 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/01 17:24:47 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	index;
	size_t	jndex;

	if (*needle == 0)
		return ((char *)haystack);
	index = 0;
	while (index < n && haystack[index])
	{
		jndex = 0;
		while (haystack[jndex + index] == needle[jndex] && needle[jndex]
			&& index + jndex < n)
			jndex++;
		if (needle[jndex] == '\0')
			return ((char *)haystack + index);
		index++;
	}
	return (NULL);
}
