#================ COMPILATOR ================#
CC = cc
#=================== FLAGS ==================#
FLAGS = -Wall -Wextra -Werror
#=================== NAME ===================#
NAME = libft.a
#============= MANDATORY SOUCES =============#
SRCS = ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_strlen.c \
	ft_memset.c \
	ft_bzero.c \
	ft_strlcpy.c \
	ft_strlcat.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strncmp.c \
	ft_memchr.c \
	ft_memmove.c \
	ft_memcpy.c \
	ft_memcmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_calloc.c \
	ft_strdup.c \
	ft_substr.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_itoa.c	\
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_split.c \
	ft_unsplit.c
#=============== BONUS SOURCES ==============#
BONUS = ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

#============== PRINTF SOURCES ==============#
PRINTF = ft_printf.c \
	printf_char_print.c \
	printf_nbr_print.c \
	printf_hex_print.c

#============ TRANSFORM .c TO .o ============#
#============== MANDATORY PART ==============#
OBJM = $(SRCS:.c=.o)

#================ BONUS PART ================#
OBJB = $(BONUS:.c=.o)

#================ BONUS PART ================#
OBJPR = $(PRINTF:.c=.o)

#============== EXECUTABLE PART =============#

all : $(NAME)

$(NAME) : $(OBJB) $(OBJM) $(OBJPR)
	@ar rcs $(NAME) $(OBJB) $(OBJM) $(OBJPR)
	
%.o : %.c libft.h
	@$(CC) $(FLAGS) -c $< -o $@

clean :
	@rm -rf $(OBJB) $(OBJM) $(OBJPR)

fclean : clean
	@rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re
