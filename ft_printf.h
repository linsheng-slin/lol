/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:05:05 by slin              #+#    #+#             */
/*   Updated: 2018/04/10 20:52:12 by slin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdint.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>
# include <wchar.h>
# include <unistd.h>

typedef	struct		s_info
{
	char			*flags;
	int				width;
	int				precision;
	int				length;
	char			specifier;
	int				printed;
	int				dot;
}					t_info;

int					update_conversions(char **fs, va_list lst);
int					ft_printf(char *format_str, ...);
int					take_arg_and_print(t_info *inf, va_list lst, int len);
int					ft_putchar(char c);
int					ft_strlen(const char *s);
void				ft_strdel(char **as);
int					parse_percent(t_info *inf, char p);
int					parse_char(t_info *inf, void *c);
int					parse_str(t_info *inf, void *str);
int					parse_int(t_info *inf, void *num);
int					parse_point(t_info *inf, void *num);
int					parse_uns(t_info *inf, void *num);
int					parse_oct(t_info *inf, void *num);
int					parse_hex(t_info *inf, void *num);
int					parse_point(t_info *inf, void *num);
void				ft_putstr2(char *s, int len);
void				*ft_memcpy(void *dst, const void *src, size_t n);
char				*ft_strdup(const char *src);
void				set_info_initial(t_info *initial);
void				update_flags(char **fs, t_info *inf);
int					ft_putwchar(wchar_t wc);
int					print_oct2(t_info *inf, uintmax_t nbr, int len);
int					print_hex2(t_info *inf, uintmax_t nbr, int len);
int					size_wchar(unsigned int bye);
int					ft_outdith(uintmax_t nbr, char *lib);
int					ft_outdito(uintmax_t nbr, char *lib);
int					write_padd2o(t_info *inf, int width, int len);
int					write_padd2h(t_info *inf, int width, int len);

#endif
