/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 16:16:23 by slin              #+#    #+#             */
/*   Updated: 2018/04/10 17:42:53 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		parse_percent(t_info *inf, char p)
{
	int		l;
	int		wide;

	l = 0;
	wide = inf->width;
	if ((inf->flags)[2] == '0')
		(inf->flags)[0] = '0';
	if ((inf->flags)[3] != '-' && wide > 1)
	{
		while (wide-- > 1)
			l += ft_putchar((inf->flags)[0]);
	}
	l += ft_putchar(p);
	if ((inf->flags)[3] == '-' && wide > 1)
	{
		while (wide-- > 1)
			l += ft_putchar(' ');
	}
	return (l);
}
