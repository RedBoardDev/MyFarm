/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** q_seller.c
*/

#include "../../../include/rpg.h"

void send_chat_bubble_seller(rpg_t *rpg)
{
    if (rpg->quest[QUEST_SELLER].step <= 0)
        return;
    write_text(rpg->begin.window, rpg->quest[QUEST_SELLER].dialog);
    if (get_clock_time(rpg->quest[QUEST_SELLER].clock_chat) >=
    SECOND_TO_MICRO(6)) {
        if (!get_chat_into_file("assets/quest_dialog/seller.txt",
        QUEST_SELLER, rpg))
            rpg->quest[QUEST_SELLER].step = -1;
        sfClock_restart(rpg->quest[QUEST_SELLER].clock_chat);
    }
}

void quest_seller(rpg_t *rpg)
{
    // rpg->quest[QUEST_SELLER].clock_chat = sfClock_create();
    // rpg->spritesheet[SP_BUBBLE_CHAT].pos = rpg->quest[QUEST_SELLER].pos_dialog;
    // sfSprite_setScale(rpg->spritesheet[SP_BUBBLE_CHAT].sprite,
    // (sfVector2f){1, 1});
    // sfSprite_setScale(rpg->spritesheet[SP_BUBBLE_CHAT].sprite,
    // rpg->quest[QUEST_SELLER].scale);
    // if (rpg->quest[QUEST_SELLER].step == 0) {
    //     rpg->spritesheet[SP_BUBBLE_CHAT].active = true;
    //     get_chat_into_file("assets/quest_dialog/seller.txt",
    //     QUEST_SELLER, rpg);
    // }
    // if (rpg->quest[QUEST_SELLER].step == -1) {
    put_shop_gui(rpg);
    // }
}
