/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** q_seller.c
*/

#include "../../../include/rpg.h"

void quest_seller(rpg_t *rpg)
{
    rpg->quest[QUEST_SELLER].clock_chat = sfClock_create();
    rpg->spritesheet[SP_BUBBLE_CHAT].pos = rpg->quest[QUEST_SELLER].pos_dialog;
    sfSprite_setScale(rpg->spritesheet[SP_BUBBLE_CHAT].sprite,
    (sfVector2f){1, 1});
    sfSprite_setScale(rpg->spritesheet[SP_BUBBLE_CHAT].sprite,
    rpg->quest[QUEST_SELLER].scale);
    if (rpg->quest[QUEST_SELLER].active != 0) {
        if (rpg->quest[QUEST_SELLER].active == -1)
            put_shop_gui(rpg);
        else if (rpg->quest[QUEST_SELLER].active <= 1
        || check_if_in_inventory(rpg, rpg->quest[QUEST_SELLER].active == -1))
            return;
    }
    rpg->spritesheet[SP_BUBBLE_CHAT].active = true;
    rpg->quest[QUEST_SELLER].active = 1;
    get_chat_into_file("assets/quest_dialog/seller.txt",
    QUEST_SELLER, rpg);
}
