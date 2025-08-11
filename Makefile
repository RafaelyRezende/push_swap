CC = cc

CFLAGS = -Wall -Werror -Wextra -Iinclude -Ilibft

ifeq ($(DEBUG), 1)
	CFLAGS += -g
endif

NAME = push_swap

SRC_DIR = srcs

OBJ_DIR = objs

SRCS = main.c utils.c error_handle.c

OBJS = $(SRCS:.c=.o)

PATH_SRCS = $(patsubst %,$(SRC_DIR)/%,$(SRCS))

PATH_OBJS = $(patsubst %,$(OBJ_DIR)/%,$(OBJS))

LFT = libft/libft.a

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(LFT):
	$(MAKE) -C libft

$(NAME): $(PATH_OBJS) $(LFT) | $(OBJ_DIR)
	$(CC) $(CFLAGS) $^ -o $@
	@echo "🚀 Ready."

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

debug: fclean
	$(MAKE) DEBUG=1

clean:
	@rm -rf $(OBJ_DIR)
	@$(MAKE) clean -C libft
	@echo "🧹 Cleaned $(OBJ_DIR)."

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean
	@echo "🗑️  Cleaned all."

re: fclean all
	@echo "🔄 Rebuild."

.PHONY: all clean fclean re debug
