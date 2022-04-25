/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** utils_quests.c
*/

#include "../../include/rpg.h"

int check_status_dialog(quest_t *quest)
{
    if (quest[QUEST_SOLDIER].step > 0)
        return (1);
    return (0);
}

int get_chat_into_file(char *filepath, int quest, rpg_t *rpg)
{
    char *lineptr;
    FILE *fd;
    size_t n = 0;

    if (rpg->quest[quest].step == 0)
        rpg->quest[quest].step = 1;
    else
        sfSprite_scale(rpg->spritesheet[SP_BUBBLE_CHAT].sprite,
        (sfVector2f){-1.f, 1.f});
    fd = fopen(filepath, "r");
    if (!fd)
        return (0);
    for (int i = 0; i < rpg->quest[quest].step; ++i)
        getline(&lineptr, &n, fd);
    rpg->quest[quest].step += 1;
    rpg->quest[quest].speaker = lineptr[0] == 'N' ? 1 : 0;
    if (lineptr[0] == 'F') {
        rpg->spritesheet[SP_BUBBLE_CHAT].active = false;
        return (0);
    }
    for (int i = 0; lineptr[i]; ++i)
        lineptr[i] = lineptr[i] == '|' ? '\n' : lineptr[i];
    sfText_setString(rpg->quest[quest].dialog, lineptr + 2);
    fclose(fd);
    free(lineptr);
    return (1);
}
