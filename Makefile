##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

NAME	= 42sh

CC	= gcc

RM	= rm -f

SRCS	=		./src/main.c		            	\
                ./src/history.c			            \
    			./src/main_42sh.c			        \
    			./src/parse_string.c	            \
    			./src/str_clean.c		            \
    			./src/remove_n.c		            \
    			./src/env.c				            \
				./src/shell_excve.c		            \
				./src/fill_array_pars.c             \
				./src/exit.c                        \
				./src/error_handling.c              \
				./src/search_function.c         	\
				./src/replace_environnement_var.c   \
				./src/all_redir.c                   \
				./src/free.c                        \
				./src/parser_and_or_semicolon.c     \
				./src/get_array_from_and_or_final.c \
				./src/pipe.c                        \
				./src/create_argv.c					\
				./src/setenv.c                      \
				./src/get_env.c                     \
				./src/unsetenv.c                    \
				./src/cd.c                          \
				./src/cd_minus.c                    \
				./src/error_check_arg.c				\
				./src/recup_str.c					\
				./src/init.c						\
				./src/echo.c						\

OBJS	=	$(SRCS:.c=.o)

CFLAGS = -I ./include/
CFLAGS += -W -Wall -Wextra -Wno-unused

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

clean_test:
	rm ./src/*.gcda
	rm ./src/*.gcno

re: fclean all
