.SILENT:
NAME = minitalk
SV = server
CT = client
CC = cc

#=== LIBRARIES ===#

LIBFT_PATH =	./lib/libft/
LIBFT =			$(LIBFT_PATH)libft.a

CFLAGS =	-Wall -Wextra -Werror #-g -fsanitize=address 
OTHERFLAGS = -L$(LIBFT_PATH) -lft
SRC_SV =	./src/$(SV).c
SRC_CT =	./src/$(CT).c

#=== COLORS ===#

RED =		\033[0;31m
GREEN =		\033[0;92m
YELLOW =	\033[93m
BLUE =		\033[0;34m
MAGENTA =	\033[0;35m
CYAN =		\033[96m
RESET =		\033[0m

TAG =	$(CYAN)[$(NAME)]$(RESET)

#=== RULES ===#

all: $(NAME)

$(NAME): $(SV) $(CT)

$(SV): $(LIBFT) $(SRC)
	@echo "$(TAG) Making Program"
	@$(CC) $(CFLAGS) $(SRC_SV) $(OTHERFLAGS) -o $(SV)

$(CT): $(LIBFT) $(SRC)
	@echo "$(TAG) Making $(CT)"
	@$(CC) $(CFLAGS) $(SRC_CT) $(OTHERFLAGS) -o $(CT)

$(LIBFT):
	@make -C $(LIBFT_PATH)

clean:
	@make -C $(LIBFT_PATH) clean

fclean: clean
	@echo "$(TAG) Full clean." 
	@make -C $(LIBFT_PATH) fclean 
	@rm -f $(SV) $(CT) 

re: fclean all 
	@echo "$(TAG) Recompiling."

.PHONY: all clean fclean re $(NAME)