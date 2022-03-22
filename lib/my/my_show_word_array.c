/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday08-martin.d-herouville
** File description:
** my_show_word_array.c
*/

#include "my.h"

void my_show_word_array(char * const *tab)
{
    for (int i = 0; tab[i] != NULL; ++i) {
        my_putstr(tab[i]);
        my_putchar('\n');
    }
}
