CC = cc
CFLAGS = -Wall -Werror -Wextra
NAME = libftprintf.a
RM = rm -rf
AR = ar -rsc

SRCS = -archivooos :P-	

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
