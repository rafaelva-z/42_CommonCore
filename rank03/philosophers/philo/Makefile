.SILENT:

NAME =		philo
CC =		cc
CFLAGS =	-Wall -Wextra -Werror -pthread #-g -fsanitize=thread 
SRC =		./src/main.c ./src/print.c ./src/time.c \
			./src/philo/checks.c ./src/philo/fork_actions.c \
			./src/philo/philo_actions.c ./src/philo/philo.c \
			./src/program/error_man.c ./src/program/memory_man.c \
			./src/program/start_prog.c \
			./src/utils/ft_atoi.c ./src/utils/ft_isdigit.c ./src/utils/ft_strncmp.c

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

$(NAME): $(SRC)
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
#	./philo  philo_nb	time_die	time_eat  time_sleep	times_must_eat
	@./$(NAME)	 5		800			 200		 200			3 
	@echo "\n--PHILOSOPHERS--rvaz------END-"
	@make fclean

.PHONY: all clean fclean re run