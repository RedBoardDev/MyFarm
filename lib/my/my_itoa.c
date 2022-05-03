/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_itoa.c
*/

#include "my.h"

char *my_itoa(int nb)
{
    int i = 0;
    char *str;
    int tmp = nb;

    if (nb == 0)
        return ("0");
    while (tmp > 0) {
        tmp /= 10;
        ++i;
    }
    str = malloc(sizeof(str) * (i + 1));
    str[i] = '\0';
    while (i > 0) {
        i--;
        str[i] = nb % 10 + 48;
        nb /= 10;
    }
    return (str);
}
