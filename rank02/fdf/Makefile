.SILENT:
NAME = fdf
CC = cc

#=== LIBRARIES ===#

LIBFT_PATH = ./lib/libft/ 
LIBFT = $(LIBFT_PATH)libft.a
MLX_PATH = ./lib/minilibx-linux/
MLX = $(MLX_PATH)libmlx_Linux.a

CFLAGS = -Wall -Wextra -Werror #-g -fsanitize=address 
OTHERFLAGS = -L$(LIBFT_PATH) -lft -L$(MLX_PATH) -lmlx_Linux -lXext -lX11 -lm -lz -o $(NAME)
SRC =	./src/*.c ./src/node/*.c ./src/draw/*.c ./src/map/*.c\
		# ./src/main.c \
		# ./src/hooks.c ./src/map_reader.c ./src/node/node_new.c ./src/node/node_addback.c ./src/node/node_find.c \
		# ./src/node/node_last.c ./src/node/node_lastbelow.c



#=== COLORS ===#

RED = \033[0;31m
GREEN = \033[0;92m
YELLOW = \033[93m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[96m
RESET = \033[0m

TAG = $(CYAN)[$(NAME)]$(RESET)

#=== RULES ===#

all: $(NAME)

$(NAME): $(MLX) $(LIBFT) $(SRC)
	@echo "$(TAG) Making $(TAG)"
	@$(CC) $(CFLAGS) $(SRC) $(OTHERFLAGS)

$(MLX):
	@make -C $(MLX_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@echo "$(TAG) Cleaning all object files."
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@echo "$(TAG) Full clean." 
	@make -C $(LIBFT_PATH) fclean 
	@rm -f $(NAME)
	
re: fclean all 
	@echo "$(TAG) Recompiling."

run: re
	@./fdf maps/42Maps/42.fdf
	@make fclean

.PHONY: all clean fclean re run