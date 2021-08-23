/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:24:36 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/01 17:24:36 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*is_there_null(char const *s1, char const *s2)
{
	if (s1)
		return (ft_strdup(s1));
	else if (s2)
		return (ft_strdup(s2));
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dest;
	int		dlen;
	int		len_s1;

	if (!s1 || !s2)
		return (is_there_null(s1, s2));
	len_s1 = ft_strlen(s1);
	dlen = len_s1 + ft_strlen(s2);
	dest = (char *)ft_calloc(sizeof(*dest), dlen + 1);
	if (!dest)
		return (NULL);
	ft_strcat(dest, s1);
	ft_strcat(dest, s2);
	return (dest);
}
