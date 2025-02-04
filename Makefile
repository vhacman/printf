# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/04 08:27:30 by vhacman           #+#    #+#              #
#    Updated: 2025/02/04 13:37:12 by vhacman          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#definizione delle variabili
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

AR = ar 
ARFLAGS = rcs 

#definizione delle cartelle
SRC_DIR = src/
OBJ_DIR = obj/

#lista file sorgente
SRC = 
SRCS = $(addsuffix .c, $(SRC))
OBJS = $(SRCS:.c=.o)

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

#target
all: $(NAME)

#crea libreria statica (rcs= sostituisce i file .o gia' esistenti, 
#crea archivio se non esiste, aggiunge un indice per velocizzare il linking)
$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

#questa regola compila un file .c in un file .o all'interno della directory 
#$(OBJ_DIR) e assicura che la directory di destinazione esista prima della compilazione.
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

#creazione cartella obj/ per organizzare i file .o, se non esiste
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

#pulizia
clean: 
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re