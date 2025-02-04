/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_buffer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 13:02:01 by vhacman           #+#    #+#             */
/*   Updated: 2025/02/04 13:37:13 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_flush_buffer(t_data *data)
{
    data->chars_written += write(STDOUT_FILENO, data->buffer,data->buffer_index);
    //refresh after call
    ft_memset(data->buffer, 0, BUF_SIZE);
    data->buffer_index = 0;
}

void    ft_write_buffer(t_data *data, char c)
{
    if (data->buffer_index == BUF_SIZE)
    {
        //refresh index and write string in stdout
        ft_flush_buffer(data);
    }
    data->buffer[data->buffer_index++] = c;
}