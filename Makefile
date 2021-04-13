# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 19:24:17 by lrocigno          #+#    #+#              #
#    Updated: 2021/04/13 12:41:41 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

BIN = ftprintf

ARCHV = ar -rcs

LIBS = libft.a \

LIBS_DIR = ./libs/libft

HEADERS = ft_printf.h \
		  libft.h \

INCLUDES_PATH =	./ \
				$(LIBS_DIR) \

INCLUDES = $(foreach i, $(INCLUDES_PATH), -I $(i))

SRC =	ft_printf.c \
		pf_fspec_utils.c \
		pf_parser.c \

SRC_PATH = ./src

SRC_FULL = $(addprefix $(SRC_PATH)/, $(SRC))

OUT = $(SRC:.c=.o)

OUT_PATH = ./out

OUT_FULL = $(addprefix $(OUT_PATH)/, $(OUT))

$(NAME): makedeps $(OUT_FULL)
	cp $(LIBS_DIR)/$(LIBS) ./$(NAME)
	$(ARCHV) $(NAME) $(OUT_FULL)

makedeps:
	@make -C $(LIBS_DIR)
	@mkdir -p $(OUT_PATH)

$(OUT_FULL): $(SRC_FULL)
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

all: $(NAME)

clean:
	@rm -rf $(OUT_PATH)
	@rm -f exec
	@make -C $(LIBS_DIR) clear

fclean:
	@rm -f exec
	@rm -f $(NAME)
	@rm -rf $(OUT_PATH)
	@make -C $(LIBS_DIR) fclean

re: fclean all

exec: all
	$(CC) $(FLAGS) $(INCLUDES) $(SRC_PATH)/main.c -L. -lftprintf -o $(BIN)

.PHONY: all clean fclean re exec makedeps
