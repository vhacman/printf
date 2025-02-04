/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 10:44:19 by vhacman           #+#    #+#             */
/*   Updated: 2025/02/04 12:51:27 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>

//Buffer of 4096 bytes
# define BUF_SIZE 4096
# define FLAGS "+ 0-#"
# define NUMBERS "0123456789"
# define SPECIFIERS "cspdiuxX"
/*We have to create a struct to contain
All the bools [+-' '0#] [width] [.precision]*/
typedef enum
{
	BASE_2 = 2,
	BASE_8 = 8,
	BASE_10 = 10,
	BASE_16 = 16,
}	e_base;
typedef struct s_format
{
	bool	left_justified;//true if output should be left-aligned (- flag)
	bool	plus;//true if '+' flag is set
	bool	space;//true if the ' ' flag is set
	bool	hash;// True if the '#' flag is set
	bool	zero_pad;// True if the '0' flag is set
	char	specifier;// The format specifier
	int		width_value;// Minimum width for the output
	int		precision_value;// Precision for floating-point numbers or strings
	e_base	base;
}	t_format;

typedef struct s_data
{
	const char	*s;// Pointer to the format string
	va_list		ap;// Variable argument list
	int			chars_written;// Number of characters written
	char		*buffer;// A buffer for storing output before printing
	int			buffer_index;// The current index in the buffer
	t_format	format;// The current index in the buffer
}	t_data;

typedef	enum
{
	OK = 0,
	MALLOC_ERROR = -1337,
	PARSE_ERROR = -42
}	e_error;

//************************prototypes*******************************//
void	*ft_memset(void *b, int c, size_t count);
char	*ft_strchr(const char *s, int c);
#endif