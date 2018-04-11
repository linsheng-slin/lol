/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 16:11:10 by slin              #+#    #+#             */
/*   Updated: 2018/04/10 16:51:31 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int		start_formula(char *fs, va_list lst)
{
	int		len;

	len = 0;
	while (*fs)
	{
		if (*fs != '%')
		{
			len += ft_putchar(*fs);
		}
		else
		{
			fs++;
			len += update_conversions(&(fs), lst);
		}
		fs++;
	}
	return (len);
}

int		ft_printf(char *format_str, ...)
{
	int			result;
	va_list		list;

	result = 0;
	va_start(list, format_str);
	result = start_formula(format_str, list);
	va_end(list);
	return (result);
}
