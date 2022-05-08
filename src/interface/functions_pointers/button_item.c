/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button_item.c
*/

#include "../../../include/rpg.h"

void click_item_prisoner_pee(rpg_t *rpg)
{
    if (check_if_in_inventory(rpg, SP_ITEM_PRISONER_PEE) == -1) {
        add_item_inventory(rpg, SP_ITEM_PRISONER_PEE);
        rpg->spritesheet[SP_ITEM_PRISONER_PEE].active = false;
    }
}

void collision_pee(rpg_t *rpg)
{
    sfFloatRect pee_rect = {0, 0, 0, 0};

    if (check_collision_npc(rpg, SP_ITEM_PRISONER_PEE, pee_rect))
        if (check_if_in_inventory(rpg, SP_ITEM_PRISONER_PEE) == -1) {
            send_notif(rpg, "Bring it back to the Indian");
            add_item_inventory(rpg, SP_ITEM_PRISONER_PEE);
            rpg->spritesheet[SP_ITEM_PRISONER_PEE].active = false;
        }
}

void collision_milk(rpg_t *rpg)
{
    sfFloatRect milk_rect = {0, 0, 0, 0};

    if (check_collision_npc(rpg, SP_ITEM_MILK, milk_rect))
        if (check_if_in_inventory(rpg, SP_ITEM_MILK) == -1) {
            send_notif(rpg, "Bring it back to the guide");
            add_item_inventory(rpg, SP_ITEM_MILK);
            rpg->spritesheet[SP_ITEM_MILK].active = false;
            mark_quest_done(rpg, Q_FIND_COWS);
        }
}
