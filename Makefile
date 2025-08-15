# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 17:30:31 by rluis-ya          #+#    #+#              #
#    Updated: 2025/08/15 12:08:52 by rluis-ya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -Iinclude -Ilibft

ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

NAME = push_swap

UNIT = unit_test

SRC_DIR = srcs

PARSER_DIR = $(SRC_DIR)/parser

TRASH_DIR = $(SRC_DIR)/trash

SM_DIR = $(SRC_DIR)/stack_moves

SRCS_PARSER = parser.c parser_utils.c

SRCS_TRASH = error_handle.c 

SRCS_SM = moves.c

PATH_PARSER = $(patsubst %,$(PARSER_DIR)/%,$(SRCS_PARSER))

PATH_TRASH = $(patsubst %,$(TRASH_DIR)/%,$(SRCS_TRASH))

PATH_SM = $(patsubst %,$(SM_DIR)/%,$(SRCS_SM))

LFT = libft/libft.a

all: $(NAME)

unit: fclean $(UNIT)

$(LFT):
	$(MAKE) -C libft

$(NAME): $(PATH_PARSER) $(PATH_TRASH) $(LFT)
	$(CC) $(CFLAGS) main.c $^ -o $@
	@echo "🚀 Ready."

$(UNIT): $(PATH_PARSER) $(PATH_TRASH) $(PATH_SM) $(LFT)
	$(CC) -g $(CFLAGS) main.c $^ -o $@
	@echo "🚀 Test ready."

debug: fclean
	$(MAKE) DEBUG=1

clean:
	@$(MAKE) clean -C libft
	@echo "🧹 Cleaned."

fclean: clean
	@rm -f $(NAME)
	@rm -f $(UNIT)
	@$(MAKE) -C libft fclean
	@echo "🗑️  Cleaned all."

re: fclean all
	@echo "🔄 Rebuild."

.PHONY: all clean fclean re debug unit
