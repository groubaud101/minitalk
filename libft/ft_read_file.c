/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 20:13:42 by groubaud          #+#    #+#             */
/*   Updated: 2021/05/12 17:46:32 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

static char	*ft_free_buf_read(char *buf, t_read **lst)
{
	t_read	*tmp;

	if (lst && *lst)
	{
		tmp = (*lst)->next;
		while (tmp)
		{
			free((*lst)->str);
			free(*lst);
			*lst = tmp;
			tmp = tmp->next;
		}
		free((*lst)->str);
		free(*lst);
		*lst = NULL;
	}
	else if (lst)
		free(lst);
	if (buf)
		free(buf);
	return (NULL);
}

static char	*ft_paste(t_read **start, int size)
{
	char	*str;
	t_read	*lst;

	lst = *start;
	str = (char *)ft_calloc(sizeof(*str), size + 1);
	if (!str)
		return ((char *)ft_free_buf_read(0, start));
	while (lst)
	{
		ft_strlcat(str, lst->str, size);
		lst = lst->next;
	}
	ft_free_buf_read(0, start);
	return (str);
}

static int	ft_copy(t_read **start, char *buf, int fd)
{
	int		size;
	t_read	*tmp;
	int		rd;

	tmp = *start;
	size = tmp->rd;
	rd = 1;
	while (rd > 0)
	{
		rd = (read(fd, buf, BUFF));
		if (rd == -1)
		{
			ft_free_buf_read(buf, start);
			return (0);
		}
		size = size + rd;
		tmp = ft_lstnew_read(buf, rd);
		if (!tmp)
		{
			ft_free_buf_read(buf, start);
			return (0);
		}
		ft_lstadd_read(start, tmp);
	}
	return (size);
}

char	*ft_read_file(int fd)
{
	char	*buf;
	int		rd;
	int		size;
	t_read	*lst;
	t_read	*tmp;

	lst = NULL;
	buf = (char *)malloc(BUFF);
	rd = read(fd, buf, BUFF);
	if (rd == -1)
		return ((char *)ft_free_buf_read(buf, &lst));
	tmp = ft_lstnew_read(buf, rd);
	if (!tmp)
		return ((char *)ft_free_buf_read(buf, &lst));
	ft_lstadd_read(&lst, tmp);
	size = ft_copy(&lst, buf, fd);
	if (!size)
		return (NULL);
	if (buf)
		free(buf);
	return (ft_paste(&lst, size));
}
