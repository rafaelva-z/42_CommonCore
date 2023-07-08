.SILENT:
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c \
	ft_isascii.c ft_isdigit.c ft_isprint.c ft_itoa.c ft_memchr.c \
	ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c ft_putchar_fd.c \
	ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_split.c \
	ft_strcat.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
	ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncat.c \
	ft_strncmp.c ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c \
	ft_tolower.c ft_toupper.c

SRC_BONUS = ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c \
	ft_lstdelone.c ft_lstiter.c \
	ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJ = $(SRC:.c=.o)
OBJ_BONUS = $(SRC_BONUS:.c=.o)

#=== COLORS ===#

RED = \033[0;31m
GREEN = \033[0;92m
YELLOW = \033[93m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[96m
RESET = \033[0m

TAG = $(CYAN)[libft]$(RESET)

#=== RULES ===#

all: $(NAME)

$(NAME): $(OBJ)
	@echo "$(TAG) Making library"
	@ar rs $(NAME) $(OBJ)

bonus: $(OBJ_BONUS)
	@echo "$(TAG) Making library (Bonus)"
	@ar rs $(NAME) $(OBJ_BONUS)

clean:
	@echo "$(TAG) Cleaning all object files."
	@rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	@echo "$(TAG) Full clean."  
	@rm -f $(NAME)

re: fclean all
	@echo "$(TAG) Recompiling."  

.PHONY: all bonus clean fclean re