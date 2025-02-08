# ft_printf
![42 Roma Luiss](https://img.shields.io/badge/42-Roma_Luiss-green)
![Score](https://img.shields.io/badge/Score-In_Progress-yellow)

A custom implementation of the printf function for 42 School. This project is part of the Common Core curriculum.

## 📝 Description

`ft_printf` is a reimplementation of the standard C library function `printf`. It handles various format specifiers and returns the number of characters printed. This implementation supports the following format specifiers:

- `%c` - Single character
- `%s` - String
- `%p` - Pointer address in hexadecimal
- `%d` - Decimal number
- `%i` - Integer in base 10
- `%u` - Unsigned decimal number
- `%x` - Number in lowercase hexadecimal
- `%X` - Number in uppercase hexadecimal
- `%%` - Percent sign

## 🚀 Getting Started

### Prerequisites
- GCC compiler
- Make

### Installation
1. Clone the repository
```bash
git clone https://github.com/vhacman/ft_printf.git
cd ft_printf
```

2. Compile the library
```bash
make
```

This will create a `libftprintf.a` file.

## 💻 Usage

Include the header in your C file:
```c
#include "ft_printf.h"
```

Example usage:
```c
int main(void)
{
    ft_printf("Character: %c\n", 'A');
    ft_printf("String: %s\n", "Hello, 42!");
    ft_printf("Pointer: %p\n", (void *)0x12345678);
    ft_printf("Decimal: %d\n", 42);
    ft_printf("Integer: %i\n", -42);
    ft_printf("Unsigned: %u\n", 4294967295);
    ft_printf("Hexadecimal: %x\n", 255);
    ft_printf("HEXADECIMAL: %X\n", 255);
    ft_printf("Percent: %%\n");
    return (0);
}
```

### Compilation with Your Program
```bash
gcc your_program.c libftprintf.a -o program
```

## 🛠️ Implementation Details

The project consists of several components:

- `ft_printf.c` - Main printf function and format specifier handler
- `ft_utils.c` - Utility functions for number and character printing
- `ft_putnbr_hex.c` - Hexadecimal number conversion and printing
- `ft_printf.h` - Header file with function prototypes and includes

### Key Features
- Handles all basic format specifiers
- Manages null pointers and edge cases
- Returns the exact number of characters printed
- Uses variadic functions for argument handling
- Implements recursive number printing for different bases

## ⚙️ Testing

To test the implementation:
1. Uncomment the main function in ft_printf.c
2. Compile with test flags
```bash
make
gcc -Wall -Wextra -Werror ft_printf.c libftprintf.a
./a.out
```

## 📚 Resources
- [42 School](https://42.fr/)
- [Printf Manual](https://man7.org/linux/man-pages/man3/printf.3.html)
- [Variadic Functions](https://en.cppreference.com/w/c/variadic)

## ⚖️ License
This project is part of the 42 School curriculum. Please refer to their guidelines for usage and distribution.

## 👤 Author
**vhacman**
- Github: [@vhacman](https://github.com/vhacman)
- 42 Intra: [vhacman](https://profile.intra.42.fr/)
