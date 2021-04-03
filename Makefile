# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 19:24:17 by lrocigno          #+#    #+#              #
#    Updated: 2021/04/03 14:39:35 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADERS = libft.h

HEADERS_PATH = headers/

LIB = libft/libft.a

SRC =	ft_printf.c \
		ft_printf_parser.c \

SRC_PATH = ./src

SRC_FULL = $(addprefix $(SRC_PATH)/, $(SRC))

OUT = $(SRC:.c=.o)

OUT_PATH = ./out

OUT_FULL = $(addprefix $(OUT_PATH)/, $(OUT))

LIB_SRC =	libft/src/ft_memset.c \
			libft/src/ft_bzero.c \
			libft/src/ft_memcpy.c \
			libft/src/ft_memccpy.c \
			libft/src/ft_memmove.c \
			libft/src/ft_memchr.c \
			libft/src/ft_memcmp.c \
			libft/src/ft_strlen.c \
			libft/src/ft_strlcpy.c \
			libft/src/ft_strlcat.c \
			libft/src/ft_strchr.c \
			libft/src/ft_strrchr.c \
			libft/src/ft_strnstr.c \
			libft/src/ft_strncmp.c \
			libft/src/ft_atoi.c \
			libft/src/ft_isalpha.c \
			libft/src/ft_isdigit.c \
			libft/src/ft_isalnum.c \
			libft/src/ft_isascii.c \
			libft/src/ft_isprint.c \
			libft/src/ft_toupper.c \
			libft/src/ft_tolower.c \
			libft/src/ft_calloc.c \
			libft/src/ft_strdup.c \
			libft/src/ft_substr.c \
			libft/src/ft_strjoin.c \
			libft/src/ft_strtrim.c \
			libft/src/ft_split.c \
			libft/src/ft_itoa.c \
			libft/src/ft_strmapi.c \
			libft/src/ft_putchar_fd.c \
			libft/src/ft_putstr_fd.c \
			libft/src/ft_putendl_fd.c \
			libft/src/ft_putnbr_fd.c \
			libft/src/ft_lstnew.c \
			libft/src/ft_lstadd_front.c \
			libft/src/ft_lstsize.c \
			libft/src/ft_lstlast.c \
			libft/src/ft_lstadd_back.c \
			libft/src/ft_lstdelone.c \
			libft/src/ft_lstclear.c \
			libft/src/ft_lstiter.c \
			libft/src/ft_lstmap.c \
			libft/src/ft_dtox.c \
			libft/src/ft_reallocncat.c \
			libft/src/ft_strhvchr.c \
			libft/src/ft_intlen.c \

all: $(LIB)

$(LIB) : $(OUT_FULL)
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
	echo "Not the best way of doing things"
	$(CC) $(FLAGS) -I $(HEADERS_PATH) $(SRC_PATH)/main.c $(SRC_FULL) $(LIB_SRC) -o exec
	./exec
	rm -f exec

.PHONY: all clean fclean re
