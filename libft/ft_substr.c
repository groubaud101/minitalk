/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:24:53 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/01 17:24:53 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	index;
	size_t			slen;
	size_t			dlen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	if (start > slen)
		return ((char *)ft_calloc(sizeof(*str), 1));
	if (slen > len)
		dlen = len;
	else
		dlen = slen - start;
	str = (char *)ft_calloc(sizeof(*str), (dlen + 1));
	if (!str)
		return (NULL);
	index = start;
	while (index - start < dlen && s[index])
	{
		str[index - start] = s[index];
		index++;
	}
	return (str);
}
