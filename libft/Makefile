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
LDFLAGS = rc
NAME = libft.a
SRC = btree/ft_btree.c \
      btree/ft_btree_put.c \
      chars/ft_isalnum.c \
      chars/ft_isalpha.c \
      chars/ft_isascii.c \
      chars/ft_isdigit.c \
      chars/ft_isprint.c \
      chars/ft_tolower.c \
      chars/ft_toupper.c \
      dynstr/ft_dynstradd.c \
      dynstr/ft_dynstrdel.c \
      dynstr/ft_dynstrflush.c \
      dynstr/ft_dynstrnew.c \
      dynstr/ft_dynstrput.c \
      inputs/ft_getchar.c \
      inputs/get_next_line.c \
      integers/ft_atoi_base.c \
      integers/ft_atoi.c \
      integers/ft_itoa.c \
      ldcd/ft_ldcdat.c \
      ldcd/ft_ldcd_celldel.c \
      ldcd/ft_ldcd_cellnew.c \
      ldcd/ft_ldcddel.c \
      ldcd/ft_ldcddel_head.c \
      ldcd/ft_ldcddel_tail.c \
      ldcd/ft_ldcditer.c \
      ldcd/ft_ldcdnew.c \
      ldcd/ft_ldcdpop_back.c \
      ldcd/ft_ldcdpop.c \
      ldcd/ft_ldcdpop_front.c \
      ldcd/ft_ldcdpush_back.c \
      ldcd/ft_ldcdpush_front.c \
      ldcd/ft_ldcdpush_sorted.c \
      ldcd/ft_ldcdsize.c \
      ldcd/ft_ldcdsize_ref.c \
      ldcd/ft_putldcd.c \
      lists/ft_lstadd.c \
      lists/ft_lstdel.c \
      lists/ft_lstdelone.c \
      lists/ft_lstiter.c \
      lists/ft_lstmap.c \
      lists/ft_lstnew.c \
      lists/ft_lstsize.c \
      lists/ft_lsttotab.c \
      memory/ft_bzero.c \
      memory/ft_memalloc.c \
      memory/ft_memccpy.c \
      memory/ft_memchr.c \
      memory/ft_memcmp.c \
      memory/ft_memcpy.c \
      memory/ft_memdel.c \
      memory/ft_memdup.c \
      memory/ft_memmove.c \
      memory/ft_memset.c \
      memory/ft_print_memory.c \
      outputs/ft_putchar.c \
      outputs/ft_putchar_fd.c \
      outputs/ft_putdouble.c \
      outputs/ft_putdouble_sci.c \
      outputs/ft_putendl.c \
      outputs/ft_putendl_fd.c \
      outputs/ft_putldouble.c \
      outputs/ft_putldouble_sci.c \
      outputs/ft_putnbr_base.c \
      outputs/ft_putnbr.c \
      outputs/ft_putnbr_fd.c \
      outputs/ft_putnbrhex.c \
      outputs/ft_putnbr_len.c \
      outputs/ft_putnbr_ll.c \
      outputs/ft_putnbr_oct.c \
      outputs/ft_putnbr_ulen.c \
      outputs/ft_putnbr_ull.c \
      outputs/ft_putstr.c \
      outputs/ft_putstr_fd.c \
      outputs/ft_putstr_len.c \
      printf/ft_printf.c \
      printf/ft_printfn.c \
      printf/ft_readarg.c \
      printf/ft_readautom.c \
      printf/ft_readchar.c \
      printf/ft_readfloat.c \
      printf/ft_readfloat_len.c \
      printf/ft_readint.c \
      printf/ft_readint_len.c \
      printf/ft_readpoint.c \
      printf/ft_readstr.c \
      string/ft_strcat.c \
      string/ft_strchind.c \
      string/ft_strchr.c \
      string/ft_strclr.c \
      string/ft_strcmp.c \
      string/ft_strcpy.c \
      string/ft_strcsub.c \
      string/ft_strdel.c \
      string/ft_strdup.c \
      string/ft_strequ.c \
      string/ft_striter.c \
      string/ft_striteri.c \
      string/ft_strjoin.c \
      string/ft_strlcat.c \
      string/ft_strlen.c \
      string/ft_strmap.c \
      string/ft_strmapi.c \
      string/ft_strncat.c \
      string/ft_strncmp.c \
      string/ft_strncpy.c \
      string/ft_strnequ.c \
      string/ft_strnew.c \
      string/ft_strnstr.c \
      string/ft_strrchind.c \
      string/ft_strrchr.c \
      string/ft_strrev.c \
      string/ft_strsepjoin.c \
      string/ft_strsplit.c \
      string/ft_strstr.c \
      string/ft_strsub.c \
      string/ft_strtabcpy.c \
      string/ft_strtabdel.c \
      string/ft_strtabrealloc.c \
      string/ft_strtrim.c
OBJ = $(SRC:.c=.o)
	HEADERS = headers/
	SRCDIR = srcs/


all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(LDFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS) -I$(HEADERS)

.PHONY: clean fclean all re $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
