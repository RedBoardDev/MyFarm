/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** copies a string into another.
*/

#include "my.h"

char *my_strncpy(char *dest, char const *src, int n)
{
    int i = 0;

    while (i < n) {
        dest[i] = src[i];
        ++i;
    }
    if (n > my_strlen(src))
        dest[i] = '\0';
    return (dest);
}
