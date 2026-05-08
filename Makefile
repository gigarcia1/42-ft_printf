CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
RM = rm -rf
AR = ar -rsc

SRCS =	ft_printf.c \
		ft_printf_utils_nbr.c \
		ft_printf_utils_text.:wqc \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all 

.PHONY: all clean fclean re
