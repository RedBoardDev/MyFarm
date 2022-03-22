/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday08-martin.d-herouville
** File description:
** my_str_to_word_array.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "my.h"

bool is_space(char c)
{
    return (c == ' ');
}

int count_words(char const *str)
{
    int nbr_words = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        if (i > 0 && is_space(str[i]) && !is_space(str[i + 1]))
            ++nbr_words;
    if (str[my_strlen(str) - 1] != ' ')
        ++nbr_words;
    return (nbr_words);
}

int count_letters(char const *str)
{
    int i = 0;

    while (!is_space(str[i]) && str[i] != '\0')
        ++i;
    return (i);
}

char **set_arr(char **new_arr, int i_a, int j_a)
{
    new_arr[i_a][j_a] = '\0';
    new_arr[++i_a] = NULL;
    return (new_arr);
}

char **my_str_to_word_array(char const *str)
{
    int nbr_words = count_words(str);
    int nbr_letters;
    int i_a = 0;
    int j_a = 0;
    int i = 0;
    char **new_arr = malloc(sizeof(char *) * (nbr_words + 1));

    for (; is_space(str[i]); ++i);
    nbr_letters = count_letters(&str[i]);
    new_arr[i_a] = malloc(sizeof(char) * (nbr_letters + 1));
    for (; str[i] != '\0'; ++i) {
        if (i > 0 && is_space(str[i]) && !is_space(str[i - 1]))
            new_arr[i_a][j_a] = '\0';
        is_space(str[i]) && !is_space(str[i + 1]) && str[i + 1] != '\0' ?
        j_a = 0, nbr_letters = count_letters(str + i + 1),
        new_arr[++i_a] = malloc(sizeof(char) * (nbr_letters + 1)) : 0;
        !is_space(str[i]) && str[i] != '\0' ? new_arr[i_a][j_a++] = str[i] : 0;
    }
    new_arr = set_arr(new_arr, i_a, j_a);
    return (new_arr);
}

// int main(int ac, char **av)
// {
//     char *str = "qfs  4  jE su5is dqsmfljhqds slmfg feauepzfh ";

//     char **arr = my_str_to_word_array(av[1]);
//     my_show_word_array(arr);
//     for (int i = 0; arr[i]; ++i)
//         free(arr[i]);
//     free(arr);

//     return (0);
// }

// int my_is_alphanum(char const *str, int i)
// {
//     if (str[i] < '0' || (str[i] > '9' && str[i] < 'A') || (str[i] > 'Z' &&
//     str[i] < 'a') || str[i] > 'z')
//         return (0);
//     else
//         return (1);
// }

// char **strtowordarray2(char const *str, int var_word, char **new_arr, int k)
// {
//     for (int all_letters = 0; str[all_letters] != '\0'; ++all_letters) {
//         int size = 0;

//         if (my_is_alphanum(str, all_letters) == 1) {
//             for (int j = all_letters; str[j] != '\0'
//             && (my_is_alphanum(str, j)); ++j) {
//                 ++size;
//             }
//             new_arr[var_word] = malloc(sizeof(char) * (size + 1));
//             for (k = 0; k < size; ++k) {
//                 new_arr[var_word][k] = str[all_letters];
//                 ++all_letters;
//             }
//             new_arr[var_word][k] = '\0';
//             ++var_word;
//         }
//     }
//     new_arr[var_word] = NULL;
//     return (new_arr);
// }

// char **my_str_to_word_array(char const *str)
// {
//     char **new_arr;
//     int nb_words = 0;
//     int lettres = 0;
//     int var_word = 0;
//     int k = 0;

//     for (int i = 0; i < my_strlen(str); ++i) {
//         int j = 0;
//         if (my_is_alphanum(str, i)) {
//             for (j = i; str[j] != '\0' && (my_is_alphanum(str, j)); ++j)
//                 ++i;
//             ++nb_words;
//         }
//     }
//     new_arr = malloc(sizeof(char *) * (nb_words + 1));
//     new_arr = strtowordarray2(str, var_word, new_arr, k);
//     return (new_arr);
// }
