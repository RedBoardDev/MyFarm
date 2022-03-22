/*
** EPITECH PROJECT, 2021
** my_lib
** File description:
** my_put_colors.c
*/

#include "my.h"

void my_putcolor(char *str, char *color)
{
    write(1, color, my_strlen(color));
    my_putstr(str);
    write(1, RESET, my_strlen(RESET));
}
