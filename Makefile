# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 19:24:17 by lrocigno          #+#    #+#              #
#    Updated: 2021/04/12 18:30:33 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

ARSCRIPT = ft_printf_comp

ARCHV = ar -rcs

LIBS = libft.a

LIBS_DIR = ./libs/libft

LIBSHORT = ft

HEADERS = ft_printf.h \
		  libft.h \

INCLUDES_PATH =	./ \
				./libs/libft \

INCLUDES = $(foreach i, $(INCLUDES_PATH), -I $(i))

SRC =	ft_printf.c \
		pf_fspec_utils.c \
		pf_parser.c \

SRC_PATH = ./src

SRC_FULL = $(addprefix $(SRC_PATH)/, $(SRC))

OUT = $(SRC:.c=.o)

OUT_PATH = ./out

OUT_FULL = $(addprefix $(OUT_PATH)/, $(OUT))

makelibft:
	@make -C $(LIBS_DIR)

$(NAME): makelibft $(OUT_FULL)
	@$(ARCHV) $(NAME) $(OUT_FULL)
	@cp $(LIBS_DIR)/$(LIBS) ./$(NAME)

$(OUT_FULL): $(SRC_FULL)
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $< -L$(LIBS_DIR) -l$(LIBSHORT)

all: $(NAME)

clean:
	@rm -rf $(OUT_PATH)
	@rm -f exec
	@cd $(LIBS_DIR) && make clean

fclean:
	@rm -f $(NAME)
	@rm -rf $(OUT_PATH)
	@rm -f exec
	@cd $(LIBS_DIR) && make fclean

re: fclean all

exec: all
	@$(CC) $(FLAGS) $(INCLUDES) $(SRC_PATH)/main.c -L. -lftprintf -o exec

.PHONY: all clean fclean re
