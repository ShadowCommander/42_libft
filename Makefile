# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jtong <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/09/12 09:44:30 by jtong             #+#    #+#              #
#    Updated: 2021/11/25 12:43:26 by jtong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a
SRC := ft_abs ft_atoi ft_bzero ft_intlen ft_isalnum ft_isalpha ft_isascii ft_isdigit ft_islower ft_isnum ft_isprint ft_isspace ft_isupper ft_itoa_base ft_itoa ft_listadd ft_listclear ft_listdelete ft_listfind ft_listfiter ft_listfree ft_listiter ft_listlop ft_listnew ft_listnode ft_listpop ft_listpush ft_listrm ft_listsort ft_listsrt ft_lstadd ft_lstdel ft_lstdelone ft_lstiter ft_lstmap ft_lstnew ft_lstrm ft_lstsize ft_memalloc ft_memccpy ft_memchr ft_memcmp ft_memcpy ft_memdel ft_memdup ft_memmove ft_memset ft_printbits ft_putchar ft_putchar_fd ft_putendl ft_putendl_fd ft_putnbr ft_putnbr_fd ft_putstr ft_putstr_fd ft_putull_fd ft_strcat ft_strchr ft_strclr ft_strcmp ft_strcpy ft_strdel ft_strdup ft_strequ ft_striter ft_striteri ft_strjoin ft_strnjoin ft_strlcat ft_strlcpy ft_strlen ft_strmap ft_strmapi ft_strncat ft_strncmp ft_strncpy ft_strndup ft_strnequ ft_strnew ft_strnstr ft_strrchr ft_split ft_strsplit ft_strstr ft_strsub ft_strtol ft_strtrim ft_tolower ft_toupper ft_ulltoa_base ft_wordcount get_next_line
CC := clang
HEADERDIRS := .
FILES := $(addsuffix .c,$(SRC))
OBJ := $(FILES:.c=.o)
HEADERFLAGS := $(addprefix -I,$(HEADERDIRS))
OFLAGS := $(HEADERFLAGS)
CCFLAGS := -Werror -Wall -Wextra -pedantic ${CFLAGS}

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c Makefile
	$(CC) $(OFLAGS) $(CCFLAGS) -c $< -o $@

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME) libft.h.gch

re: fclean all

debug: OFLAGS += -g
debug: $(NAME)

.PHONY: all clean fclean re debug
