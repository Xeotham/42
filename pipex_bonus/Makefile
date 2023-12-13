#================ COMPILATOR ================#
CC = cc
#=================== FLAGS ==================#
FLAGS = -Wall -Wextra -Werror -g
#=================== NAME ===================#
NAME = pipex
#============= MANDATORY SOUCES =============#
SRCS = access.c \
	link_list.c \
	link_list_utils.c \
	pipex.c \
	utils.c \
	process.c \
	error.c \
	fd_fork_handle.c
#=============== BONUS SOURCES ==============#
#BONUS = 

#============ TRANSFORM .c TO .o ============#
#============== MANDATORY PART ==============#
OBJM = $(SRCS:.c=.o)

#================ BONUS PART ================#
OBJB = $(BONUS:.c=.o)

#================= MAKE NAME ================#

LIBFT = Libft/libft.a

all : $(NAME)

$(LIBFT) :
	@ $(MAKE) -C Libft all

%.o : %.c pipex.h
	@ $(CC) $(FLAGS) -c $< -o $@

bonus :
	@ $(CC) $(FLAGS) $(BONUS) $(LIBFT) -o $(NAME)

$(NAME) : $(OBJM) $(LIBFT)
	@ $(CC) $(FLAGS) $(OBJM) $(LIBFT) -o $(NAME)
	
clean :
	@ $(MAKE) -C Libft clean
	rm -rf $(OBJM)

fclean :
	@ $(MAKE) -C Libft fclean
	rm -rf $(NAME) $(OBJM)

re : fclean all

.PHONY : all clean fclean re bonus
