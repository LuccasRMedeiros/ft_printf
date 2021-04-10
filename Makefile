# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 19:24:17 by lrocigno          #+#    #+#              #
#    Updated: 2021/04/09 21:48:04 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADERS = ft_printf.h

HEADERS_PATH = ./

SRC =	ft_printf.c \
		pf_parser.c \

SRC_PATH = ./src

SRC_FULL = $(addprefix $(SRC_PATH)/, $(SRC))

OUT = $(SRC:.c=.o)

OUT_PATH = ./out

OUT_FULL = $(addprefix $(OUT_PATH)/, $(OUT))

LIBS =	ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strlen.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_calloc.c \
		ft_strdup.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_strtrim.c \
		ft_split.c \
		ft_itoa.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_lstnew.c \
		ft_lstadd_front.c \
		ft_lstsize.c \
		ft_lstlast.c \
		ft_lstadd_back.c \
		ft_lstdelone.c \
		ft_lstclear.c \
		ft_lstiter.c \
		ft_lstmap.c \
		ft_dtox.c \
		ft_reallocncat.c \
		ft_intlen.c \
		ft_ltoa.c \
		ft_ltox.c \
		ft_utoa.c \

LIBS_PATH = libs/libft/src

LIBS_FULL = $(addprefix $(LIBS_PATH)/, $(LIBS))

all: $(LIBS_FULL)

$(LIBS_FULL) : $(OUT_FULL)
	cd libft && make

$(OUT_FULL): $(SRC_FULL)
	mkdir -p $(OUT_PATH)
	$(CC) $(FLAGS) -I $(HEADERS_PATH) -o $@ -c $<

clean:
	rm -rf $(OUT_PATH)
	cd libft && make clean

fclean:
	rm -rf $(OUT_PATH)
	cd libft && make fclean

re: fclean all

exec:
	echo "Not the best way of to do things"
	$(CC) $(FLAGS) -I $(HEADERS_PATH) $(SRC_PATH)/main.c $(SRC_FULL) $(LIB_SRC) -o exec
	./exec
	rm -f exec

.PHONY: all clean fclean re
