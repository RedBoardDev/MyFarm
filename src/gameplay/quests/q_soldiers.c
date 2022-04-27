/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** q_soldiers.c
*/

#include "../../../include/rpg.h"

void send_chat_bubble_soldiers(rpg_t *rpg)
{
    if (rpg->quest[QUEST_SOLDIER].step <= 0)
        return;
    write_text(rpg->begin.window, rpg->quest[QUEST_SOLDIER].dialog);
    if (get_clock_time(rpg->quest[QUEST_SOLDIER].clock_chat) >=
    SECOND_TO_MICRO(6)) {
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
