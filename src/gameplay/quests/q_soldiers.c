/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** q_soldiers.c
*/

#include "../../../include/rpg.h"

void quest_soldiers(rpg_t *rpg)
{
    if (rpg->quest[QUEST_SOLDIER].active != 0) {
        if (rpg->quest[QUEST_SOLDIER].active <= 1
        || check_if_in_inventory(rpg, rpg->quest[QUEST_SOLDIER].active) == -1)
            return;
        else
            remove_item_inventory(rpg, rpg->quest[QUEST_SOLDIER].active);
    }
    rpg->quest[QUEST_SOLDIER].active = 1;
    get_chat_into_file("assets/quest_dialog/soldiers.txt",
    QUEST_SOLDIER, rpg);
}
