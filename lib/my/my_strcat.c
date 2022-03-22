/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_strcat.c
*/

#include "my.h"

char *my_strcat(char *dest , char const *src)
{
    int len_tot = my_strlen(dest) + my_strlen(src) + 1;
    char *new = malloc(sizeof(char) * len_tot);
    int i = 0;

    for (; dest[i] != '\0'; ++i)
        new[i] = dest[i];
    for (int j = 0; src[j] != '\0'; ++i, ++j)
        new[i] = src[j];
    new[i] = '\0';
    return (new);
}
