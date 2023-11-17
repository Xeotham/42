#============ COMPILATOR ============#
CC = cc
#============ FLAGS ============#
FLAGS = -Wall -Wextra -Werror
#============ NAME ============#
NAME = libftprintf.a
#============ MANDATORY SOUCES ============#
SRCS = ft_printf.c \
	char_print.c \
	nbr_print.c \
	hex_print.c
#============ TRANSFORM .c TO .o ============#
OBJS = $(SRCS:.c=.o)

#============ EXECUTABLE PART ============#
all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c ft_printf.h
	$(CC) $(FLAGS) -c $< -o $@
clean :

	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
