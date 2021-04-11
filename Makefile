# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 19:24:17 by lrocigno          #+#    #+#              #
#    Updated: 2021/04/11 19:03:55 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

ARSCRIPT = ft_printf_comp

ARCHV = ar -M $(ARSCRIPT)

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

$(NAME): $(OUT_FULL)
	@echo "CREATE $(NAME)" > $(ARSCRIPT)
	@echo "ADDLIB $(LIBS_DIR)/$(LIBS)" > $(ARSCRIPT)
	@echo "ADDMOD $(OUT_FULL)" > $(ARSCRIPT)
	@echo "SAVE" > $(ARSCRIPT)
	@$(ARCHV) $(ARSCRIPT)
	@rm -f $(ARSCRIPT)

$(OUT_FULL): $(SRC_FULL)
	@cd $(LIBS_DIR) && make
	@cd ../..
	@mkdir $(OUT_PATH)
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

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
	@$(CC) $(FLAGS) $(INCLUDES) $(SRC_PATH)/main.c -L. -lprintf -o exec
	@./exec

.PHONY: all clean fclean re
