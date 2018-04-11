/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hi.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 20:37:33 by slin              #+#    #+#             */
/*   Updated: 2018/04/10 20:46:33 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_putwchar(wchar_t wc)
{
	int					len;
	int					size;
	unsigned char		curr_byte;

	len = 0;
	size = size_wchar(wc);
	if (size == 1)
		return (ft_putchar(wc));
	curr_byte = (240 << (4 - size)) | (wc >> ((size - 1) * 6));
	len += ft_putchar(curr_byte);
	size--;
	while (size--)
	{
		curr_byte = ((wc >> ((size) * 6)) & 63) | 128;
		len += ft_putchar(curr_byte);
	}
	return (len);
}

int				print_oct2(t_info *inf, uintmax_t nbr, int len)
{
	if (inf->width > len || inf->precision > len)
		len = write_padd2o(inf, inf->width, len);
	if (inf->flags[1] == '#')
		ft_putchar('0');
	if (inf->flags[6] == '.' && inf->precision <= 0 && nbr == 0)
		len += 0;
	else
		ft_outdito(nbr, "01234567");
	return (inf->width > len ? inf->width : len);
}

int				print_hex2(t_info *inf, uintmax_t nbr, int len)
{
	if ((inf->width > len || inf->precision > len) && inf->flags[2] != '0')
		len = write_padd2h(inf, inf->width, len);
	if (inf->flags[1] == '#' && inf->specifier == 'x' && nbr != 0)
		ft_putchar('0') && ft_putchar('x');
	if (inf->flags[1] == '#' && inf->specifier == 'X' && nbr != 0)
		ft_putchar('0') && ft_putchar('X');
	if ((inf->width > len || inf->precision > len) && inf->flags[2] == '0')
		len = write_padd2h(inf, inf->width, len);
	if (inf->flags[6] == '.' && inf->precision <= 0 && nbr == 0)
		len += 0;
	else if (inf->specifier == 'x')
		ft_outdith(nbr, "0123456789abcdef");
	else
		ft_outdith(nbr, "0123456789ABCDEF");
	return (len);
}
