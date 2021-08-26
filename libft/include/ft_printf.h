/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 19:38:43 by groubaud          #+#    #+#             */
/*   Updated: 2021/06/11 23:26:54 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FLAGS "0-"
# define CONVERSION "cspdiuxX%"

# include "libft.h"
# include <stdarg.h>

/*
**     conv : c s p d i u x X %
** num_conv : 0 1 2 3 4 5 6 7 8
*/

typedef struct s_printf
{
	int		fd;
	char	*flag;
	int		minus;
	int		zero;
	int		field;
	int		precis;
	int		explicit_precis;
	char	*conv;
	int		num_conv;
	int		len_pat;
	int		ret;
}t_printf;

int			ft_printf_fd(int fd, const char *format, ...);
int			ft_printf(const char *format, ...);
const char	*ft_aff_format(t_printf *ptr, const char *format);
int			ft_printf_part_two(t_printf *ptr, va_list params);

int			ft_fill_tprintf(t_printf *ptr, va_list params, const char *fmt);

int			ft_conversion(t_printf *ptr, va_list params);

int			ft_aff_di(t_printf *ptr, int len_uint, int nb);
int			ft_aff_uxx(t_printf *ptr, int len_uint, int exist);
int			ft_aff_p(t_printf *ptr, int len, unsigned long long n);
int			ft_aff_s(t_printf *ptr, const char *str);

int			ft_conv_di(t_printf *ptr, va_list params);
int			ft_conv_u(t_printf *ptr, va_list params);
int			ft_conv_x(t_printf *ptr, va_list params);
int			ft_conv_xup(t_printf *ptr, va_list params);
int			ft_conv_mod(t_printf *ptr);

#endif
