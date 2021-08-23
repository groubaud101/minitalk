/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:13:38 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/16 20:13:38 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puttab_fd(char **tab, char *sep, int fd)
{
	int		index;

	index = 0;
	if (!tab || !tab[index])
	{
		ft_putstr_fd("(null)", fd);
		return ;
	}
	while (tab[index])
	{
		ft_putstr_fd(tab[index], fd);
		index++;
		if (tab[index])
			ft_putstr_fd(sep, fd);
	}
	ft_putchar_fd('\n', fd);
}
