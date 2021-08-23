/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 17:24:00 by groubaud          #+#    #+#             */
/*   Updated: 2021/04/01 17:24:00 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (!lst || !(*lst))
		return ;
	tmp = (*lst)->next;
	while (tmp)
	{
		ft_lstdelone(*lst, del);
		*lst = tmp;
		tmp = tmp->next;
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
