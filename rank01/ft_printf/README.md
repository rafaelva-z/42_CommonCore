# ft_printf

## Overview

**ft_printf** is a recreation of the standard `printf` function in C. This function was added to my custom C library **libft**, giving me a more efficient way to write on the standard output while also being a helpful tool for the debugging process. Working on this project helped me learn more about formatted output functions, variadic arguments and recursive functions.

## What I Learned

By developing **ft_printf**, I gained several key insights:
- **Variadic Functions**: This project introduced me to variadic arguments using `va_list`, `va_start`, `va_arg`, and `va_end`, which allowed me to process a dynamic number of arguments.
- **Formatted Output**: I learned how to handle various format specifiers (`%s`, `%d`, `%x`, etc.), converting and printing different types of data.
- **Recursive Programming**: In order to handle the process of printing strings of digits (also known as 'a number'), I used recursive algorithms.

## Supported Format Specifiers

The following format specifiers are supported in `ft_printf`:
- `%c`: Prints a single character.
- `%s`: Prints a string.
- `%p`: Prints a memory address in hexadecimal format.
- `%d` / `%i`: Prints a signed decimal integer.
- `%u`: Prints an unsigned decimal integer.
- `%x`: Prints an unsigned hexadecimal integer (lowercase).
- `%X`: Prints an unsigned hexadecimal integer (uppercase).
- `%%`: Prints a literal `%` character.

## Code Structure

The code for **ft_printf** is structured into multiple helper functions for ease of readability and functionality:

- **ft_nputaddr**: Handles printing memory addresses (`%p`).
- **ft_nputchar**: Prints a single character.
- **ft_nputhex**: Recursively prints numbers in hexadecimal format (lowercase: `%x`, uppercase: `%X`).
- **ft_nputnbr**: Recursively prints signed and unsigned integers (`%d`, `%i`, `%u`).
- **ft_nputstr**: Prints strings and handles the case where the string is `NULL`.
- **ft_conversion** (ft_printf.c): Selects the appropriate function based on the format specifier.

The main function, `ft_printf`, uses the `va_list` mechanism (variable argument list) to parse and print a dynamic number of arguments passed to it, according to the format string.

## Using ft_printf

*Note: On the following projects, I merged ft_printf with libft.*

To use `ft_printf` in a project, follow these steps:

1. **Clone the repository**:
    ```bash
    git clone https://github.com/rafaelva-z/42_CommonCore.git
    cd 42_CommonCore/rank01/ft_printf
    ```

2. **Compile the library**:
    ```bash
    make
    ```
    This will generate the `libftprintf.a` library file.

3. **Link the library** to your project by including the `ft_printf.h` header:
    ```c
    #include "ft_printf.h"
    ```

    And compile your project linking against `libftprintf.a`:
    ```bash
    gcc -o my_program my_program.c -L. -lftprintf
    ```
## Final Notes

- This project was developed with the constraints and standards of the **42 School**. As such, no external libraries are used (aside from standard C headers like `<stdlib.h>`, `<unistd.h>` and `<stdarg.h>`).
- The project cannot contain any memory leaks, and must not crash under any circumstance, the code has to be explained to and tested by 3 different evaluators in order for it to be finished.
