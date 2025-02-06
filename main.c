/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhacman <vhacman@student.42roma.it>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 10:39:54 by vhacman           #+#    #+#             */
/*   Updated: 2025/02/06 11:52:40 by vhacman          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int main(void)
{
    int return1;
    int return2;
    //test carattere
    return1 = ft_printf("test c, carattere: %c\n", 'A');
    return2 = printf("test c, carattere: %c\n", 'A');
    printf("Return values: ft_printf = %d, printf = %d\n", return1, return2);
    //test stringa
    return1 = ft_printf("test s, string: %s\n", "Hello, World!");
    return2 = printf("test s, stringa: %s\n", "Hello, World!");
    printf("Return values: ft_printf = %d, printf = %d\n", return1, return2);
    //test interi (d/i)
    return1 = ft_printf("test d/i, Intero: %d | %i\n", -42, 42);
    return2 = printf("test d/i, Intero: %d | %i\n", -42, 42);
    printf("Return values: ft_printf = %d, printf = %d\n", return1, return2);
    //intero senza segno
    return1 = ft_printf("test u, Unsigned: %u\n", 123456789);
    return2 = printf("test u, Unsigned: %u\n", 123456789);
    printf("Return values: ft_printf = %u, printf = %u\n", return1, return2);
    //esadecimale minuscolo e maiuscolo
    return1 = ft_printf("test hex: %x | %X\n", 255, 255);
    return2 = printf("test hex: %x | %X\n", 255, 255);
    printf("Return values: ft_printf = %x, printf = %x\n", return1, return2);
    //puntatore
    void    *ptr;
    ptr = (void *)0x12345678;
    return1 = ft_printf("test p, Pointer: %p\n", ptr);
    return2 = printf("test p, Pointer: %p\n", ptr);
    printf("Return values: ft_printf = %d, printf = %d\n", return1, return2);
    return (0);
}
