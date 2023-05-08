.SILENT:
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_nputchar.c ft_nputnbr.c ft_nputstr.c \
	ft_nputaddr.c ft_nputhex.c
	
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(NAME) - Making library"
	@ar rsc $(NAME) $(OBJ)

clean:
	@echo "$(NAME) - Cleaning all object files."
	@rm -f $(OBJ)

fclean: clean
	@echo "$(NAME) - Full clean."  
	@rm -f $(NAME)

re: fclean all
	@echo "$(NAME) - Recompiling."  

.PHONY: all clean fclean re
