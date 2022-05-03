/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** q_guide.c
*/

#include "../../../include/rpg.h"

void quest_soldiers(rpg_t *rpg)
{
    rpg->quest[QUEST_SOLDIER].clock_chat = sfClock_create();
    rpg->spritesheet[SP_BUBBLE_CHAT].pos = rpg->quest[QUEST_SOLDIER].pos_dialog;
    sfSprite_setScale(rpg->spritesheet[SP_BUBBLE_CHAT].sprite,
    (sfVector2f){1, 1});
    sfSprite_setScale(rpg->spritesheet[SP_BUBBLE_CHAT].sprite,
    rpg->quest[QUEST_SOLDIER].scale);
    if (rpg->quest[QUEST_SOLDIER].active != 0) {
        if (rpg->quest[QUEST_SOLDIER].active <= 1
        || check_if_in_inventory(rpg, rpg->quest[QUEST_SOLDIER].active) == -1)
            return;
        else
            remove_item_inventory(rpg, rpg->quest[QUEST_SOLDIER].active);
    }
    rpg->spritesheet[SP_BUBBLE_CHAT].active = true;
    rpg->quest[QUEST_SOLDIER].active = 1;
    get_chat_into_file("assets/quest_dialog/soldiers.txt",
    QUEST_SOLDIER, rpg);
}
