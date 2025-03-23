# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 08:27:30 by vhacman           #+#    #+#              #
#    Updated: 2025/03/23 13:44:52 by vhacman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = printf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar
ARFLAGS = rcs

# Lista file sorgente (modifica questi se hai più file .c)
SRC = ft_printf.c ft_utils.c ft_putnbr_hex.c
OBJS = $(SRC:.c=.o)

# Target
all: $(NAME)

# Crea libreria statica
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

# Compila un file .c in un file .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Pulizia
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re