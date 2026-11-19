# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: albarnet <albarnet@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/11/05 14:43:11 by albarnet      #+#    #+#                  #
#    Updated: 2026/11/19 14:01:43 by albarnet      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Wextra -Werror
NAME := push_swap
# NAME2 := push_swap.out
FTPRINTFSOURCES := ft_printf_libft/ft_printf.c \
		ft_printf_libft/ft_putnbr_base.c \
		ft_printf_libft/ft_putnbr_base_unsigned.c \
		algorithms.c \
		complex_sort.c \
		ft_disorder.c \
		ft_medium.c \
		ft_onerror_funcs.c \
		list_funcs.c \
		main.c \
		Rules.c
LIBFTSOURCES = ft_printf_libft/Libft/ft_atoi.c ft_printf_libft/Libft/ft_bzero.c ft_printf_libft/Libft/ft_calloc.c \
		ft_printf_libft/Libft/ft_isalnum.c ft_printf_libft/Libft/ft_isalpha.c ft_printf_libft/Libft/ft_isascii.c \
		ft_printf_libft/Libft/ft_isdigit.c ft_printf_libft/Libft/ft_isprint.c ft_printf_libft/Libft/ft_memchr.c \
		ft_printf_libft/Libft/ft_memcmp.c ft_printf_libft/Libft/ft_memcpy.c ft_printf_libft/Libft/ft_memmove.c \
		ft_printf_libft/Libft/ft_memset.c ft_printf_libft/Libft/ft_split.c ft_printf_libft/Libft/ft_strchr.c \
		ft_printf_libft/Libft/ft_strdup.c ft_printf_libft/Libft/ft_strjoin.c ft_printf_libft/Libft/ft_strlcat.c \
		ft_printf_libft/Libft/ft_strlcpy.c ft_printf_libft/Libft/ft_strlen.c ft_printf_libft/Libft/ft_strncmp.c \
		ft_printf_libft/Libft/ft_strnstr.c ft_printf_libft/Libft/ft_strrchr.c ft_printf_libft/Libft/ft_strtrim.c \
		ft_printf_libft/Libft/ft_substr.c ft_printf_libft/Libft/ft_tolower.c ft_printf_libft/Libft/ft_toupper.c \
		ft_printf_libft/Libft/ft_itoa.c ft_printf_libft/Libft/ft_strmapi.c ft_printf_libft/Libft/ft_striteri.c \
		ft_printf_libft/Libft/ft_putchar_fd.c ft_printf_libft/Libft/ft_putstr_fd.c ft_printf_libft/Libft/ft_putendl_fd.c \
		ft_printf_libft/Libft/ft_putnbr_fd.c ft_printf_libft/Libft/ft_lstadd_back.c ft_printf_libft/Libft/ft_lstadd_front.c \
		ft_printf_libft/Libft/ft_lstclear.c ft_printf_libft/Libft/ft_lstdelone.c ft_printf_libft/Libft/ft_lstiter.c \
		ft_printf_libft/Libft/ft_lstlast.c ft_printf_libft/Libft/ft_lstnew.c ft_printf_libft/Libft/ft_lstsize.c \
		ft_printf_libft/Libft/ft_lstmap.c ft_printf_libft/Libft/ft_count.c
LIBFTFOLDER := Libft/$(LIBFTSOURCES)
OBJECTS := $(FTPRINTFSOURCES:.c=.o) $(LIBFTSOURCES:.c=.o)
SUBDIRS := ft_printf_libft/ ft_printf_libft/Libft/
SUBARCHIVES := ft_printf_libft/libftprintf.a ft_printf_libft/Libft/libft.a

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

# %.o : %.c ft_printf_libft/ft_printf.a
# 	$(CC) $(CFLAGS) -I./ft_printf_libft -I./ft_printf_libft/Libft -c $< -o $(NAME)

ft_printf_libft/ft_printf.a:
	$(MAKE) -C $(dir $@)


# ft_printf.o: ft_printf.c
# 	$(CC) $(CFLAGS) -c ft_printf.c -o ft_printf.o

# ft_conversions.o: ft_conversions.c
# 	$(CC) $(CFLAGS) -c ft_conversions.c -o ft_conversions.o

libft: 
	

clean:
	rm -f $(OBJECTS)
	$(MAKE) -C ft_printf_libft clean
	$(MAKE) -C ft_printf_libft/Libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C ft_printf_libft fclean
	$(MAKE) -C ft_printf_libft/Libft fclean

aclean:
	rm -f a.out

re: fclean all
