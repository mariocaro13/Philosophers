NAME = philo

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

CC = cc
SRCS_DIR = src
UTILS_DIR = $(SRCS_DIR)/utils
INCLUDE_DIR = inc

INCLUDE_DIRS = -I$(INCLUDE_DIR)
FLAGS = -Wall -Wextra -Werror
CFLAGS = $(INCLUDE_DIRS) $(FLAGS)

SRCS = $(SRCS_DIR)/philo.c			\
	   $(UTILS_DIR)/utils.c			\
	   $(UTILS_DIR)/atol.c			\
	   $(SRCS_DIR)/parse.c			\
	   $(SRCS_DIR)/init.c			\
	   $(SRCS_DIR)/actions.c		\
	   $(SRCS_DIR)/time.c			\
	   $(SRCS_DIR)/threads.c		\
	   $(SRCS_DIR)/error_handling.c	\
	   $(SRCS_DIR)/main.c

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	@echo "$(GREEN)Compiling $(NAME)...$(RESET)"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)Compilation successful!$(RESET)"

all: $(NAME)

clean:
	@echo "$(RED)Cleaning object files...$(RESET)"
	@rm -f $(OBJS)

fclean: clean
	@echo "$(RED)Removing $(NAME)...$(RESET)"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
