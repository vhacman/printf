/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:27:23 by vhacman           #+#    #+#             */
/*   Updated: 2025/02/04 13:37:14 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_char(t_data *data, int c)
{
	int	width;

	width = data->format.width_value;
	if (width > 1)
	{
		if (data->format.left_justified)
		{

		}
		else
		{

		}
	}
}
char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if ((char)c == '\0')
		return ((char *)s);
	return (0);
}

void	*ft_memset(void *b, int c, size_t count)
{
	size_t	cur;
	char	*data;

	cur = 0;
	data = (char *)b;
	while (cur < count)
	{
		data[cur] = c;
		cur++;
	}
	return (b);
}
