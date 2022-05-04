/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** utils_quests.c
*/

#include "../../include/rpg.h"

int check_status_dialog(quest_t *quest)
{
    if (quest[QUEST_SOLDIER].active == 1)
        return (1);
    return (0);
}

static char *get_line_into_file(char *filepath, int quest, rpg_t *rpg)
{
    char *lineptr;
    FILE *fd;
    size_t n = 0;

    fd = fopen(filepath, "r");
    if (!fd)
        return (0);
    for (int i = 0; i < rpg->quest[quest].step; ++i)
        getline(&lineptr, &n, fd);
    fclose(fd);
    if (lineptr[0] == 'N')
        rpg->quest[quest].speaker = 0;
    else if (lineptr[0] == 'P')
        rpg->quest[quest].speaker = 1;
    return (lineptr);
}

static int get_argument_dialog(rpg_t *rpg, char *str, int quest)
{
    if (str[0] == 'F') {
        rpg->quest[quest].speaker = -1;
        return (1);
    }
    if (str[0] == 'W') {
        str = &str[2];
        rpg->quest[quest].speaker = -1;
        rpg->quest[quest].active = my_atoi(str);
        return (2);
    }
    if (str[0] == 'G') {
        str = &str[2];
        add_item_inventory(rpg, my_atoi(str));
        return (2);
    }
    return (0);
}

int get_chat_into_file(char *filepath, int quest, rpg_t *rpg)
{
    int ret = 0;
    char *lineptr;

    if (rpg->quest[quest].step == 0)
        rpg->quest[quest].step = 1;
    lineptr = get_line_into_file(filepath, quest, rpg);
    ret = get_argument_dialog(rpg, lineptr, quest);
    if (ret == 1)
        return (0);
    rpg->quest[quest].step += 1;
    if (ret == 2)
        return (1);
    for (int i = 0; lineptr[i]; ++i)
        lineptr[i] = lineptr[i] == '|' ? '\n' : lineptr[i];
    sfText_setString(rpg->quest[quest].dialog, lineptr + 2);
    free(lineptr);
    return (1);
}
