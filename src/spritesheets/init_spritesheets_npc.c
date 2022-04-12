/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_spritesheets_npc.c
*/

#include "../../include/rpg.h"

void init_spritesheets_npc(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_one_sprite("assets/img/skins/NPC/soldiers.png",
    &spritesheet[SP_NPC_SOLDIER], begin, (init_sprite_t){{835, 860},
    {1, 1}, {0, 0, 34, 198 / 3}, true, false, .change_sprite_on_mouse = true});
}
