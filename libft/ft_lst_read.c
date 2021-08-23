/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:13:08 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/16 20:13:08 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_read	*ft_lstnew_read(char *str, int rd)
{
	t_read	*lst;

	lst = (t_read *)malloc(sizeof(*lst));
	if (!lst)
		return (NULL);
	lst->str = ft_strdup(str);
	lst->rd = rd;
	lst->next = NULL;
	return (lst);
}

void	ft_lstadd_read(t_read **alst, t_read *new_list)
{
	t_read	*lst;

	if (alst && *alst)
	{
		lst = *alst;
		while (lst->next)
			lst = lst->next;
		lst->next = new_list;
	}
	else
		*alst = new_list;
}
