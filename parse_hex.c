/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 13:57:05 by slin              #+#    #+#             */
/*   Updated: 2018/04/10 17:24:39 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_outdith(uintmax_t nbr, char *lib)
{
	if (nbr >= 16)
	{
		ft_outdith(nbr / 16, lib);
		ft_putchar(lib[nbr % 16]);
	}
	else
		ft_putchar(lib[nbr % 16]);
	return (0);
}

static int		cn(uintmax_t nbr)
{
	int		len;

	len = 1;
	nbr /= 16;
	while (nbr)
	{
		nbr /= 16;
		len++;
	}
	return (len);
}

int				write_padd2h(t_info *inf, int width, int len)
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

int				print_hex(t_info *inf, uintmax_t nbr, int len)
{
	len = cn(nbr);
	if (inf->flags[6] == '.' && inf->precision <= 0 && nbr == 0)
		len = 0;
	if (inf->flags[1] == '#' && nbr != 0)
		len += 2;
	if (inf->flags[3] == '-')
	{
		if (inf->precision > len)
			len = write_padd2h(inf, inf->width, len);
		if (inf->flags[1] == '#' && inf->specifier == 'x' && len != 0)
			ft_putchar('0') && ft_putchar('x');
		if (inf->flags[1] == '#' && inf->specifier == 'X' && len != 0)
			ft_putchar('0') && ft_putchar('X');
		if (inf->flags[6] == '.' && inf->precision <= 0 && nbr == 0)
			len += 0;
		else if (inf->specifier == 'x')
			ft_outdith(nbr, "0123456789abcdef");
		else
			ft_outdith(nbr, "0123456789ABCDEF");
		if (inf->width > len)
			len = write_padd2h(inf, inf->width, len);
	}
	else
		len = print_hex2(inf, nbr, len);
	return (inf->width > len ? inf->width : len);
}

int				parse_hex(t_info *inf, void *num)
{
	int len;

	len = 0;
	if (inf->length == 8)
		return (print_hex(inf, (unsigned long)num, 0));
	else if (inf->length == 6)
		return (print_hex(inf, (unsigned char)num, 0));
	else if (inf->length == 7)
		return (print_hex(inf, (unsigned short)num, 0));
	else if (inf->length == 9)
		return (print_hex(inf, (unsigned long long)num, 0));
	else if (inf->length == 10)
		return (print_hex(inf, (uintmax_t)num, 0));
	else if (inf->length == 11)
		return (print_hex(inf, (size_t)num, 0));
	else
		return (print_hex(inf, (unsigned int)num, 0));
	return (0);
}
