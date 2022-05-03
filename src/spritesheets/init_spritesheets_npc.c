/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_spritesheets_npc.c
*/

#include "../../include/rpg.h"

void init_spritesheets_npc(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/skins/npc/soldiers.png",
    &spritesheet[SP_NPC_SOLDIER], (init_sprite_t){{100, 417 - 130},
    {1, 1}, {0, 0, 34, 198 / 3}, true, false, .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/skins/npc/seller.png",
    &spritesheet[SP_NPC_SELLER], (init_sprite_t){{1000, 100},
    {1, 1}, {0, 0, 31, 192 / 3}, true, false, .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/skins/npc/npc_guide.png",
    &spritesheet[SP_NPC_GUIDE], (init_sprite_t){{870, 1025},
    {1, 1}, {0, 0, 31, 189 / 3}, true, false, .change_sprite_on_mouse = true});
}
