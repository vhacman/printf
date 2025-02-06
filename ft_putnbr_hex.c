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

int	ft_putnbr_hex(unsigned long n, int upper)
{
	char	*hex_digits;
	int		count;

	count = 0;
	if (upper)
		hex_digits = "0123456789ABCDEF";
	else
		hex_digits = "0123456789abcdef";
	if (n >= 16)
		count += ft_putnbr_hex (n / 16, upper);
	count += ft_putchar(hex_digits[n % 16]);
	return (count);
}

/*
static int	ft_putnbr_hex_helper(unsigned int n, int upper,
					char *hex_digits)
{
	int	count;

	count = 0;
	if (n == 0 && count == 0)
	{
		count += ft_putchar('0');
		return (count);
	}
	if (n >= 16)
		count += ft_putnbr_hex_helper (n / 16, upper, hex_digits);
	count += ft_putchar(hex_digits[n % 16]);
	return (count);
}*/