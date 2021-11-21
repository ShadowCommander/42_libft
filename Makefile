# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 09:44:30 by jtong             #+#    #+#              #
#    Updated: 2021/11/06 04:48:54 by jtong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SRC := ft_abs.c ft_atoi.c ft_bzero.c ft_intlen.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_islower.c ft_isnum.c ft_isprint.c ft_isspace.c ft_isupper.c ft_itoa_base.c ft_itoa.c ft_listadd.c ft_listclear.c ft_listdelete.c ft_listfind.c ft_listfiter.c ft_listfree.c ft_listiter.c ft_listlop.c ft_listnew.c ft_listnode.c ft_listpop.c ft_listpush.c ft_listrm.c ft_listsort.c ft_listsrt.c ft_lstadd.c ft_lstdel.c ft_lstdelone.c ft_lstiter.c ft_lstmap.c ft_lstnew.c ft_lstrm.c ft_lstsize.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memdel.c ft_memdup.c ft_memmove.c ft_memset.c ft_printbits.c ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c ft_putull_fd.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c ft_strcpy.c ft_strdel.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmap.c ft_strmapi.c ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strndup.c ft_strnequ.c ft_strnew.c ft_strnstr.c ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtol.c ft_strtrim.c ft_tolower.c ft_toupper.c ft_ulltoa_base.c ft_wordcount.c
HEADERDIRS := .
FILES := $(SRC)
OBJ := $(FILES:.c=.o)
CC := clang
HEADERFLAGS := $(addprefix -I,$(HEADERDIRS))
OFLAGS := $(HEADERFLAGS)
CCFLAGS := -Werror -Wall -Wextra -pedantic ${CFLAGS}

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(OFLAGS) $(CCFLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME) libft.h.gch

re: fclean all
