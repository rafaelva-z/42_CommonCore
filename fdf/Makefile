.SILENT:
NAME = fdf
CC = cc
LIBFT = $(LIBFT_FOLDER)libft.a
LIBFT_FOLDER = ./lib/libft/ 
MLX = $(MLX_FOLDER)libmlx_Linux.a
MLX_FOLDER = ./lib/minilibx-linux/
OTHERFLAGS = -L$(LIBFT_FOLDER) -lft -L$(MLX_FOLDER) -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME) 
CFLAGS = #-g -fsanitize=address #-Wall -Wextra -Werror
SRC =	./src/main.c \
		./src/hooks.c ./src/map_reader.c ./src/node_new.c ./src/node_addback.c ./src/node_find.c \
		./src/node_last.c

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(SRC)
	@echo "$(NAME) - Making library"
	@$(CC) $(CFLAGS) $(SRC) $(OTHERFLAGS)

$(MLX):
	@make -C $(MLX_FOLDER)

$(LIBFT):
	@make -C $(LIBFT_FOLDER)

clean:
	@echo "$(NAME) - Cleaning all object files."
	@make -C $(MLX_FOLDER) clean
	@make -C $(LIBFT_FOLDER) clean

fclean: clean
	@echo "$(NAME) - Full clean." 
	@make -C $(LIBFT_FOLDER) fclean 
	@rm -f $(NAME)
	
re: fclean all 
	@echo "$(NAME) - Recompiling."

run: re
	@./fdf
	@make fclean

.PHONY: all clean fclean re