/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday04-martin.d-herouville
** File description:
** my_getnbr.c
*/

#include "my.h"

int is_minus(char const *str)
{
    int minus = 0;
    int negative = 0;

    for (int i = 0; i < my_strlen(str); ++i) {
        if (str[i] == '-')
            ++minus;
        if ((str[i + 1] >= '0' && str[i + 1] <= '9') && str[i] == '-')
            break;
    }
    negative = minus % 2;
    if (negative == 1)
        return (1);
    else
        return (0);
}

int my_getnbr(char const *str)
{
    int increment = 1;
    long int result = 0;

    for (int i = 0; i < my_strlen(str); ++i) {
        if ((str[i] < '0' || str[i] > '9') && str[i] != '-'
        && str[i] != '+')
            break;
        if (str[i] >= '0' && str[i] <= '9') {
            result = (result * 10);
            ++increment;
            result = result + (str[i] - 48);
        }
    }
    if (is_minus(str) == 1)
        result = result * -1;
    if ((result > 2147483647 || result < -2147483647)
    && increment >= 10)
        return (0);
    return (result);
}
