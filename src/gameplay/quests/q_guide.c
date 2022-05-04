/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** q_guide.c
*/

#include "../../../include/rpg.h"

void quest_guide(rpg_t *rpg)
{
    rpg->quest[QUEST_GUIDE].clock_chat = sfClock_create();
    if (rpg->quest[QUEST_GUIDE].active != 0) {
        if (rpg->quest[QUEST_GUIDE].active <= 1
        || check_if_in_inventory(rpg, rpg->quest[QUEST_GUIDE].active) == -1)
            return;
        else
            remove_item_inventory(rpg, rpg->quest[QUEST_GUIDE].active);
    }
    rpg->quest[QUEST_GUIDE].active = 1;
    get_chat_into_file("assets/quest_dialog/guide.txt",
    QUEST_SOLDIER, rpg);
}
