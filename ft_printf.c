/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 09:01:00 by vhacman           #+#    #+#             */
/*   Updated: 2025/02/05 13:01:50 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*The function checks the specifier and processes the 
corresponding argument passed in args. It uses the va_arg macro to extract 
the argument for each specifier.
This specifier stands for c,s,p,u,x,X,%.
char is promoted to int in variadic functions).The function returns the result
of the corresponding printing function (e.g., ft_putchar, ft_putstr, etc.),
which presumably returns the number of characters printed.
If no valid specifier is found, the function returns 0
*/
int	handle_conversion(char specifier, va_list args)
{
	if (specifier == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (specifier == 's')
		return (ft_putstr(va_arg(args, char *)));
	else if (specifier == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_putnbr(va_arg(args, int)));
	else if (specifier == 'u')
		return (ft_putnbr_unsigned(va_arg(args, unsigned int)));
	else if (specifier == 'x')
		return (ft_putnbr_hex(va_arg(args, unsigned int), 0));
	else if (specifier == 'X')
		return ((ft_putnbr_hex(va_arg(args, unsigned int), 1)));
	else if (specifier == '%')
		return (ft_putchar('%'));
	return (0);
}

/**
 * The function returns an INT, which represents the total number
 * of characters printed. The *format parameter is a str that contains
 * both normal characters and format specifiers.
 * The ...-> ellipsis--> indicates that the function accepts
 * a variable number of arguments (variadic function)
 * va_list args:Declares a variable to manage the list of variable args.
 * int i: A counter used to iterate through the format string.
 * int count: Keeps track of the total number of characters printed.
 * The function processes the format string character by character:
 * If the character is '%', it indicates the start of a format specifier.
 * If not, it prints the character directly using ft_putchar and
 * increments the count.
 * va_start-->initialize the args variable to start reading the args that
 * come after format.
*/
int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		count;

	i = 0;
	count = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			count += handle_conversion(format[i], args);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
