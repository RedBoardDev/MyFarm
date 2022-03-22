/*
** EPITECH PROJECT, 2021
** evalexpr
** File description:
** is.c
*/

#include "my.h"

int isnum(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    else
        return (0);
}

int isparenthesis(char c)
{
    if (c == '(' || c == ')')
        return (1);
    else
        return (0);
}

int isope(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%')
        return (1);
    else
        return (0);
}

int isletter(char c)
{
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
        return (1);
    else
        return (0);
}
