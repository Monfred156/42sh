##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	= 42sh

CC	= gcc

RM	= rm -f

SRCS	=		./src/main.c			\
                ./src/history.c			\
    			./src/42sh.c			\
    			./src/parse_string.c	\
    			./src/str_clean.c		\
    			./src/remove_n.c		\
    			./src/env.c				\
				./src/shell_excve.c		\
				./src/fill_array_pars.c \
				./src/exit.c            \
				./src/error_handling.c  \
				./src/search_function.c	\

OBJS	=	$(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra -Wno-unused -g

all: $(NAME)

$(NAME):	$(OBJS)
			make -C ./lib/my
			$(CC) $(OBJS) -o $(NAME) $(LDFLAGS) -L./lib/my -lmy
			@echo -e "\033[32mCOMPILED WITH SUCCESS\033[42m"

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)
	@echo -e "\033[36m[SRC] [COMPILED]\033[0m.......$<"

clean:
	@make clean -C ./lib/my
	@$(RM) $(OBJS)

fclean: clean
	@make fclean -C ./lib/my
	$(RM) $(NAME)

re: fclean all
