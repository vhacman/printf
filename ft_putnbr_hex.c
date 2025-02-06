/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 15:18:59 by vhacman           #+#    #+#             */
/*   Updated: 2025/02/05 19:18:00 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**the function prints a number in hexadecimal(base 16) format, using
 * either uppercase or lowercase letters, depending on the upper parameter
 * It is a recursive helper function that prints an unsigned integer in 
 * hexadecimal representation. 
 */
static int	ft_putnbr_hex_helper(unsigned int n, int upper,
					char *hex_digits)
{
	int	count;

	count = 0;
	if(n == 0 && count == 0)
	{
		count += ft_putchar('0');
		return (count);
	}
	if (n >= 16)
		count += ft_putnbr_hex_helper (n / 16, upper, hex_digits);
	count += ft_putchar(hex_digits[n % 16]);
	return(count);
}

/* 
 * `ft_putnbr_hex` is the main function that takes an unsigned integer `n`
 * and prints it in hexadecimal format using `ft_putnbr_hex_helper`. 
 * It first selects the appropriate hexadecimal digit set (either uppercase or 
 * lowercase) based on the `upper` parameter.
 * If upper == 1, it uses uppercase hexadecimal digits "0123456789ABCDEF".
 * If upper == 0, it uses lowercase hexadecimal digits "0123456789abcdef".
 * It then passes the selected digit set along with the number n to 
 * ft_putnbr_hex_helper to start the printing process.
 */
int	ft_putnbr_hex(unsigned int n, int upper)
{
	char	*hex_digits;
	int	count;

	count = 0;	
	if (upper)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	count = ft_putnbr_hex_helper(n, upper, hex_digits);
	return (count);
}
