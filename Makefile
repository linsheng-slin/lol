#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slin <linsheng4522010@gmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/04 16:20:37 by slin              #+#    #+#              #
#    Updated: 2018/04/04 16:21:34 by slin             ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	=	libftprintf.a

SRC		=	ft_printf.c out.c parse_percent.c update_conversions.c \
			parse_char.c parse_int.c parse_uns.c parse_oct.c \
			parse_hex.c parse_point.c parse_str.c functions.c \
			hi.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror
RM		= 	rm -f

all: $(NAME)

$(NAME): $(OBJ)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

%.o : %.c
	@$(CC) $(CFLAGS) -c $(SRC)

clean:
	@$(RM) *.o*

fclean: clean
	@$(RM) $(NAME)

re: fclean all