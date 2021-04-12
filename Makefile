# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 19:24:17 by lrocigno          #+#    #+#              #
#    Updated: 2021/04/11 21:04:51 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

ARSCRIPT = ft_printf_comp

ARCHV = ar -m $(ARSCRIPT)

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
	@echo "\tCompiling libft"
	@mkdir -p $(OUT_PATH)
	@cd $(LIBS_DIR) && make all

name: $(NAME)

$(NAME): $(OUT_FULL)
	@echo "\tGenerating archive script"
	@echo "CREATE $(NAME)" > $(ARSCRIPT)
	@echo "ADDLIB $(LIBS_DIR)/$(LIBS)" > $(ARSCRIPT)
	@echo "ADDMOD $(OUT_FULL)" > $(ARSCRIPT)
	@echo "SAVE" > $(ARSCRIPT)
	@echo "\tDone"
	@echo "\tCreating archive"
	@$(ARCHV) $(ARSCRIPT)
	@echo "\tDeleting script"
	@rm -f $(ARSCRIPT)

$(OUT_FULL): $(SRC_FULL)
	@echo "\tCompiling ft_printf"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

all: makelibft name

clean:
	@echo "\tCleaning objects"
	@rm -rf $(OUT_PATH)
	@rm -f exec
	@cd $(LIBS_DIR) && make clean

fclean:
	@echo "\tCleaning ft_printf"
	@rm -f $(NAME)
	@rm -rf $(OUT_PATH)
	@rm -f exec
	@cd $(LIBS_DIR) && make fclean

re: fclean all

exec: all
	@echo "\tCreating executable"
	@$(CC) $(FLAGS) $(INCLUDES) $(SRC_PATH)/main.c -L. -lftprintf -o exec
	@./exec

.PHONY: all clean fclean re
