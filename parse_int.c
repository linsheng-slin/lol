/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/05 13:19:14 by slin              #+#    #+#             */
/*   Updated: 2018/04/10 17:30:43 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			count_number(intmax_t nbr)
{
	int		count;

	count = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		nbr *= -1;
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return (count);
}

void		put_nbr3(intmax_t nbr)
{
	if (nbr < 0)
		nbr *= -1;
	if (nbr >= 0 && nbr < 10)
		ft_putchar(nbr + '0');
	else
	{
		put_nbr3(nbr / 10);
		put_nbr3(nbr % 10);
	}
}

int			print_int2(t_info *inf, intmax_t num, int len)
{
	int	tmp;

	tmp = (inf->precision > len) ? inf->precision : len;
	if (num < 0 || inf->flags[4] == '+' || inf->flags[5] == ' ')
		tmp++;
	while (inf->width > tmp && (inf->flags[2] != '0' || inf->precision >= len))
		tmp += ft_putchar(' ');
	if (num < 0)
		ft_putchar('-');
	else if (inf->flags[4] == '+')
		ft_putchar('+');
	else if (inf->flags[5] == ' ')
		ft_putchar(' ');
	while (inf->width > tmp && inf->flags[2] == '0')
		tmp += ft_putchar('0');
	while (inf->precision > len)
		len += ft_putchar('0');
	if (inf->flags[6] == '.' && inf->precision <= 0 && num == 0)
		tmp -= 0;
	else
		put_nbr3(num);
	return (tmp);
}

int			print_int(t_info *inf, intmax_t num, int len)
{
	len = count_number(num);
	if (inf->flags[6] == '.' && inf->precision <= 0 && num == 0)
		len = 0;
	if (inf->flags[3] == '-')
	{
		if (num < 0)
			ft_putchar('-');
		else if (inf->flags[4] == '+')
			ft_putchar('+');
		else if (inf->flags[5] == ' ')
			ft_putchar(' ');
		while (inf->precision > len)
			len += ft_putchar('0');
		if (num < 0 || inf->flags[4] == '+' || inf->flags[5] == ' ')
			len++;
		if (inf->flags[6] == '.' && inf->precision <= 0 && num == 0)
			len -= 0;
		else
			put_nbr3(num);
		while (inf->width > len)
			len += ft_putchar(' ');
	}
	else
		len = (print_int2(inf, num, len));
	return (len);
}

int			parse_int(t_info *inf, void *num)
{
	if (inf->specifier == 'D' || inf->length == 8)
		return (print_int(inf, (long)num, 0));
	else if (inf->length == 6)
		return (print_int(inf, (char)num, 0));
	else if (inf->length == 7)
		return (print_int(inf, (short)num, 0));
	else if (inf->length == 9)
		return (print_int(inf, (long long)num, 0));
	else if (inf->length == 10)
		return (print_int(inf, (intmax_t)num, 0));
	else if (inf->length == 11)
		return (print_int(inf, (size_t)num, 0));
	else
		return (print_int(inf, (int)num, 0));
	return (0);
}
