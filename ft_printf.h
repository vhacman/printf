/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:01:53 by vhacman           #+#    #+#             */
/*   Updated: 2025/02/05 17:01:53 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

//# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

# define PTR_LONG_MIN 0x8000000000000000
# define PTR_LONG_MAX 0x7fffffffffffffff
# define PTR_MINUS_ULONG_MAX ULONG_MAX
# define ULONG_MAX 0xffffffffffffffff

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr_hex(unsigned int n, int upper);
int	ft_putptr(void *ptr);
int	handle_conversion(char specifier, va_list args);
//int	main(void);

#endif