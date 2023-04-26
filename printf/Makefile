.SILENT:
NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c ft_nputchar_fd.c ft_nputendl_fd.c ft_nputnbr_fd.c \
	ft_nputstr_fd.c ft_strlen.c ft_nputaddr_fd.c ft_nputhex_fd.c
	
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

.PHONY: all bonus clean fclean re blank
