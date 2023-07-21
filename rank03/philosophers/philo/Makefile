.SILENT:

NAME =		philo
CC =		cc
CFLAGS =	-Wall -Wextra -Werror -pthread #-g -fsanitize=address 
SRC =		./src/*.c
OBJ = 		$(SRC:.c=.o)

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

$(NAME): $(SRC) $(OBJ)
	@echo "$(TAG) Making Program"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:
	@echo "$(TAG) Cleaning object files."
	@rm -f $(OBJ)

fclean: clean
	@echo "$(TAG) Full clean." 
	@rm -f $(NAME)

re: fclean all 
	@echo "$(TAG) Recompiling."

run: re
	@echo "$(TAG) Running program."
	@echo "--PHILOSOPHERS--rvaz------START-\n"
	@./$(NAME) 1 100000 200 200 1
	@echo "\n--PHILOSOPHERS--rvaz------END-"
	@make clean

.PHONY: all clean fclean re