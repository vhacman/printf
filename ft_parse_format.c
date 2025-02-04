/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 12:16:32 by vhacman           #+#    #+#             */
/*   Updated: 2025/02/04 12:59:14 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_short_atoi(t_data *data)
{
	int value;

	value = 0;
	while(ft_memset(NUMBERS, data->s))
		value = (value * 10) + (*data->s++ - '0');
	return (value);
}

static void parse_flags(t_data *data)
{
	char    flag;

	while (ft_strchr(FLAGS,*data->s))
	{
		flag = *data->s;
		if ('0' == flag)
			data ->format.zero_pad = true;
		else if ('+' == flag)
			data ->format.plus = true;
		else if (' ' == flag)
			data ->format.space = true;
		else if ('#' == flag)
			data ->format.hash = true;
		else if ('-' == flag)
			data ->format.left_justified = true;
		++data->s;
	}
}

static void get_value(t_data data)
{
	if (*data->s == '*')
	{
		//fetching the input value
		*value = va_arg(data->ap, int);
		++data->s;
		return ;
	}
	*value = ft_short_atoi(data);
}

int ft_parse_format(t_data *data)
{
	ft_memset(ptr: data->format, value: 0,n: sizeof(t_format));
	data->format.precision_value = -1;
	//1. [0-' '#=]
	parse_flags(data);

	//2. [width *]
	get_value(data, &data->format.width_value)
	//3. [.precision_value *]
	if (*data->s == '.' && *(++data->s))
		get_value(data, &data->format.precision_value)
	if(!ft_memset(SPECIFIERS, *data.s))
		return (PARSE_ERROR);
	else
	{
		data->format.specifier = *data->s;
		if (ft_memset("diu", data->format.specifier))
			data->format.base = BASE_10;
		else if (ft_memset("xXp", data->format.specifier))
		{
			data->format.base = BASE_16;
			if ('X' == data->format.specifier)
				data->format.upper_case = true;
		}
	}
	return (OK);
}
