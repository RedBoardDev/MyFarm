/*
** EPITECH PROJECT, 2021
** minishell1
** File description:
** arrays_utils.c
*/

#include "my.h"

void free_array(char **array)
{
    for (int i = 0; array[i]; ++i)
        free(array[i]);
    free(array);
}

int count_arr(char **arr)
{
    int i = 0;

    for (; arr[i] != NULL; ++i);
    return (i);
}

char **my_array_dup(char **arr)
{
    char **new_arr = malloc(sizeof(char *) * (count_arr(arr) + 1));
    int i = 0;

    for (; arr[i] != NULL; ++i)
        new_arr[i] = my_strdup(arr[i]);
    new_arr[i] = NULL;
    return (new_arr);
}
