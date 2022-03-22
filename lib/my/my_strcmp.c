/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_strcmp.c
*/

#include "my.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && i < my_strlen(s1))
        ++i;
    return (s1[i] - s2[i]);
}

/*int main(void)
{
    char *str1 = "hello world!";
    char *str2 = "hello world!";

    my_putchar('\n');
    my_put_nbr(my_strcmp(str1, str2));
    return (0);
}*/
