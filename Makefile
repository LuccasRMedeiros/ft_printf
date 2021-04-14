# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 19:24:17 by lrocigno          #+#    #+#              #
#    Updated: 2021/04/13 21:58:38 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

BIN = ftprint

MSG_DONE = echo "-- Done!\n"

ARCHV = ar -rcs

LIBS = libft.a \

LIBS_DIR = ./libs/libft

HEADERS = ft_printf.h \
		  libft.h \

INCLUDES_PATH =	./\
				$(LIBS_DIR)\

INCLUDES = $(foreach i, $(INCLUDES_PATH), -I $(i))

SRC =	ft_printf.c \
		pf_newfspec.c \
		pf_delfspec.c \
		pf_parser.c \
		pf_textformat.c \

SRC_PATH = ./src

SRC_FULL = $(addprefix $(SRC_PATH)/, $(SRC))

OBJ = $(SRC:%.c=%.o)

OBJ_PATH = ./out

OBJ_FULL = $(addprefix $(OBJ_PATH)/, $(OBJ))

makedeps:
	@echo "-- Creating ft_printf dependencies"
	@make -C $(LIBS_DIR) all
	@mkdir -p $(OBJ_PATH)

$(NAME): makedeps $(OBJ_FULL)
	@echo "-- Creating static library FTPRINTF"
	@cp $(LIBS_DIR)/$(LIBS) ./$(NAME)
	@$(ARCHV) $(NAME) $(OBJ_FULL)
	@$(MSG_DONE)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo "-- Compiling $@"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

all: $(NAME)

clean:
	@echo "-- Removing ft_printf objects"
	@rm -rf $(OBJ_PATH)
	@rm -f $(BIN)
	@$(MSG_DONE)
	@make -C $(LIBS_DIR) clear

fclean:
	@echo "-- Removing everything of ft_printf"
	@echo "NOTE: source code will be preserved"
	@rm -f exec
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)
	@$(MSG_DONE)
	@make -C $(LIBS_DIR) fclean

re: fclean all

exec: all
	@echo "-- Compiling executable"
	@$(CC) $(FLAGS) $(INCLUDES) $(SRC_PATH)/main.c -L. -lftprintf -o $(BIN)
	@echo "To use it call ./$(BIN)"
	@$(MSG_DONE)

.PHONY: all clean fclean re exec makedeps
