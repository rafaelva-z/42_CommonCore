.SILENT:
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_nputchar_fd.c ft_nputnbr_fd.c ft_nputstr_fd.c \
	ft_strlen.c ft_nputaddr_fd.c ft_nputhex_fd.c
	
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
