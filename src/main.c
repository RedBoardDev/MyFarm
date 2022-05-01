/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main.c
*/

#include "../include/rpg.h"
#include <time.h>

void help(void)
{
    int size_file = 992;
    char *filepath = "assets/help.txt";
    char *buff = malloc(sizeof(char) * size_file);
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return;
    if (read(fd, buff, size_file) == -1)
        return;
    buff[size_file - 1] = '\0';
    my_putstr(buff);
    my_putchar('\n');
    close(fd);
}

int main(int ac, char **av)
{
    if (ac == 2 && !my_strcmp("-h", av[1])) {
        help();
        return (0);
    }
    if (ac == 2 && !my_strcmp("-s", av[1])) {
        myrpg(0);
        return (0);
    }
    if (ac != 1)
        return (84);
    myrpg(1);
    return (0);
}
