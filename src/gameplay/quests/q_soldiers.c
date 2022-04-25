/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** q_soldiers.c
*/

#include "../../../include/rpg.h"

int get_size_file(char *path)
{
    struct stat stats;

    stat(path, &stats);
    return (stats.st_size);
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
    printf("%s", lineptr);
    sfText_setString(rpg->quest[quest].dialog, lineptr + 2);
    fclose(fd);
    free(lineptr);
    return (1);
}

void send_chat_bubble_soldiers(sfRenderWindow *window, rpg_t *rpg)
{
    if (rpg->quest[QUEST_SOLDIER].step <= 0)
        return;
    write_text(rpg->begin.window, rpg->quest[QUEST_SOLDIER].dialog);
    if (get_clock_time(rpg->quest[QUEST_SOLDIER].clock_chat) >= 6000000) {
        if (!get_chat_into_file("assets/quest_dialog/soldiers.txt",
        QUEST_SOLDIER, rpg))
            rpg->quest[QUEST_SOLDIER].step = -1;
        sfClock_restart(rpg->quest[QUEST_SOLDIER].clock_chat);
    }
}

void quest_soldiers(rpg_t *rpg)
{
    rpg->quest[QUEST_SOLDIER].clock_chat = sfClock_create();
    if (rpg->quest[QUEST_SOLDIER].step == 0) {
        rpg->spritesheet[SP_BUBBLE_CHAT].active = true;
        get_chat_into_file("assets/quest_dialog/soldiers.txt",
        QUEST_SOLDIER, rpg);
    }
}
