# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahaifoul <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/20 19:03:15 by ahaifoul          #+#    #+#              #
#    Updated: 2021/11/23 12:04:43 by ahaifoul         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SRCS = ft_printf.c ft_functions.c ft_p_convert.c ft_print_u.c


OBJS :=$(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	ar -cr $@ $^

%.o: %.c
	gcc   $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) 
fclean: clean
	rm -f $(NAME)
re: fclean all
.PHONY: all clean fclean re
