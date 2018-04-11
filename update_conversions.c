/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_conversions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:39:44 by slin              #+#    #+#             */
/*   Updated: 2018/04/11 13:37:58 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int					update_num(char **str)
{
	int			result;
	int			i;
	int			sign;

	result = 0;
	i = 0;
	sign = 1;
	while ((*str)[i] >= '0' && (*str)[i] <= '9')
	{
		result = result * 10 + (*str)[i] - '0';
		i++;
	}
	(*str) = &(*str)[i];
	return (result * sign);
}

void				update_length(char **fs, t_info *inf)
{
	if (**fs == 'h')
		inf->length = 7;
	(*fs)++;
	if (**fs == 'h')
		inf->length = 6;
	else
		(*fs)--;
	if (**fs == 'l')
	{
		(*fs)++;
		if (**fs == 'l')
			inf->length = 9;
		else
		{
			inf->length = 8;
			(*fs)--;
		}
	}
	if (**fs == 'j')
		inf->length = 10;
	if (**fs == 'z')
		inf->length = 11;
}

int					is_specifier(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'c' ||
		c == 'C' || c == 'd' || c == 'D' || c == 'i' ||
		c == 'o' || c == 'O' || c == 'u' || c == 'U' ||
		c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

void				update_specifier(char c, t_info *inf)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'c' || c == 'C' ||
		c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' ||
		c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == '%')
		inf->specifier = c;
	else
		inf->specifier = '!';
}

int					update_conversions(char **fs, va_list lst)
{
	t_info	inf;

	set_info_initial(&inf);
	while (**fs == '+' || **fs == '-' ||
			**fs == ' ' || **fs == '#' || **fs == '0')
	{
		update_flags(fs, &inf);
		(*fs)++;
	}
	if (**fs >= '0' && **fs <= '9')
		inf.width = update_num(fs);
	if (**fs == '.')
	{
		(inf.flags)[6] = '.';
		(*fs)++;
		inf.precision = update_num(fs);
	}
	if (**fs == 'h' || **fs == 'l' || **fs == 'j' || **fs == 'z')
	{
		update_length(fs, &inf);
		(*fs)++;
	}
	if (is_specifier(**fs) == 1)
		update_specifier(**fs, &inf);
	return (take_arg_and_print(&inf, lst, 0));
}
