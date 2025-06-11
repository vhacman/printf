---

## 🤝 Contribuisci in modo rispettoso

Se trovi utile questo progetto, ti invito a non clonare direttamente la repository.

### ✨ Perché fare una fork?

Fare una **fork**:
- ti permette di avere una copia personale su cui lavorare liberamente;
- rende trasparente il tuo interesse per il progetto;
- mi aiuta a costruire un GitHub più professionale e tracciabile, mostrando quante persone hanno interagito realmente con il mio lavoro.

> 🚀 In questo modo posso far crescere il mio profilo e migliorare come sviluppatrice.

### ✅ Come procedere

1. Clicca in alto a destra su **Fork**
2. Clona la tua copia con:

```bash
git clone https://github.com/<il-tuo-username>/<nome-repo>.git

```
---

# ft_printf
[![ft_printf](https://github.com/vhacman/printf/actions/workflows/main.yml/badge.svg)](https://github.com/vhacman/printf/actions/workflows/main.yml)
![42 Roma Luiss](https://img.shields.io/badge/42-Roma_Luiss-green)
![Score](https://img.shields.io/badge/Score-100-green)
![Created](https://img.shields.io/badge/Created-February_2025-blue)
![Status](https://img.shields.io/badge/Status-Success-violet)

## 📝 Descrizione del Progetto

`ft_printf` è una reimplementazione della funzione `printf` della libreria standard C. Gestisce vari specificatori di formato e restituisce il numero di caratteri stampati.

### Specificatori di Formato Supportati:

- `%c` - Carattere singolo
- `%s` - Stringa
- `%p` - Indirizzo puntatore in esadecimale
- `%d` - Numero decimale
- `%i` - Intero in base 10
- `%u` - Numero decimale senza segno
- `%x` - Numero esadecimale minuscolo
- `%X` - Numero esadecimale maiuscolo
- `%%` - Simbolo percentuale

## 🚀 Come Iniziare

### Prerequisiti
- Compilatore GCC
- Make

### Installazione

1. Clona il repository
```bash
git clone https://github.com/vhacman/ft_printf.git
cd ft_printf
```

2. Compila la libreria
```bash
make
```

Questo creerà il file `libftprintf.a`.

## 💻 Utilizzo

Includi l'header nel tuo file C:
```c
#include "ft_printf.h"
```

Esempio di utilizzo:
```c
int main(void)
{
    ft_printf("Carattere: %c\n", 'A');
    ft_printf("Stringa: %s\n", "Hello, 42!");
    ft_printf("Puntatore: %p\n", (void *)0x12345678);
    ft_printf("Decimale: %d\n", 42);
    ft_printf("Intero: %i\n", -42);
    ft_printf("Senza segno: %u\n", 4294967295);
    ft_printf("Esadecimale: %x\n", 255);
    ft_printf("ESADECIMALE: %X\n", 255);
    ft_printf("Percentuale: %%\n");
    return (0);
}
```

### Compilazione con il Tuo Programma
```bash
gcc tuo_programma.c libftprintf.a -o programma
```

## 🛠️ Dettagli Implementativi

Il progetto è composto da diversi componenti:

- `ft_printf.c` - Funzione printf principale e gestore dei specificatori di formato
- `ft_utils.c` - Funzioni di utilità per la stampa di numeri e caratteri
- `ft_putnbr_hex.c` - Conversione e stampa di numeri esadecimali
- `ft_printf.h` - File header con prototipi delle funzioni e inclusioni

### Caratteristiche Principali
- Gestione di tutti gli specificatori di formato base
- Gestione di puntatori null e casi limite
- Restituzione del numero esatto di caratteri stampati
- Utilizzo di funzioni variadiche per la gestione degli argomenti
- Implementazione di stampa numerica ricorsiva per diverse basi

## ⚙️ Testing

Per testare l'implementazione:
1. Decommenta la funzione main in ft_printf.c
2. Compila con i flag di test
```bash
make
gcc -Wall -Wextra -Werror ft_printf.c libftprintf.a
./a.out
```

## 📚 Risorse
- [42 School](https://42.fr/)
- [Manuale Printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Funzioni Variadiche](https://en.cppreference.com/w/c/variadic)

## 🔍 Makefile

```makefile
NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar
ARFLAGS = rcs

SRC = ft_printf.c ft_utils.c ft_putnbr_hex.c
OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
    ar rcs $(NAME) $(OBJS)

%.o: %.c
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    $(RM) $(OBJS)

fclean: clean
    $(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
```

## 👤 Autore
**vhacman**
- Github: [@DevGabi98](https://github.com/vhacman)
- 42 Intra: [vhacman](https://profile.intra.42.fr/)

## ⚖️ Licenza
Questo progetto fa parte del curriculum della 42 School. Si prega di fare riferimento alle loro linee guida per l'utilizzo e la distribuzione.
