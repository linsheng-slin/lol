/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 19:50:05 by slin              #+#    #+#             */
/*   Updated: 2018/04/10 20:06:25 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*vdst;
	const unsigned char *vsrc;

	vdst = dst;
	vsrc = src;
	i = 0;
	while (i < n)
	{
		vdst[i] = vsrc[i];
		i++;
	}
	return (dst);
}

char			*ft_strdup(const char *src)
{
	size_t		n;
	char		*dst;

	n = ft_strlen(src);
	dst = (char*)malloc(sizeof(const char) * (n + 1));
	if (dst)
		ft_memcpy(dst, src, n + 1);
	return (dst);
}

void			set_info_initial(t_info *initial)
{
	initial->flags = ft_strdup(" ******");
	initial->width = -1;
	initial->precision = -1;
	initial->length = 0;
	initial->specifier = 'n';
}

void			update_flags(char **fs, t_info *inf)
{
	if (**fs == '#')
		(inf->flags)[1] = '#';
	else if (**fs == '0')
		(inf->flags)[2] = '0';
	else if (**fs == '-')
		(inf->flags)[3] = '-';
	else if (**fs == '+')
		(inf->flags)[4] = '+';
	else if (**fs == ' ')
		(inf->flags)[5] = ' ';
}
