.SILENT:
NAME = push_swap
CC = cc
LIBFT_FOLDER = ./libft/ 
LIBFT = $(LIBFT_FOLDER)libft.a
OTHERFLAG = -L$(LIBFT_FOLDER) -lft -o $(NAME)
CFLAGS = #-g -fsanitize=address #-Wall -Wextra -Werror
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
	#./push_swap 72 43 81 87 10 76 45 53 34 28 68 91 39 94 56 37 35 1 71 11 95 4 46 36 15 18 52 24 13 26 27 2 62 57 20 9 12 50 82 80 44 89 93 32 66 29 58 97 17 70 23 55 73 22 40 85 100 25 33 65 90 74 5 63 99 88 67 41 42 7 75 21 31 78 86 30 64 48 61 83 69 16 96 8 79 54 6 3 92 14 49 47 77 38 84 51 19 98 59 60
	./push_swap 10 8 29 9 2 3 1 38
	@make fclean

.PHONY: all bonus clean fclean re