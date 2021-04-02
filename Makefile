# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 19:24:17 by lrocigno          #+#    #+#              #
#    Updated: 2021/04/01 21:45:35 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADERS = libft.h

HEADERS_PATH = headers/

SRC =	ft_printf.c \
		ft_printf_parser.c \

SRC_PATH = ./src

SRC_FULL = $(addprefix $(SRC_PATH)/, $(SRC))

OUT = $(SRC:.c=.o)

OUT_PATH = ./out

OUT_FULL = $(addprefix $(OUT_PATH)/, $(OUT))

all:
	mkdir -p $(OUT_PATH)
	cd libft && make
	cd ..
	$(CC) $(FLAGS) -I $(HEADERS_PATH) -o $(OUT_FULL) -c $(SRC_FULL)

clean:
	rm -rf $(OUT_PATH)
	cd libft && make clean

fclean: clean
	cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re
