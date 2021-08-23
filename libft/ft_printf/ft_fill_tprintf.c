/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tprintf.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: groubaud <groubaud@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 14:04:22 by groubaud          #+#    #+#             */
/*   Updated: 2021/06/12 16:33:28 by groubaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

/*
** patern : %[flags][field width][precision]conversion
*/

static void	ft_add_flag(t_printf *ptr, const char *format)
{
	while (format[ptr->len_pat]
		&& ft_isinstr(format[ptr->len_pat], ptr->flag) >= 0)
	{
		if (format[ptr->len_pat] == '-')
			ptr->minus = 1;
		else if (format[ptr->len_pat] == '0')
			ptr->zero = 1;
		ptr->len_pat++;
	}
	if (ptr->minus == 1 && ptr->zero == 1)
		ptr->zero = 0;
}

static void	ft_add_field(t_printf *ptr, va_list params, const char *format)
{
	if (ft_isdigit(format[ptr->len_pat]) == 1 || format[ptr->len_pat] == '*')
	{
		if (ft_isdigit(format[ptr->len_pat]) == 1)
		{
			ptr->field = ft_atoi(format + ptr->len_pat);
			while (ft_isdigit(format[ptr->len_pat]) == 1)
				ptr->len_pat++;
		}
		else
		{
			ptr->field = (int)va_arg(params, int);
			if (ptr->field < 0)
			{
				ptr->field = -ptr->field;
				ptr->minus = 1;
				if (ptr->zero == 1)
					ptr->zero = 0;
			}
			ptr->len_pat++;
		}
	}
}

static void	ft_add_precis(t_printf *ptr, va_list params, const char *format)
{
	if (format[ptr->len_pat] == '.')
	{
		ptr->len_pat++;
		ptr->explicit_precis = 0;
		if (format[ptr->len_pat] == '*' || ft_isdigit(format[ptr->len_pat]))
			ptr->explicit_precis = 1;
		if (format[ptr->len_pat] == '*')
		{
			ptr->precis = (int)va_arg(params, int);
			ptr->len_pat++;
		}
		else
			ptr->precis = ft_atoi(format + ptr->len_pat);
		while (format[ptr->len_pat]
			&& ft_isinstr(format[ptr->len_pat], ptr->conv) == -1)
			ptr->len_pat++;
	}
	if (ptr->precis >= 0 && ptr->zero == 1)
		ptr->zero = 0;
}

int	ft_fill_tprintf(t_printf *ptr, va_list params, const char *format)
{
	ft_add_flag(ptr, format);
	ft_add_field(ptr, params, format);
	ft_add_precis(ptr, params, format);
	ptr->num_conv = ft_isinstr(format[ptr->len_pat], ptr->conv);
	if (ptr->num_conv >= 0)
	{
		ptr->len_pat++;
		return (1);
	}
	return (-1);
}
