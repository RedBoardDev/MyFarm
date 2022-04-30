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
        inventory->inventory_case[i].item_spritesheet = -1;
    inventory->money = create_text((init_text_t){120, "\0", sfBlack,
    {825, 760}, "assets/fonts/Sriracha-Regular.ttf"});
    inventory->inventory_case[0].pos = rpg->spritesheet[SP_INVENTORY].pos;
    // inventory->inventory_case[I_ATTACK].item_spritesheet = SP_ITEM_SWORD;
    inventory->inventory_case[2].item_spritesheet = SP_ITEM_PATATO;
    // inventory->inventory_case[3].item_spritesheet = SP_ITEM_SHOVEL;
    // inventory->inventory_case[4].item_spritesheet = SP_ITEM_HOE;
    // inventory->inventory_case[5].item_spritesheet = SP_ITEM_HAMMER;
    // inventory->inventory_case[6].item_spritesheet = SP_ITEM_FISHING_ROD;
    // inventory->inventory_case[8].item_spritesheet = SP_ITEM_CARROT;
    // inventory->inventory_case[9].item_spritesheet = SP_ITEM_TOMATE;
}
