# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 08:27:30 by vhacman           #+#    #+#              #
#    Updated: 2025/03/23 13:50:37 by vhacman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ========================== VARIABLES ========================== #

NAME		= printf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror
RM			= rm -f
AR			= ar
ARFLAGS		= rcs

SRC_DIR		= src
OBJ_DIR		= obj
INC_DIR		= includes

SRC			= $(wildcard $(SRC_DIR)/*.c)
OBJS		= $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))

# ========================== RULES ========================== #

all: $(NAME)
	@echo "✨ (\033[36mft_printf\033[0m) compiled into \033[32m$(NAME)\033[0m with style and zero warnings. 💅"

$(NAME): $(OBJS)
	@$(AR) $(ARFLAGS) $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "📦 Compiled: $<"

clean:
	@$(RM) -r $(OBJ_DIR)
	@$(RM) $(NAME)
	@echo "🧹 Object files and \033[31m$(NAME)\033[0m deleted. Clean workspace. ✨"

fclean: clean
	@echo "💀 Full cleanup complete. No trace left of \033[35mft_printf\033[0m."

re: fclean all
	@echo "🔄 Rebuilt everything from scratch. \033[36mft_printf\033[0m is reborn. 🚀"

.PHONY: all clean fclean re
