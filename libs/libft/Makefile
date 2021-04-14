# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lrocigno <lrocigno@student.42sp.org>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/16 12:00:43 by lrocigno          #+#    #+#              #
#    Updated: 2021/04/13 21:46:39 by lrocigno         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

ARCHV = ar -rcs

MSG_DONE = echo "-- Done!\n"

HEADER = libft.h

HEADER_PATH = ./

SRC =	ft_memset.c \
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
		ft_strhvchr.c \

SRC_PATH = ./src

SRC_FULL = $(addprefix $(SRC_PATH)/,$(SRC))

OBJ = $(SRC:%.c=%.o)

OBJ_PATH = ./out

OBJ_FULL = $(addprefix $(OBJ_PATH)/,$(OBJ))

makedeps:
	@echo "-- Creating objects directory"
	@mkdir -p $(OBJ_PATH)

$(NAME): makedeps $(OBJ_FULL)
	@echo "-- Creating static library FT"
	@$(ARCHV) $(NAME) $(OBJ_FULL)
	@$(MSG_DONE)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@echo "-- Compiling $@"
	@$(CC) $(FLAGS) -I $(HEADER_PATH) -o $@ -c $<

all: $(NAME)

clean:
	@echo "-- Removing objects of libft"
	@rm -rf ./out
	@$(MSG_DONE)

fclean: clean
	@echo "-- Removing everything of libft"
	@echo "NOTE: source code will be preserved"
	@rm -f $(NAME)
	@$(MSG_DONE)

re: fclean all

.PHONY: clean fclean all re makedeps
