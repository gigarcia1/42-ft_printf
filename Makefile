# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gigarcia <gigarcia@student.42madrid.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/09 01:31:46 by gigarcia          #+#    #+#              #
#    Updated: 2026/05/09 01:31:51 by gigarcia         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC      = cc
CFLAGS  = -Wall -Werror -Wextra -Iincludes
NAME    = libftprintf.a
RM      = rm -rf
AR      = ar -rcs

SRCS    = ft_printf.c \
          utils/ft_printf_utils_nbr.c \
          utils/ft_printf_utils_text.c

OBJS    = $(SRCS:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
