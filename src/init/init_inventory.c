/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_inventory.c
*/

#include "../../include/rpg.h"

void init_inventory(inventory_t *inventory, rpg_t *rpg)
{
    inventory->inventory_case = malloc(sizeof(inventory_t) * 12);
    for (int i = 0; i < 12; ++i)
        inventory->inventory_case[0].item_spritesheet = -1;
    inventory->money = create_text((init_text_t){120, "\0", sfBlack,
    {825, 760}, "assets/fonts/Sriracha-Regular.ttf"});
    inventory->inventory_case[0].pos = rpg->spritesheet[SP_INVENTORY].pos;
    inventory->inventory_case[2].item_spritesheet = SP_ITEM_PATATO;
}
