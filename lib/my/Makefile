##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## task01 CPool_Day10_2018
##

SRC	=	my_putstr.c				\
		my_putchar.c			\
		my_strlen.c				\
		my_strcmp.c				\
		my_realloc.c			\
		array_len.c				\
		my_put_nbr.c			\
		my_str_to_word_array.c	\
		check_malloc.c			\
		my_putstr_error.c		\
		my_str_copy.c			\
		add_chars_after_str.c	\
		add_chars_before_str.c	\
		my_free.c				\
		my_str_count.c			\
		my_strncmp.c			\
		my_strdup.c				\
		my_strcat.c				\
		cpy_array.c				\
		print_error_exec.c		\
		detect_exec.c			\
		my_str_isnum.c			\
		my_realloc_array.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS  =   -I ../../include
CFLAGS += -W -Wall -Wextra -Wno-unused -g

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo -e "\033[33m[LIB] [COMPILED]\033[0m.......$<"

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
