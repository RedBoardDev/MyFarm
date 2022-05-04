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
    inventory->attack = create_text((init_text_t){120, "\0", sfBlack,
    {825, 760}, "assets/fonts/Sriracha-Regular.ttf"});
    inventory->life = create_text((init_text_t){120, "\0", sfBlack,
    {825, 760}, "assets/fonts/Sriracha-Regular.ttf"});
    inventory->speed = create_text((init_text_t){120, "\0", sfBlack,
    {825, 760}, "assets/fonts/Sriracha-Regular.ttf"});
    inventory->quests = create_text((init_text_t){120, "\0", sfBlack,
    {825, 760}, "assets/fonts/Sriracha-Regular.ttf"});
    inventory->inventory_case[0].pos = rpg->spritesheet[SP_INVENTORY].pos;
    inventory->inventory_case[I_CASE_1].item_spritesheet = SP_ITEM_PATATO;
    inventory->inventory_case[I_CASE_2].item_spritesheet = SP_ITEM_SHOVEL;
    inventory->inventory_case[I_CASE_3].item_spritesheet = SP_ITEM_BEETS;
    inventory->inventory_case[I_CASE_3].item_spritesheet = SP_FLASK_ATTACK;
}
