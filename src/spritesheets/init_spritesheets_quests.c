/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_spritesheets_quests.c
*/

#include "../../include/rpg.h"

void init_spritesheets_quests(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/bubble_chat.png",
    &spritesheet[SP_BUBBLE_CHAT], (init_sprite_t){{890, 810},
    {0.1, 0.1}, {0, 0, 798, 652}, false, false, .change_sprite_on_mouse = false});
}
