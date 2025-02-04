/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 11:27:23 by vhacman           #+#    #+#             */
/*   Updated: 2025/02/04 11:33:21 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

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
