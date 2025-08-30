# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rluis-ya <rluis-ya@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/13 17:30:31 by rluis-ya          #+#    #+#              #
#    Updated: 2025/08/30 07:10:34 by rluis-ya         ###   ########.fr        #
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

ALGO_DIR = $(SRC_DIR)/algorithm

TESTER_DIR = $(SRC_DIR)/test_module

SRCS_PARSER = parser.c parser_utils.c

SRCS_TRASH = error_handle.c 

SRCS_SM = moves.c moves_utils.c

SRCS_ALGO = core.c cost.c

SRCS_TESTER = unit.c

PATH_PARSER = $(patsubst %,$(PARSER_DIR)/%,$(SRCS_PARSER))

PATH_TRASH = $(patsubst %,$(TRASH_DIR)/%,$(SRCS_TRASH))

PATH_SM = $(patsubst %,$(SM_DIR)/%,$(SRCS_SM))

PATH_ALGO = $(patsubst %,$(ALGO_DIR)/%,$(SRCS_ALGO))

PATH_TESTER = $(patsubst %,$(TESTER_DIR)/%,$(SRCS_TESTER))

LFT = libft/libft.a

all: $(NAME)

unit: fclean $(UNIT)

$(LFT):
	$(MAKE) -C libft

$(NAME): $(PATH_PARSER) $(PATH_TRASH) $(PATH_SM) $(LFT)
	$(CC) $(CFLAGS) main.c $^ -o $@
	@echo "🚀 Ready."

$(UNIT): $(PATH_PARSER) $(PATH_TRASH) $(PATH_SM) $(PATH_ALGO) $(LFT)
	$(CC) -g $(CFLAGS) $(PATH_TESTER) $^ -o $@
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
