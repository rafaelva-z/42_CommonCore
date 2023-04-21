.SILENT:
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
	ft_putstr_fd.c

SRC_BONUS = blank
OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME) clean

$(NAME): $(OBJ)
	@echo "$(NAME) - Making library"
	@ar rs $(NAME) $(OBJ)

bonus: $(OBJ_BONUS)
	@echo "$(NAME) - Making library (Bonus)"
	@ar rs $(NAME) $(OBJ_BONUS)

clean:
	@echo "$(NAME) - Cleaning all object files."
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@echo "$(NAME) - Full clean."  
	@rm -f $(NAME)

re: fclean all
	@echo "$(NAME) - Recompiling."  

.PHONY: all bonus clean fclean re
