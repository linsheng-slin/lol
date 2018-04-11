/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_char.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 17:13:43 by slin              #+#    #+#             */
/*   Updated: 2018/04/10 16:57:28 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_char(t_info *inf, void *c)
{
	int			len;
	int			wide;
	char		spec;

	len = 0;
	wide = inf->width;
	spec = inf->specifier;
	if ((inf->flags)[2] == '0')
		(inf->flags)[0] = '0';
	if ((inf->flags)[3] != '-' && wide > 1)
	{
		while (wide-- > 1)
			len += ft_putchar((inf->flags)[0]);
	}
	if ((spec == 'c' && inf->length != 8) || spec == 'C' ||
		(spec == 'c' && inf->length == 8))
		len += ft_putchar((char)c);
	else
		len += ft_putchar(inf->specifier);
	if ((inf->flags)[3] == '-' && wide > 1)
	{
		while (wide-- > 1)
			len += ft_putchar(' ');
	}
	return (len);
}
