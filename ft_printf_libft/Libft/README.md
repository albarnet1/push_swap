This project has been created as part of the 42 curriculum by Albarnet.

# Libft

## Description

Libft is the first project of the core of the curriculum. The goal is to build your own C library, reimplementing a set of standard libc functions along with additional utility functions. The library is reused in later projects, so it helps you throughout the curriculum.

The project teaches:
- Manual memory management (`malloc`, `free`) and avoiding leaks
- Pointer arithmetic and working with raw memory
- Writing code under the 42 Norm
- Building a static library with a Makefile

### Contents

**Part 1: libc functions.** Reimplementations of standard functions, such as:
- Character checks and conversions: `ft_isalpha`, `ft_isdigit`, `ft_toupper`, `ft_tolower`, ...
- String functions: `ft_strlen`, `ft_strlcpy`, `ft_strlcat`, `ft_strchr`, `ft_strnstr`, `ft_strncmp`, `ft_atoi`, ...
- Memory functions: `ft_memset`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_bzero`, `ft_calloc`, ...

**Part 2: additional functions.** Utilities that are not in libc or are in a different form: `ft_substr`, `ft_strjoin`, `ft_strtrim`, `ft_split`, `ft_itoa`, `ft_strmapi`, `ft_striteri`, and the `ft_put*_fd` output functions.

**Part 3: linked lists.** A `t_list` structure and its functions: `ft_lstnew`, `ft_lstadd_front`, `ft_lstsize`, `ft_lstlast`, `ft_lstadd_back`, `ft_lstdelone`, `ft_lstclear`, `ft_lstiter`, `ft_lstmap`.

## Instructions

```bash
make          # builds libft.a
make bonus    # this is just here for francinette
make clean    # removes object files
make fclean   # removes object files and libft.a
make re       # fclean + make
```

The library is compiled with `cc -Wall -Wextra -Werror`.

## Resources

- `man` pages for the libc functions being reimplemented
- [The C Programming Language](https://en.wikipedia.org/wiki/The_C_Programming_Language) by Kernighan and Ritchie
- The 42 Norm and the Libft subject PDF
- (https://GeeksforGeeks.org)(https://w3schools.com) informational C blogs
- (https://pythontutor.com) a visual debugger for smaller snippets of code
- (https://github.com) for Francinette and for reference pages to learn how certain applications of code work better than others.
- Youtube videos from Oceano (https://youtube.com/oceano)
- Peer-learning and peer-review with fellow Codam students

### Use of AI

AI tools were used only as a support for understanding concepts and reviewing ideas (e.g. discussing edge cases and Norm constraints). All code was written, tested, and understood by me, and I can explain and reproduce every function without AI assistance.