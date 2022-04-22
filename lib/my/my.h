/*
** EPITECH PROJECT, 2021
** B-CPE-100-MLH-1-1-cpoolday09-martin.d-herouville
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_

    #include <stdlib.h>
    #include <stdio.h>
    #include <stddef.h>
    #include <unistd.h>
    #include <string.h>
    #include <stdbool.h>
    #define RESET "\033[0m"
    #define BLACK "\033[0;30m"
    #define RED "\033[0;31m"
    #define GREEN "\033[0;32m"
    #define YELLOW "\033[0;33m"
    #define BLUE "\033[0;34m"
    #define PURPLE "\033[0;35m"
    #define CYAN "\033[0;36m"
    #define WHITE "\033[0;37m"
    #define BOLD_BLACK "\033[1;30m"
    #define BOLD_RED "\033[1;31m"
    #define BOLD_GREEN "\033[1;32m"
    #define BOLD_YELLOW "\033[1;33m"
    #define BOLD_BLUE "\033[1;34m"
    #define BOLD_PURPLE "\033[1;35m"
    #define BOLD_CYAN "\033[1;36m"
    #define BOLD_WHITE "\033[1;37m"

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
void my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *array, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup(int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char *my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strdup(char const *src);
char *my_strupcase(char *str);
char *my_strlowcase(char *str);
char *my_strcapitalize(char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const *str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
int my_is_integer(float val);
char *my_strstr_supplement(char *str, char const *to_find, int i);
void my_show_word_array(char * const *tab);
char **my_str_to_word_array(char const *str);
char **strtowordarray2(char const *str, int var_word, char **new_str, int k);
int my_is_alphanum(char const *str, int i);
int testiff(int *array, int size);
void printarray(int *arr, int size);
int my_atoi(char const *src);
int isnum(char c);
int isparenthesis(char c);
int isope(char c);
int isletter(char c);
int my_printf(char *str, ...);
void my_putcolor(char *str, char *color);
char *my_itoa(int nb);

#endif /* MY_H_ */
