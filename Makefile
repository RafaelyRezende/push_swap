# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 17:30:31 by rluis-ya          #+#    #+#              #
#    Updated: 2025/08/13 18:02:25 by rluis-ya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -Iinclude -Ilibft

ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

NAME = push_swap

SRC_DIR = srcs

PARSER_DIR = $(SRC_DIR)/parser

TRASH_DIR = $(SRC_DIR)/trash

SRCS_PARSER = parser.c parser_utils.c

SRCS_TRASH = error_handle.c 

PATH_PARSER = $(patsubst %,$(PARSER_DIR)/%,$(SRCS_PARSER))

PATH_TRASH = $(patsubst %,$(TRASH_DIR)/%,$(SRCS_TRASH))

LFT = libft/libft.a

all: $(NAME)

$(LFT):
	$(MAKE) -C libft

$(NAME): $(PATH_PARSER) $(PATH_TRASH) $(LFT)
	$(CC) $(CFLAGS) main.c $^ -o $@
	@echo "🚀 Ready."

debug: fclean
	$(MAKE) DEBUG=1

clean:
	@$(MAKE) clean -C libft
	@echo "🧹 Cleaned."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean
	@echo "🗑️  Cleaned all."

re: fclean all
	@echo "🔄 Rebuild."

.PHONY: all clean fclean re debug
