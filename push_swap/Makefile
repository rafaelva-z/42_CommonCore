.SILENT:
NAME = push_swap
CC = cc
LIBFT_FOLDER = ./libft/ 
LIBFT = $(LIBFT_FOLDER)libft.a
OTHERFLAG = -L$(LIBFT_FOLDER) -lft -o $(NAME)
CFLAGS = -Wall -Wextra -Werror
SRC = main.c \
	./utils/is_signal.c ./utils/ft_error.c ./utils/input_check.c \
	./operations/ls_push.c ./operations/ls_rotate.c ./operations/ls_swap.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(OTHERFLAG)
	@echo "$(NAME) - Done"

$(LIBFT):
	make -C $(LIBFT_FOLDER)

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

run: re clean
	@echo "$(NAME) - running"
	./push_swap -5000 100 985 21320 -100 -2

.PHONY: all bonus clean fclean re