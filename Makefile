# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocignoS <lrocigno@student.42sp.org.br    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/01 19:24:17 by lrocigno          #+#    #+#              #
#    Updated: 2021/05/09 01:01:48 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

BIN = debugf

MSG_DONE = echo "-- Done!\n"

ARCHV = ar -rcs

LIBS = libft.a \

LIBS_DIR = ./libs/libft

LIBS_RULE = all

HEADERS = ft_printf.h \
		  libft.h \

INCLUDES_PATH =	./\
				$(LIBS_DIR)/headers/\

INCLUDES = $(foreach i, $(INCLUDES_PATH), -I $(i))

SRC =	ft_printf.c \
		pf_error.c \
		pf_newfspec.c \
		pf_delfspec.c \
		pf_txtparser.c \
		pf_numparser.c \
		pf_refine_weights.c\
		pf_refine_long_weights.c\
		pf_textformat.c \
		pf_settype.c \

SRC_PATH = ./src

SRC_FULL = $(addprefix $(SRC_PATH)/, $(SRC))

OBJ = $(SRC:%.c=%.o)

OBJ_PATH = ./out

OBJ_FULL = $(addprefix $(OBJ_PATH)/, $(OBJ))

$(NAME): makedeps $(OBJ_FULL)
	@echo "-- Creating static library FTPRINTF"
	@cp $(LIBS_DIR)/$(LIBS) ./$(NAME)
	@$(ARCHV) $(NAME) $(OBJ_FULL)
	@$(MSG_DONE)

makedeps: 
	@echo "-- Creating ft_printf dependencies"
	@make -C $(LIBS_DIR) $(LIBS_RULE)
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo "-- Compiling $@"
	@$(CC) $(FLAGS) $(INCLUDES) -o $@ -c $<

all: $(NAME)

clean:
	@echo "-- Removing ft_printf objects"
	@rm -rf $(OBJ_PATH)
	@rm -f $(BIN)
	@$(MSG_DONE)
	@make -C $(LIBS_DIR) clean

fclean:
	@echo "-- Removing everything of ft_printf"
	@echo "NOTE: source code will be preserved"
	@rm -f $(BIN)
	@rm -f $(NAME)
	@rm -rf $(OBJ_PATH)
	@$(MSG_DONE)
	@make -C $(LIBS_DIR) fclean

re: fclean all

debug: FLAGS += -g

debug: LIBS_RULE = debug

debug: re
	@echo "-- Compiling debugger executable file"
	@$(CC) $(FLAGS) $(INCLUDES) main.c -L. -lftprintf -o $(BIN)
	@$(MSG_DONE)

.PHONY: all clean fclean re exec makedeps debug
