/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** my_strncmp.c
*/

#include "my.h"

int my_strncmp(char const *s1, char const *s2, int n)
{
    int i = 0;

    while (s1[i] == s2[i] && i < n - 1)
        ++i;
    return (s1[i] - s2[i]);
}

/*int main(void)
{
    char *str1 = "hello world!";
    char *str2 = "hello";
    int n = 5;

    my_putchar('\n');
    my_put_nbr(my_strncmp(str1, str2, n));
    return (0);
}*/
