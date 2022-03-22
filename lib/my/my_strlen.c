/*
** EPITECH PROJECT, 2021
** my_strlen.c
** File description:
** Counts and return the number of characters in the string.
*/

#include "my.h"

int my_strlen(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        ++i;
    }
    return (i);
}
