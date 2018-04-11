/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_oct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 20:46:49 by slin              #+#    #+#             */
/*   Updated: 2018/04/10 19:37:00 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		cn(uintmax_t nbr)
{
	int		len;

	len = 1;
	nbr /= 8;
	while (nbr)
	{
		nbr /= 8;
		len++;
	}
	return (len);
}

int				write_padd2o(t_info *inf, int width, int len)
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

int				ft_outdito(uintmax_t nbr, char *lib)
{
	if (nbr >= 8)
	{
		ft_outdito(nbr / 8, lib);
		ft_putchar(lib[nbr % 8]);
	}
	else
		ft_putchar(lib[nbr % 8]);
	return (0);
}

int				print_oct(t_info *inf, uintmax_t nbr)
{
	int len;

	len = cn(nbr);
	if (inf->flags[6] == '.' && inf->precision <= 0 && nbr == 0)
		len = 0;
	if (inf->flags[1] == '#')
		len += 1;
	if (inf->flags[3] == '-')
	{
		if (inf->precision > len)
			len = write_padd2o(inf, inf->width, len);
		if (inf->flags[1] == '#')
			ft_putchar('0');
		if (inf->flags[6] == '.' && inf->precision <= 0 && nbr == 0)
			len += 0;
		else
			ft_outdito(nbr, "01234567");
		if (inf->width > len)
			len = write_padd2o(inf, inf->width, len);
	}
	else
	{
		len = print_oct2(inf, nbr, len);
	}
	return (inf->width > len ? inf->width : len);
}

int				parse_oct(t_info *inf, void *num)
{
	if (inf->specifier == 'O' || inf->length == 8)
		return (print_oct(inf, (unsigned long)num));
	else if (inf->length == 6)
		return (print_oct(inf, (unsigned char)num));
	else if (inf->length == 7)
		return (print_oct(inf, (unsigned short)num));
	else if (inf->length == 9)
		return (print_oct(inf, (unsigned long long)num));
	else if (inf->length == 10)
		return (print_oct(inf, (uintmax_t)num));
	else if (inf->length == 11)
		return (print_oct(inf, (size_t)num));
	else
		return (print_oct(inf, (unsigned int)num));
	return (0);
}
