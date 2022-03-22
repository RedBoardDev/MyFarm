/*
** EPITECH PROJECT, 2021
** my_put_number.c
** File description:
** Displays the number given as parameter
*/

#include "my.h"

int my_put_nbr(int nb)
{
    int result;

    if (nb < 0) {
        nb = nb * (-1);
        my_putchar(45);
    }

    result = nb % 10;
    nb = nb / 10;

    if (nb > 0) {
        my_put_nbr(nb);
    }

    my_putchar(result + 48);

    return (0);
}
