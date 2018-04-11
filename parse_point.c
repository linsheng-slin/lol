/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_point.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 16:18:04 by slin              #+#    #+#             */
/*   Updated: 2018/04/11 14:58:54 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_outdit(uintmax_t nbr, char *lib)
{
	if (nbr >= 16)
	{
		ft_outdit(nbr / 16, lib);
		ft_putchar(lib[nbr % 16]);
	}
	else
		ft_putchar(lib[nbr % 16]);
	return (0);
}

static int		cn(uintmax_t nbr)
{
	int	len;

	len = 1;
	nbr /= 16;
	while (nbr)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

static int		write_padd2(t_info *inf, int width, int len)
{
	if ((inf->flags[2] == '0' && inf->flags[3] != '-') || inf->precision > len)
	{
		if (inf->precision > len)
		{
			while (inf->precision > len++)
				write(1, "0", 1);
		}
		else
		{
			while (width > len++)
				write(1, "0", 1);
		}
		len--;
	}
	else
	{
		while (width > len++)
			write(1, " ", 1);
		len--;
	}
	return (len);
}

int				print_point(t_info *inf, uintmax_t nbr)
{
	int	len;

	len = cn(nbr);
	len += 2;
	if (inf->flags[3] == '-')
	{
		if (inf->precision > len)
			len = write_padd2(inf, inf->width, len);
		ft_putchar('0') && ft_putchar('x');
		ft_outdit(nbr, "0123456789abcdef");
		if (inf->width > len)
			len = write_padd2(inf, inf->width, len);
	}
	else
	{
		if ((inf->width > len || inf->precision > len) && inf->flags[2] != '0')
			len = write_padd2(inf, inf->width, len);
		ft_putchar('0') && ft_putchar('x');
		if ((inf->width > len || inf->precision > len) && inf->flags[2] == '0')
			len = write_padd2(inf, inf->width, len);
		ft_outdit(nbr, "0123456789abcdef");
	}
	return (inf->width > len ? inf->width : len);
}

int				parse_point(t_info *inf, void *num)
{
	return (print_point(inf, (uintmax_t)num));
}
