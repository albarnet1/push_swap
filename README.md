*This project has been created as part of the 42 curriculum by albarnet, dakuznet.*

# Push_swap

## Description

Ft_printf is the second project of the core of the curriculum. The goal is to rebuild the printf function from `stdio.h`, using your libft functions along with new functions or rebuilt functions from libft. The library is reused in later projects, so it helps you throughout the curriculum.

The project teaches:
- Working with functions that make use of variadic variables `f(a, ...)`
- Working with `va_start`, `va_list`, `va_end` and `va_arg`
- Writing code under the 42 Norm
- Building a static library with a Makefile

## sorting algorithms and reasoning
- for the simple algorithm we used selection sort because ...
-
-
-

## Contents

### Libft functions
**Part 1: libc functions.** Reimplementations of standard functions, such as:
- Character checks and conversions: `ft_isalpha`, `ft_isdigit`, `ft_toupper`, `ft_tolower`, ...
- String functions: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strnstr`, `ft_strncmp`, `ft_atoi`, ...
- Memory functions: `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_bzero`, `ft_calloc`, ...

**Part 2: additional functions.** Utilities that are not in libc or are in a different form: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, and the `ft_put*_fd` output functions.

**Part 3: linked lists.** A `t_list` structure and its functions: `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.

### ft_printf functions
These are functions made to make ft_printf work:
- `ft_printf`
- `ft_putnbr_base`, `ft_putnbr_base_uns` (for the unsigned conversions), `ft_putptr`


## Instructions

```bash
make          # builds libftprintf.a
make clean    # removes object files
make fclean   # removes object files and libftprintf.a
make re       # fclean + make
```

The library is compiled with `cc -Wall -Wextra -Werror`.

## Resources

- `man` pages for the libft functions being reimplemented
- The 42 Norm and the ft_printf subject PDF
- (https://GeeksforGeeks.org)(https://w3schools.com) informational C blogs
- (https://pythontutor.com) a visual debugger for smaller snippets of code
- (https://github.com) for Francinette and for reference pages to learn how certain applications of code work better than others.
- Peer-learning and peer-review with fellow Codam students

### Use of AI

AI tools were used only as a support for understanding concepts and reviewing ideas (e.g. discussing edge cases and Norm constraints). All code was written, tested, and understood by me, and I can explain and reproduce every function without AI assistance.