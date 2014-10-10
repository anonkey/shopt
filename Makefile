
ifeq ($(GCC), 1)
    CC = gcc
else
    CC = clang
endif
ifeq ($(DEBUG), 1)
    CFLAGS = -Wall -Wextra -Werror -ggdb3
else
    CFLAGS = -Wall -Wextra -Werror
endif
NAME = shnew
INCDIR = ./libft/headers
LIBDIR = ./libft/
LIBNAME = libft
LIB = -lft
SRC = ft_astnode.c \
ft_lang.c \
ft_lexer.c \
ft_lexfunc_bg.c \
ft_lexfunc_escape.c \
ft_lexfunc_expr.c \
ft_lexfunc_hinib.c \
ft_lexfunc_ifs.c \
ft_lexfunc_inib.c \
ft_lexfunc_listsep.c \
ft_lexfunc_lredir.c \
ft_lexfunc_others.c \
ft_lexfunc_pipe.c \
ft_lexfunc_rredir.c \
ft_lexfunc_termsep.c \
ft_lextools.c \
ft_parser.c \
main.c
OBJ = $(SRC:.c=.o)

all: $(LIBNAME) $(NAME)

$(LIBNAME):
	make -C $(LIBDIR)

$(LIBNAME)_fclean:
	make -C $(LIBDIR) fclean

gcc: $(OBJ)
	gcc $(CFLAGS) -L$(LIBDIR) $(LIB) $(OBJ) -o $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -L$(LIBDIR) $(LIB) $(OBJ) -o $(NAME) -I $(INCDIR)
%.o: %.c
	$(CC) -I$(LIBDIR) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

clean:
	rm -rf $(OBJ)

fclean: $(LIBNAME)_fclean clean
	rm -rf $(NAME)

re: $(LIBNAME)_fclean fclean all

.PHONY: $(LIBNAME) $(LIBNAME)_fclean clean fclean all re