/*
** EPITECH PROJECT, 2021
** my_revstr.c
** File description:
** reverses a string.
*/

#include "my.h"

char *my_revstr(char *str)
{
    int o = my_strlen(str) - 1;
    int h = 0;
    char temp;

    while (h < o) {
        temp = str[h];
        str[h] = str[o];
        str[o] = temp;
        ++h;
        --o;
    }
    return (str);
}
