/*
** EPITECH PROJECT, 2021
** project
** File description:
** main.c
*/

#include "../include/rpg.h"

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
    } else if (ac != 1)
        return (84);
    myrpg();
    return (0);
}
