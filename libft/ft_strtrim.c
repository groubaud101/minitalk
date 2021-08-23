/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:24:52 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/01 17:24:52 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_strlentrim(char const *s1, char const *set)
{
	int	index;
	int	len;

	index = 0;
	len = 0;
	while (ft_isinstr(s1[index], set) != -1)
		index++;
	if (s1[index] == '\0')
		return (0);
	while (s1[index])
	{
		index++;
		len++;
	}
	index--;
	while (index >= 0 && ft_isinstr(s1[index], set) != -1)
	{
		index--;
		len--;
	}
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		index;
	int		jndex;
	char	*trim;
	int		len;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlentrim(s1, set);
	trim = (char *)ft_calloc(sizeof(*trim), len + 1);
	if (!trim)
		return (NULL);
	if (len == 0)
		return (trim);
	index = 0;
	jndex = 0;
	while (ft_isinstr(s1[index], set) != -1)
		index++;
	while (jndex < len)
		trim[jndex++] = s1[index++];
	return (trim);
}
