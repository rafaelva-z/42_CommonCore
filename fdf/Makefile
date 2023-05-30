.SILENT:
NAME = fdf
CC = cc
LIBFT = $(LIBFT_FOLDER)libft.a
LIBFT_FOLDER = ./libft/ 
MLX = $(MLX_FOLDER)libmlx.a
MLX_FOLDER = ./minilibx-linux/
OTHERFLAG = -L$(LIBFT_FOLDER) -lft -o $(NAME)
CFLAGS = #-g -fsanitize=address #-Wall -Wextra -Werror
SRC = main.c \
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(MLX) $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(OTHERFLAG)
	@echo "$(NAME) - Done"

$(MLX): 
	@make -C minilibx-linux

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

.PHONY: all clean fclean re