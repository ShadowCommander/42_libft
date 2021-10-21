# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 09:44:30 by jtong             #+#    #+#              #
#    Updated: 2021/10/21 13:22:57 by jtong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SRC := $(wildcard *.c)
#LIST_FILES
SRC += ft_listadd.c ft_listclear.c ft_listfree.c ft_listlop.c \
	ft_listnew.c ft_listnode.c ft_listpop.c ft_listpush.c ft_listrm.c \
	ft_listsort.c ft_listsrt.c ft_listfind.c
HEADERDIRS := .
FILES := $(SRC)
OBJ := $(FILES:.c=.o)
CC := clang
HEADERFLAGS := $(addprefix -I,$(HEADERDIRS))
OFLAGS := $(HEADERFLAGS)
CFLAGS := -Werror -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(OFLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME) libft.h.gch

re: fclean all
