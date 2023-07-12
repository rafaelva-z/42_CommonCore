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
SRC =	./src/ft_issignal.c ./src/hooks.c ./src/main.c ./src/move_map.c ./src/move_map2.c \
		./src/draw/draw_calc.c ./src/draw/draw_fdf.c ./src/draw/draw_line.c ./src/draw/draw_pixel.c \
		./src/node/node_addback.c ./src/node/node_find.c ./src/node/node_last.c \
		./src/node/node_addbelow.c ./src/node/node_lastbelow.c ./src/node/node_new.c \
		./src/map/map_addline.c ./src/map/map_free.c ./src/map/map_getsize.c ./src/map/map_reader.c \

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

$(NAME): $(LIBFT) $(MLX) $(SRC)
	@echo "$(TAG) Making Program"
	@$(CC) $(CFLAGS) $(SRC) $(OTHERFLAGS)

$(MLX):
	@make -C $(MLX_PATH)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@echo "$(TAG) Full clean." 
	@make -C $(LIBFT_PATH) fclean 
	@rm -f $(NAME)
	
re: fclean all 
	@echo "$(TAG) Recompiling."

.PHONY: all clean fclean re