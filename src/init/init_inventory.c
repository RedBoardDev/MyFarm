/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_inventory.c
*/

#include "../../include/rpg.h"

void init_inventory(inventory_t *inventory)
{
    for (int i = 0; i < 10; ++i)
        inventory->cases[i] = -1;
    inventory->money = create_text((init_text_t){100, "SDFGHJKDFGHJK", sfRed,
    {825, 765}, "assets/fonts/NotoSerif-Regular.ttf"});
}