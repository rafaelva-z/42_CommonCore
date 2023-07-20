# Libft
C library composed of 45 functions that will be used during the course + some functions that i found to be useful in different situations. At 42, most functions are forbidden, and besides some exceptions like malloc and free, if i need a function i will have to make it.

# Functions
### ft_atoi.c
Convert a string to an int, ignoring all spaces before the number, and stopping at the first character that isn't a digit, '+' or '-'.\
*INPUT:*	(char *) number in string format to be converted.\
*RETURN:*	the string given as an int.\
### ft_itoa.c
Convert an int to a string.\
*INPUT:*	(int) to be converted.\
*RETURN:*	(char *) pointer to the converted value.\
### ft_isalpha.c
Checks if the char given as input represents a letter.\
*INPUT:*	(char) to be checked.\
*RETURN:*	1 if the input value represents a letter, 0 if it doesn't.\
### ft_isdigit.c
Checks if the char given as input represents a number.\
*INPUT:*	(char) to be checked.\
*RETURN:*	1 if the input value represents a number, 0 if it doesn't.\
### ft_isalnum.c
Checks if the char given as input represents a number or a letter.\
*INPUT:*	(char) to be checked.\
*RETURN:*	1 if the input value represents a number or a letter, 0 if it doesn't.\
### ft_isprint.c
Checks if the char given as input represents a printable character.\
*INPUT:*	(char) to be checked.\
*RETURN:*	1 if the input value represents a printable character, 0 if it doesn't.\
### ft_isascii.c
Checks if the char given as input represents a printable character.\
*INPUT:*	(char) to be checked.\
*RETURN:*	1 if the input value represents an ascii character, 0 if it doesn't.\
### ft_putendl_fd.c
Sends a '\n' to the designated file descriptor\
*INPUT*		(char *), (int)
*RETURN*	
### ft_putchar_fd.c
### ft_putnbr_fd.c
### ft_putstr_fd.c
### ft_putchar_fd.c
### ft_strcat.c
### ft_strjoin.c
Joins two strings into a new alocated string\
*INPUT*		(char *) string1, (char *) string2\
*RETURN*	(char *) a new string with the contents of str1 followed by the contents in str2\
### ft_strmapi.c
### ft_strrchr.c
### ft_toupper.c
Returns the given character in uppercase\
*INPUT*		(char)\
*RETURN*	(char) uppercase character or same char if it doesn't correspond to a lowercase letter\
### ft_bzero.c
Clears the memory on n bytes starting on the given pointer\
*INPUT*		(void *) adress to clear, (unsigned int) number of bytes to clear\
*RETURN*	_no return value_\
### ft_calloc.c
Alocates memory, and sets it to '\0'\
*INPUT:*	(int) amount of slots, (int) size of slots in bytes\
*RETURN:*	(void *) pointer to the address of the alocated memory.\
### ft_memcpy.c
Copies n bytes from source to destination.\
*INPUT*		(void *) destination pointer, (void *) source pointer, (unsigned int) number of bytes\
*RETURN*	(void *) destination pointer\
### ft_memmove.c
Copies n bytes from source to destination, both objects may overlap and nothing will be lost, as opposed to ft_memcpy\
*INPUT*		(void *) destination pointer, (void *) source pointer, (unsigned int) number of bytes\
*RETURN*	(void *) destination pointer\
### ft_memchr.c
### ft_memset.c
### ft_memcmp.c
### ft_putnbr_fd.c
### ft_putchar_fd.c
### ft_putstr_fd.c
### ft_strtrim.c
### ft_strnstr.c
### ft_strdup.c
### ft_strlcpy.c
### ft_strncmp.c
### ft_striteri.c
### ft_strlen.c
### ft_strchr.c
### ft_strlcat.c
### ft_strncat.c
### ft_split.c
Splits the given string on every instance of the separator
*INPUT:*	(char *) string, (char) separator\
*RETURN:*	(char **) an array containing the splitted strings
### ft_substr.c
### ft_tolower.c
### ft_lstdelone.c
### ft_lstnew.c
Creates a new t_list and puts content into it
*INPUT:*	(void *) content
*RETURN*	(t_list *) pointer to the allocated list
### ft_lstadd_front.c
### ft_lstadd_back.c
### ft_lstiter.c
### ft_lstsize.c
### ft_lstlast.c
### ft_lstclear.c
### ft_lstmap.c

