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
	return (write(1, &c, 1));
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
	ft_putchar(n % 10 + '0');
	}
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

/**
 * the function prints the memory address of a pointer 'ptr' in 
 * hecadecimal format, prefixed by "0x". If the pointer is NULL,
 * it prints "0x0". The ptr argument is a pointer, and since pointer 
 * types vary depending on the platform  * (e.g., 64-bit or 32-bit), 
 * we convert it to unsigned long long to ensure the address can be 
 * handled as a large number on any system.
 */
int	ft_putptr(void *ptr)
{
	unsigned long long	p;
	int					count;

	p = (unsigned long long)ptr;
	count = 0;
	count = count + ft_putstr("0x");
	if (p == 0)
		count = count + ft_putchar('0');
	else
		count = count + ft_putnbr_hex(p, 0);
	return (count);
}
