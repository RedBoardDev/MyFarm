/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** quest_dialog.c
*/

#include "../../../include/rpg.h"

static char *get_line_into_file(char *filepath, int quest, rpg_t *rpg)
{
    char *lineptr = NULL;
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

static int get_argument_step_action(rpg_t *rpg, char *str, char first_character)
{
    switch (first_character) {
    case 'G':
        add_item_inventory(rpg, my_atoi(str));
        return (2);
    case 'A':
        send_notif(rpg, str);
        return (2);
    case 'Q':
        add_quest_inv(rpg, my_atoi(str));
        return (2);
    case 'R':
        mark_quest_done(rpg, my_atoi(str));
        return (2);
    default:
        break;
    }
    return (0);
}

static int get_argument_step(rpg_t *rpg, char *str, int quest)
{
    char first_character = str[0];

    str = &str[2];
    switch (first_character) {
    case ('F'):
        rpg->player_stats.money += my_atoi(str);
        rpg->quest[quest].speaker = -1;
        return (1);
    case 'W':
        rpg->quest[quest].speaker = -2;
        rpg->quest[quest].active = my_atoi(str);
        return (2);
    case 'S':
        rpg->quest[quest].speaker = -3;
        rpg->quest[quest].active = my_atoi(str) + NBR_SP;
        return (2);
    default:
        break;
    }
    return (get_argument_step_action(rpg, str, first_character));
}

int get_chat_into_file(char *filepath, int quest_id, rpg_t *rpg)
{
    int ret = 0;
    char *lineptr;

    if (rpg->quest[quest_id].step == 0)
        rpg->quest[quest_id].step = 1;
    lineptr = get_line_into_file(filepath, quest_id, rpg);
    ret = get_argument_step(rpg, lineptr, quest_id);
    if (ret == 1)
        return (0);
    rpg->quest[quest_id].step += 1;
    if (ret == 2)
        return (1);
    for (int i = 0; lineptr[i]; ++i)
        lineptr[i] = lineptr[i] == '|' ? '\n' : lineptr[i];
    sfText_setString(rpg->quest[quest_id].dialog, lineptr + 2);
    free(lineptr);
    return (1);
}
