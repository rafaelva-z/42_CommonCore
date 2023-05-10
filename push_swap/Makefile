.SILENT:
NAME = push_swap
CC = cc
LIBFT_FOLDER = ./libft/ 
LIBFT = $(LIBFT_FOLDER)libft.a
OTHERFLAG = -L$(LIBFT_FOLDER) -lft -o $(NAME)
CFLAGS = -Wall -Wextra -Werror
SRC = main.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(OTHERFLAG)
	@echo "$(NAME) - Done"

$(LIBFT):
	make -C $(LIBFT_FOLDER)

clean:
	@echo "$(NAME) - Cleaning all object files."
	@rm -f $(OBJ) $(OBJ_BONUS)
	@make -C $(LIBFT_FOLDER) clean

fclean: clean
	@echo "$(NAME) - Full clean."  
	@rm -f $(NAME)
	@make -C $(LIBFT_FOLDER) fclean

re: fclean all 
	@echo "$(NAME) - Recompiling."  

run: re clean
	@echo "====RUN===="
	./push_swap -10 0 5 6 7 800

.PHONY: all bonus clean fclean re