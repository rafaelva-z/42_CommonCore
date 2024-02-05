.SILENT:
NAME =		megaphone
CC =		c++
CFLAGS =	-Wall -Wextra -Werror -std=c++98
SRC =		./megaphone.cpp

#=== COLORS ===#

CYAN =		\033[96m
RESET =		\033[0m

TAG =		$(CYAN)[$(NAME)]$(RESET)

#=== RULES ===#

all: $(NAME)

$(NAME): $(SRC)
	@echo "$(TAG) Making Program"
	@$(CC) $(CFLAGS) $(SRC) -o $(NAME)

clean:

fclean: clean
	@echo "$(TAG) Full clean." 
	@rm -f $(NAME)

re: fclean all
	@echo "$(TAG) Recompiling."

.PHONY: all clean fclean re