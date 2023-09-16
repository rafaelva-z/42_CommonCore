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
Writes a '\n' after the string passed to the designated file descriptor\
*INPUT*		(char *), (int)\
### ft_putchar_fd.c
Writes a given char to the designated file descriptor\
*INPUT*		(char *), (int)\
### ft_putnbr_fd.c
Writes a given int to the designated file descriptor\
*INPUT*		(int), (int)\
### ft_putstr_fd.c
Writes a given string to the designated file descriptor\
*INPUT*		(char *), (int)\
### ft_strcat.c
Concatenates n bytes from s2 to s1\
*INPUT*		(char *), (char *), (unsigned long)\
### ft_strjoin.c
Joins two strings into a new alocated string\
*INPUT*		(char *) string1, (char *) string2\
*RETURN*	(char *) a new string with the contents of str1 followed by the contents in str2\
### ft_strmapi.c
Copies the given string to a newly allocated string using function passed as a parameter and returns it\
*INPUT*		(char *), (char)(*function(unsigned int, char))\
*RETURN*	(char *)\
### ft_strrchr.c
Returns the last occurence of the given int (char) on a string\
*INPUT*		(char *), (int)\
*RETURN*	(char *)\
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
Returns a pointer to the first occurence of int c on the n bytes after the given pointer, or NULL if there is none\
*INPUT*		(void *), (int), (unsigned long)\
*RETURN*	(void *)\
### ft_memset.c
Sets n bytes starting on the given pointer to the given char\
*INPUT*		(void *), (int), (unsigned long)\
*RETURN*	(void *)\
### ft_memcmp.c
Compares n bytes from s1 and s2, and returns the difference of the first different byte (s1 - s2) or 0 if every byte matches\
*INPUT*		(void *), (void *), (int)\
*RETURN*	(int)\
### ft_strtrim.c
Removes each ocurrence of every character of the given character set from the start and end of the given string\
and returns a pointer to the start of the resulting string \
*INPUT*		(char *), (char *)\
*RETURN*	(char *)\
### ft_strnstr.c
### ft_strdup.c
### ft_strlcpy.c
### ft_strncmp.c
### ft_striteri.c
### ft_strlen.c
Returns the amount of characters in a string\
*INPUT*		(char *)\
*RETURN*	(int)\
### ft_strchr.c
Returns a pointer to the first ocurrence of the given int (char) on the given string or NULL if there is none\
*INPUT*		(char *), (int c)\
*RETURN*	(char *)\
### ft_strlcat.c
### ft_strncat.c
### ft_split.c
Splits the given string on every instance of the separator\
*INPUT:*	(char *) string, (char) separator\
*RETURN:*	(char **) an array containing the splitted strings\
### ft_substr.c
### ft_tolower.c
### ft_lstdelone.c
Uses a given function to clear the content of t_list, and frees it\
*INPUT*		(t_list *), (void)(*function(void *))\
### ft_lstnew.c
Creates a new t_list and puts content into it\
*INPUT:*	(void *) content\
*RETURN*	(t_list *) pointer to the allocated list\
### ft_lstadd_front.c
Adds a given t_list to the begining of a given linked list\
*INPUT*		(t_list **), (t_list *)\
### ft_lstadd_back.c
Adds a given t_list to the end of a given linked list\
*INPUT*		(t_list **), (t_list *)\
### ft_lstiter.c
Iterates through every item on the given list and aplies the given function to each items content\
*INPUT*		(t_list *), (void)(*function(void *))\
### ft_lstsize.c
Returns the size of a given linked list\
*INPUT*		(t_list *)\
### ft_lstlast.c
Returns a pointer to the lat item of the linked list\
*INPUT*		(t_list *)\
*RETURN*	(t_list *)\
### ft_lstclear.c
Deletes every item on a linked list using the given function using ft_lstdelone()\
*INPUT*		(t_list **), (void)(*function(void *))\
### ft_lstmap.c

