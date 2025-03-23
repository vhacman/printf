
# 🌟🛡️ ft_printf 🛡️🌟
![42 Roma Luiss](https://img.shields.io/badge/42-Roma_Luiss-green)
![Score](https://img.shields.io/badge/Score-100-green)
![Created](https://img.shields.io/badge/Created-February_2025-blue)
![Status](https://img.shields.io/badge/Status-Success-violet)

## 📝 Project Description

`ft_printf` is a custom implementation of the standard C `printf` function. It supports a wide range of format specifiers and returns the number of characters printed to the standard output.

## 🔤 Supported Format Specifiers

- `%c` - Single character
- `%s` - String
- `%p` - Pointer address in hexadecimal
- `%d` - Decimal (base 10)
- `%i` - Integer (base 10)
- `%u` - Unsigned decimal
- `%x` - Lowercase hexadecimal
- `%X` - Uppercase hexadecimal
- `%%` - Literal percent sign

## 🚀 Getting Started

### Prerequisites
- GCC compiler
- `make`

### Installation

1. Clone the repository:
```bash
git clone https://github.com/vhacman/ft_printf.git
cd ft_printf
```

2. Compile the library:
```bash
make
```

This will generate the static library file `libftprintf.a`.

## 💻 Usage

Include the header in your C file:
```c
#include "ft_printf.h"
```

### Example:
```c
int main(void)
{
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Hello, 42!");
    ft_printf("Pointer: %p\n", (void *)0x12345678);
    ft_printf("Decimal: %d\n", 42);
    ft_printf("Integer: %i\n", -42);
    ft_printf("Unsigned: %u\n", 4294967295);
    ft_printf("Hex (lower): %x\n", 255);
    ft_printf("Hex (upper): %X\n", 255);
    ft_printf("Percent: %%\n");
    return (0);
}
```

### Compile with your program:
```bash
gcc your_program.c libftprintf.a -o program
```

## 🛠️ Implementation Details

- `ft_printf.c` – Main printf logic and specifier dispatcher
- `ft_utils.c` – Utility functions for printing characters and numbers
- `ft_putnbr_hex.c` – Hexadecimal number conversion and output
- `ft_printf.h` – Header file containing prototypes and includes

### Key Features
- Full support for basic specifiers
- Handles NULL pointers and edge cases
- Returns the exact number of characters printed
- Uses variadic functions to handle dynamic arguments
- Recursively prints numbers in different bases

## ⚙️ Testing

To test the implementation:
1. Uncomment a test `main()` in `ft_printf.c`
2. Compile with:
```bash
make
gcc -Wall -Wextra -Werror ft_printf.c libftprintf.a
./a.out
```

## 📚 Resources
- [42 School](https://42.fr/)
- [man 3 printf](https://man7.org/linux/man-pages/man3/printf.3.html)
- [C Variadic Functions](https://en.cppreference.com/w/c/variadic)

## 🔧 Makefile Overview

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

## 👤 Author
**vhacman**
- GitHub: [@DevGabi98](https://github.com/DevGabi98)
- 42 Intra: [vhacman](https://profile.intra.42.fr/)

## 📝 License

This project is part of the 42 School curriculum.
Please follow 42's guidelines for usage and distribution.
