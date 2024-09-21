# Libft - C Library Implementation

## Overview

The first project of the 42 curriculum (common core) introduced the basics of the C programming language. The goal was to write several standard library functions from scratch, adhering to their original behavior as defined in the C Standard Library (`libc`). This custom library, contains functions that convert, seek and manipulate memory, characters (that are values in memory) and strings (which is basically a group of characters). By building these functions, I gained a better understanding into low-level programming concepts, memory management, and algorithm optimization.

## Function List

### **Memory Functions**
Functions for allocating, copying, moving, and zeroing memory.
- `ft_bzero`: Set a block of memory to zero (null bytes).
- `ft_calloc`: Allocate and initialize memory, setting it to zero.
- `ft_memset`: Fill a block of memory with a specific value.
- `ft_memcpy`: Copy a block of memory from one location to another.
- `ft_memmove`: Safely copy a block of memory from one location to another, even if they overlap.
- `ft_memchr`: Search for a byte within a block of memory.
- `ft_memcmp`: Compare two blocks of memory.

### **String Functions**
Functions to handle and modify strings.
- `ft_strlen`: Calculate the length of a string.
- `ft_strcpy`: Copy a string to another buffer.
- `ft_strncpy`: Copy a specific number of characters from one string to another.
- `ft_strchr`: Locate a character in a string.
- `ft_strdup`: Duplicate a string by allocating memory for the new copy.
- `ft_strcat`: Concatenate two strings.
- `ft_strncat`: Concatenate a specified number of characters from one string to another.
- `ft_strlcat`: Concatenate two strings safely by preventing buffer overflow.
- `ft_strrchr`: Locate the last occurrence of a character in a string.
- `ft_strcmp`: Compare two strings lexicographically.
- `ft_strncmp`: Compare a specified number of characters of two strings.
- `ft_strnstr`: Find a substring in a string within a limited number of characters.
- `ft_strlcpy`: Copy a string to a buffer while preventing buffer overflow.
- `ft_strjoin`: Concatenate two strings into a newly allocated string.
- `ft_striteri`: Apply a function to each character of a string, passing its index as the first argument.
- `ft_split`: Split a string into an array of substrings based on a given delimiter.

### **Character Functions**
Functions that check or convert the given character.
- `ft_isalpha`: Check if a character is alphabetic.
- `ft_isdigit`: Check if a character is a digit.
- `ft_isalnum`: Check if a character is alphanumeric.
- `ft_isascii`: Check if a character belongs to the ASCII set.
- `ft_isprint`: Check if a character is printable.
- `ft_tolower`: Convert an uppercase character to lowercase.
- `ft_toupper`: Convert a lowercase character to uppercase.

### **Conversion Functions**
Functions that convert data between incompatible types
- `ft_atoi`: Convert a string to an integer.
- `ft_itoa`: Convert an integer to a string.

### **Output Functions**
Output data to the provided file discriptor.
- `ft_putchar_fd`: Output a character to a given file descriptor.
- `ft_putstr_fd`: Output a string to a given file descriptor.
- `ft_putendl_fd`: Output a string followed by a newline to a given file descriptor.
- `ft_putnbr_fd`: Output an integer to a given file descriptor.

### **Linked List Functions**
Linked list operations, such as creating, adding, deleting, and iterating through nodes.
- `ft_lstnew`: Create a new node for a linked list.
- `ft_lstadd_front`: Add a new node to the front of the list.
- `ft_lstadd_back`: Add a new node to the end of the list.
- `ft_lstsize`: Count the number of nodes in a list.
- `ft_lstlast`: Get the last node of a list.
- `ft_lstdelone`: Delete a single node from a list.
- `ft_lstclear`: Delete all nodes from a list.
- `ft_lstiter`: Apply a function to each node in a list.
- `ft_lstmap`: Apply a function to each node and create a new list with the results.

## Using Libft

To use `libft` in a project, follow these steps:

1. **Clone the repository**:
    ```bash
    git clone https://github.com/rafaelva-z/42_CommonCore.git
    cd 42_CommonCore/rank01/libft
    ```

2. **Compile the library**:
    ```bash
    make
    ```
    This will generate the `libft.a` library file.

3. **Link the library** to your project by including the `libft.h` header:
    ```c
    #include "libft.h"
    ```

    And compile your project linking against `libft.a`:
    ```bash
    gcc -o my_program my_program.c -L. -lft
    ```

## Final Notes

- This project was developed with the constraints and standards of the **42 School**. As such, no external libraries are used (aside from standard C headers like `<stdlib.h>` and `<unistd.h>`).
- The project cannot contain any memory leaks, and must not crash under any circumstance, the code has to be explained to and tested by 3 different evaluators in order for it to be finished.
