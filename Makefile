NAME = philo

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

CC = cc
SRC_DIR = src
UTILS_DIR = $(SRC_DIR)/utils
INCLUDE_DIR = inc

INCLUDE_DIRS = -I $(INCLUDE_DIR)
FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=thread
CFLAGS = $(INCLUDE_DIRS) $(FLAGS)

SRCS =	$(UTILS_DIR)/philo_utils.c	\
		$(UTILS_DIR)/utils.c		\
		$(UTILS_DIR)/atol.c			\
		$(SRC_DIR)/init.c			\
		$(SRC_DIR)/parse.c			\
		$(SRC_DIR)/philo.c			\
		$(SRC_DIR)/simulation.c		\
		$(SRC_DIR)/monitor.c		\
		$(SRC_DIR)/cleanup.c		\
		$(SRC_DIR)/main.c			\

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(SRC_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(UTILS_DIR)%.o: $(UTILS_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compilation successful!$(RESET)"

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
