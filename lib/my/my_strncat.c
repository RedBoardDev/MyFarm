/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_strcat.c
*/

#include "my.h"

char *my_strncat(char *dest , char const *src, int nb)
{
    int destlen = my_strlen(dest);
    int i = 0;

    for (i; i < nb && src[i] != '\0'; ++i)
        dest[destlen + i] = src[i];
    dest[destlen + i] = '\0';

    return (dest);
}
