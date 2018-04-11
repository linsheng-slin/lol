/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   out.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:29:03 by slin              #+#    #+#             */
/*   Updated: 2018/04/10 16:55:48 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_strdel(char **as)
{
	if (as != 0)
	{
		free(*as);
		*as = NULL;
	}
}

int			take_arg_and_print(t_info *inf, va_list lst, int len)
{
	char	spec;

	spec = inf->specifier;
	if (spec == '%')
		len = parse_percent(inf, '%');
	else if (spec == 'c' || spec == 'C')
		len = parse_char(inf, va_arg(lst, void*));
	else if (spec == 'd' || spec == 'D' || spec == 'i')
		len = parse_int(inf, va_arg(lst, void*));
	else if (spec == 'u' || spec == 'U')
		len = parse_uns(inf, va_arg(lst, void*));
	else if (spec == 'o' || spec == 'O')
		len = parse_oct(inf, va_arg(lst, void*));
	else if (spec == 'x' || spec == 'X')
		len = parse_hex(inf, va_arg(lst, void*));
	else if (spec == 's' || spec == 'S')
		len = parse_str(inf, va_arg(lst, void*));
	else if (spec == 'p')
		len = parse_point(inf, va_arg(lst, void*));
	else
		len = parse_char(inf, va_arg(lst, void*));
	ft_strdel(&inf->flags);
	return (len);
}
