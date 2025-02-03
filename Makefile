NAME = libftprintf.a

#Variabili
COMPILER = gcc
CFLAGS = -Wall -Werror -Wextra
AR = ar 
ARFLAGS = rcs # agiunge o sostituisce i file oggetto nell'archivio, crea un nuovo archivio se non esiste, aggiunge un indice per velocizzare il collegamento.
RM = rm -f
SRC_DIR = src/
OBJ_DIR = obj/
SRC = #elenco dei nomi dei file sorgente senza estensione .c
SRCS = $(addsuffix .c, $(SRC))
OBJS = $(SRCS:%.c=$(OBJ_DIR)/%.o) #per ogni file .c il file oggetto corrispondente verra' creato nella directory obj/. usa il compilatore con i flag definiti in CFLAGS.
LIBFT_PATH = ./libft #percorso relativo a dove si trova la libreria libft. Signfica che si trova alla stessa altezza del Makefile.
LIBFT = $(LIBFT_PATH)/libft.a 
#Targets
all: $(NAME)

#Regole per compilare

#Pulizia dei file .o ed eseguibili
