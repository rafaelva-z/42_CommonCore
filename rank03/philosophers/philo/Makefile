.SILENT:

NAME =		philo
CC =		cc
CFLAGS =	-pthread -Wall -Wextra -Werror -g #-fsanitize=address 
SRC =		./src/*.c ./src/philo/*.c ./src/program/*.c ./src/utils/*.c #./src/arg.c ./src/ft_atoi.c ./src/main.c ./src/time.c ./src/ft_isdigit.c
#OBJ = 		$(SRC:.c=.o)

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

$(NAME): $(SRC) #$(OBJ)
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
	#./philo  philo_nb	time_die	time_eat  time_sleep	times_must_eat
	@./$(NAME)	 5		800			 200		 200			 
	#	TEST THIS WHITH 0 PHILS
	@echo "\n--PHILOSOPHERS--rvaz------END-"
	@make fclean

.PHONY: all clean fclean re