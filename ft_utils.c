/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:01:26 by vhacman           #+#    #+#             */
/*   Updated: 2025/02/05 20:00:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	(write(1, &c, 1));
	return (1);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
	{
		count = count + write(1, "-2147483648", 11);
		return (count);
	}
	if (n < 0)
	{
		count = count + ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count = count + ft_putnbr(n / 10);
	count = count + ft_putchar(n % 10 + '0');
	return (count);
}

/*the function returns an int representing the number of charachters printed.
If n is >= it means that has more tha 1 digit. The function calls itself
recursively (n / 10) to print the digit left.
The function than extracts the last digit of n (n % 10) and converts
to its corrisponding ASCII character (+ '0')

This function correctly prints unsigned integers and counts the number 
of characters printed. It efficiently processes multi-digit numbers using 
recursion, ensuring they are printed in the correct order.*/
int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count = count + ft_putnbr_unsigned(n / 10);
	count = count + ft_putchar(n % 10 + '0');
	return (count);
}

/*this function is responsible for printing a string to the STDOUT
and returning the number of chars printed.
The while loop iterates through each character in the string until 
it encounters the null terminator ('\0'). 
ft_putchar(str[count]) → Prints the current character.
count++ → Moves to the next character after printing.
After printing the entire string, the function returns count,
which represents the total number of characters printed.*/
int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (str[count])
	{
		ft_putchar(str[count]);
		count++;
	}
	return (count);
}

/*
 * the function prints the memory address of a pointer 'ptr' in 
 * hecadecimal format, prefixed by "0x". If the pointer is NULL,
 * it prints "0x0". The ptr argument is a pointer, and since pointer 
 * types vary depending on the platform  * (e.g., 64-bit or 32-bit), 
 * we convert it to unsigned long long to ensure the address can be 
 * handled as a large number on any system.
 */
 /*
int	ft_putptr(void *ptr)
{
	unsigned long long int	p;
	int					count;

	count = 0;
	if (ptr == NULL)
	{
		count += ft_putstr("(nil)");
		return (count);
	}
	p = (unsigned long long int)ptr;
	if (p == PTR_MINUS_ULONG_MAX)
		count += ft_putstr("0x7fffffffffffffff");
	else if (p == PTR_LONG_MIN)
		count = count + ft_putstr("0x8000000000000000");
	else if (p == PTR_LONG_MAX)
		count = count + ft_putstr("0x7fffffffffffffff");
	else if (p == 0)
		count = count + ft_putstr("0x0");
	else if (p == ULONG_MAX)
		count += ft_putstr("0xffffffffffffffff");
	else
	{
		count = count + ft_putstr("0x");
		count = count + ft_putnbr_hex(p, 0);
	}
	return (count);
}*/
static int	ft_put_ptr(unsigned long ptr)
{
	char	*str;
	int		count;

	str = "0123456789abcdef";
	count = 0;
	if (ptr >= 16)
		count += ft_put_ptr(ptr / 16);  // Ricorsione per stampare ogni cifra esadecimale
	write(1, &str[ptr % 16], 1);  // Stampa il carattere esadecimale corrispondente
	count++;
	return (count);
}

int	ft_putptr(void *ptr)
{
	unsigned long p;
	int count;

	count = 0;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	p = (unsigned long)ptr;
	write(1, "0x", 2);  // Stampiamo "0x"
	count += 2;
	count += ft_put_ptr(p);  // Usare ft_put_ptr per stampare il valore esadecimale
	return (count);
}


