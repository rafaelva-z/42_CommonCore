.SILENT:
NAME = push_swap
CC = cc
LIBFT_FOLDER = ./libft/ 
LIBFT = $(LIBFT_FOLDER)libft.a
OTHERFLAG = -L$(LIBFT_FOLDER) -lft -o $(NAME)
CFLAGS = #-Wall -Wextra -Werror
SRC = main.c \
	./utils/ft_issignal.c ./utils/ft_error.c ./utils/ft_lstbeforelast.c \
	./utils/ft_swap.c ./utils/heapperm.c ./utils/ft_bzero_int.c ./utils/print_utils.c \
	./utils/ps_checkers.c ./utils/ps_create_stack.c \
	./operations/ls_push.c ./operations/ls_rotate.c ./operations/ls_rrotate.c ./operations/ls_swap.c \
	./algos/ps_bruteforce.c ./algos/ps_newsort.c\

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(OTHERFLAG)
	@echo "$(NAME) - Done"

$(LIBFT):
	@make -C $(LIBFT_FOLDER)

clean:
	@echo "$(NAME) - Cleaning all object files."
	@rm -f $(OBJ)
	@make -C $(LIBFT_FOLDER) clean

fclean: clean
	@echo "$(NAME) - Full clean."  
	@rm -f $(NAME)
	@make -C $(LIBFT_FOLDER) fclean

re: fclean all 
	@echo "$(NAME) - Recompiling."  

run: re
	@echo "$(NAME) - running"
	./push_swap 5 4 3 2 1
	@make fclean

.PHONY: all bonus clean fclean re