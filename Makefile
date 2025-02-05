# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 08:27:30 by vhacman           #+#    #+#              #
#    Updated: 2025/02/05 16:22:55 by vhacman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar
ARFLAGS = rcs

# Definizione delle cartelle
SRC_DIR = src/
OBJ_DIR = obj/

# Lista file sorgente
SRC = ft_printf ft_utils ft_putnbr_hex
SRCS = $(addprefix $(SRC_DIR), $(SRC:=.c))
OBJS = $(SRCS:$(SRC_DIR)%.c=$(OBJ_DIR)%.o)

# Target
all: $(NAME)

# Crea libreria statica
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compila un file .c in un file .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Crea la cartella obj/ se non esiste
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Pulizia
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
