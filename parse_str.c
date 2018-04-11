/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_str.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 15:21:36 by slin              #+#    #+#             */
/*   Updated: 2018/04/10 19:22:32 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				size_wchar(unsigned int bye)
{
	if (bye <= 127)
		return (1);
	else if (bye >= 128 && bye <= 2047)
		return (2);
	else if (bye >= 2048 && bye <= 65535)
		return (3);
	else if (bye >= 65536 && bye <= 2097151)
		return (4);
	else
		return (0);
}

int				ft_putstr(char *str, int p)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (ft_putstr("(null)", p));
	while (*str && p--)
	{
		len += ft_putchar(*str);
		str++;
	}
	return (len);
}

int				ft_putwstr(wchar_t *str, int p)
{
	int	len;

	len = 0;
	if (str == NULL)
		return (ft_putstr("(null)", p));
	while (*str)
	{
		len += ft_putwchar(*str);
		str++;
	}
	return (len);
}

int				parse_str1(t_info *inf, void *str, int len, int len2)
{
	if (inf->specifier == 's' && inf->length != 8)
		len += ft_putstr((char*)str, inf->precision);
	else if (inf->specifier == 'S' ||
			(inf->specifier == 's' && inf->length == 8))
		len += ft_putwstr((wchar_t*)str, inf->precision);
	if (inf->flags[3] == '-')
	{
		while (inf->width > len2)
		{
			len += ft_putchar(' ');
			inf->width--;
		}
		while (inf->width > inf->precision && inf->precision != -1
				&& len2 > inf->precision)
		{
			len += ft_putchar(' ');
			len2--;
		}
	}
	return (len);
}

int				parse_str(t_info *inf, void *str)
{
	int	len;
	int	len2;

	len = 0;
	if (str == NULL)
		len2 = 6;
	else
		len2 = ft_strlen((char*)str);
	if (inf->flags[2] == '0')
		inf->flags[0] = '0';
	if (inf->flags[3] != '-')
	{
		while (inf->width > len2)
		{
			len += ft_putchar(inf->flags[0]);
			inf->width--;
		}
		while (inf->width > inf->precision && inf->precision != -1
				&& len2 > inf->precision)
		{
			len += ft_putchar(inf->flags[0]);
			inf->width--;
		}
	}
	return (parse_str1(inf, str, len, len2));
}
