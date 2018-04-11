/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_uns.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 15:43:51 by slin              #+#    #+#             */
/*   Updated: 2018/04/10 19:31:15 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			count_number2(intmax_t nbr)
{
	int	len;

	len = 1;
	nbr /= 10;
	while (nbr)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

void		put_nbr2(uintmax_t nbr)
{
	if (nbr < 10)
		ft_putchar(nbr + '0');
	else
	{
		put_nbr2(nbr / 10);
		put_nbr2(nbr % 10);
	}
}

int			write_padd2(t_info *inf, int width, int len)
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

int			print_uns(t_info *inf, uintmax_t nbr, int len)
{
	if (inf->flags[6] == '.' && inf->precision <= 0 && nbr == 0)
		len = 0;
	else
		len = count_number2(nbr);
	if (inf->flags[3] == '-')
	{
		if (inf->precision > len)
			len = write_padd2(inf, inf->width, len);
		if (inf->flags[6] == '.' && inf->precision <= 0 && nbr == 0)
			len += -1;
		else
			put_nbr2(nbr);
		if (inf->width > len)
			len = write_padd2(inf, inf->width, len);
	}
	else
	{
		if (inf->width > len || inf->precision > len)
			len = write_padd2(inf, inf->width, len);
		if (inf->flags[6] == '.' && inf->precision <= 0 && nbr == 0)
			len += -1;
		else
			put_nbr2(nbr);
	}
	return (inf->width > len ? inf->width : len);
}

int			parse_uns(t_info *inf, void *num)
{
	if (inf->specifier == 'U' || inf->length == 8)
		return (print_uns(inf, (unsigned long)num, 0));
	else if (inf->length == 6)
		return (print_uns(inf, (unsigned char)num, 0));
	else if (inf->length == 7)
		return (print_uns(inf, (unsigned short)num, 0));
	else if (inf->length == 9)
		return (print_uns(inf, (unsigned long long)num, 0));
	else if (inf->length == 10)
		return (print_uns(inf, (uintmax_t)num, 0));
	else if (inf->length == 11)
		return (print_uns(inf, (size_t)num, 0));
	else
		return (print_uns(inf, (unsigned int)num, 0));
	return (-1);
}
