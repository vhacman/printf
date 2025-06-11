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

/* Writes a single character to stdout using write.
 * Returns 1, the number of characters written.
 */
int	ft_putchar(char c)
{
	(write(1, &c, 1));
	return (1);
}

/* Recursively prints a signed integer to stdout.
 * If the number is negative, prints a minus sign first.
 * Returns the total number of characters written.
 */
int	ft_putnbr(int num)
{
	long n;
	int	count;

	n = num;
	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		n = -n;
	}
	if (n >= 10)
		count += ft_putnbr(n / 10);
	count += ft_putchar(n % 10 + '0');
	return (count);
}

/* Recursively prints an unsigned integer to stdout.
 * Returns the total number of characters written.
 */
int	ft_putnbr_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	if (n >= 10)
		count = count + ft_putnbr_unsigned(n / 10);
	count = count + ft_putchar(n % 10 + '0');
	return (count);
}

/* Writes a string to stdout, character by character.
 * If the string is NULL, prints "(null)" instead.
 * Returns the number of characters written.
 */
int	ft_putstr(char *str)
{
	int	count;

	count = 0;
	if (str == NULL)
		return (ft_putstr("(null)"));
	while (*str)
	{
		count += ft_putchar(*str);
		str++;
	}
	return (count);
}

/* Prints a pointer value in hexadecimal format with '0x' prefix.
 * If the pointer is NULL, prints "(nil)".
 * Returns the number of characters written.
 */
int	ft_putptr(void *ptr)
{
	unsigned long	p;
	int				count;

	count = 0;
	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	p = (unsigned long)ptr;
	write(1, "0x", 2);
	count += 2;
	count += ft_putnbr_hex(p, 0);
	return (count);
}
