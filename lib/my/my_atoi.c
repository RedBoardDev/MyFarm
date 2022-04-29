/*
** EPITECH PROJECT, 2021
** bistromatic
** File description:
** my_atoi.c
*/

#include "my.h"

int my_atoi(char const *src)
{
    int dest = 0;

    for (int i = 0; src[i] != '\0'; ++i) {
        if (!isnum(src[i])) {
            return (dest);
        }
        dest *= 10;
        dest += src[i] - 48;
    }
    return (dest);
}

/*int main(int ac, char **av)
{
    my_put_nbr(my_atoi(av[1]));
    return (0);
}*/
