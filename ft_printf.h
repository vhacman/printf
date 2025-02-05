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

# include <limits.h>
# include <unistd.h>
# include <string.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

int	ft_printf(const char *format, ...);
int	ft_putchar(char c);
void	ft_putnbr(int n);
int	ft_putstr(char *str);
int	ft_putnbr_unsigned(unsigned int n);
int	ft_putnbr_hex(unsigned int n, int upper);
int	ft_putptr(void *ptr);
int	handle_conversion(char specifier, va_list args);

#endif