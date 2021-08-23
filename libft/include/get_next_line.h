/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/13 10:13:59 by groubaud          #+#    #+#             */
/*   Updated: 2021/06/21 14:57:13 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE_GNL 10

# include <unistd.h>
# include <stdlib.h>

char	*ft_strjoin_gnl(char *s1, char const *s2);
ssize_t	ft_isinstr_gnl(char c, const char *str);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strdup_gnl(const char *s);

int		get_next_line(int fd, char **line);

#endif
