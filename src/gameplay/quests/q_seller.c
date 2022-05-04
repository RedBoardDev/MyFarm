/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** q_seller.c
*/

#include "../../../include/rpg.h"

void quest_seller(rpg_t *rpg)
{
    if (rpg->quest[QUEST_SELLER].active != 0) {
        if (rpg->quest[QUEST_SELLER].active <= 1
        || check_if_in_inventory(rpg, rpg->quest[QUEST_SELLER].active == -1))
            return;
    }
    rpg->quest[QUEST_SELLER].active = 1;
    get_chat_into_file("assets/quest_dialog/seller.txt",
    QUEST_SELLER, rpg);
}
