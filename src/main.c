/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** main.c
*/

#include "../include/rpg.h"
#include <time.h>

char *arg_backup(int ac, char **av, int i)
{
    if (i < ac - 1 && av[i + 1][0] != '-')
        return (av[i + 1]);
    else
        return (NULL);
}

entry_program_t parse_args(int ac, char **av)
{
    entry_program_t args = {false, false, NULL, true};
    bool b = false;

    for (int i = 1; i < ac; ++i) {
        if (!my_strcmp("-h", av[i]) || !my_strcmp("--help", av[i]))
            args.help = true;
        if (!my_strcmp("-s", av[i]) || !my_strcmp("--no-sound", av[i]))
            args.no_sound = true;
        if (!my_strcmp("-b", av[i]) || !my_strcmp("--backup", av[i])) {
            args.filepath = arg_backup(ac, av, i);
            b = true;
        }
    }
    if (b && args.filepath == NULL)
        args.ok = false;
    return (args);
}

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
    entry_program_t args = parse_args(ac, av);

    if (args.help) {
        help();
        return (0);
    }
    if (!args.ok)
        return (84);
    myrpg(args.no_sound, args.filepath);
    return (0);
}
