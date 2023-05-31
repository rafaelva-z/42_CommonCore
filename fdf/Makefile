.SILENT:
NAME = fdf
CC = cc
LIBFT = $(LIBFT_FOLDER)libft.a
LIBFT_FOLDER = ./libft/ 
MLX = $(MLX_FOLDER)libmlx_Linux.a
MLX_FOLDER = ./minilibx-linux/
OTHERFLAG = -L$(MLX_FOLDER) -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME) 
CFLAGS = #-g -fsanitize=address #-Wall -Wextra -Werror
SRC = main.c \

all: $(NAME)

$(NAME): $(MLX) $(SRC)
	@$(CC) $(CFLAGS) $(SRC) $(OTHERFLAG)
	@echo "$(NAME) - Done"

$(MLX): 
	@make -C $(MLX_FOLDER)

clean:
	@echo "$(NAME) - Cleaning all object files."
	@make -C $(MLX_FOLDER) clean

fclean: clean
	@echo "$(NAME) - Full clean."  
	@rm -f $(NAME)
	
re: fclean all 
	@echo "$(NAME) - Recompiling."

.PHONY: all clean fclean re