/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_spritesheets_quests.c
*/

#include "../../include/rpg.h"

void init_spritesheets_quests(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/bubble_chat_player.png",
    &spritesheet[SP_BUBBLE_CHAT], (init_sprite_t){{860, 790},
    {0.08, 0.08}, {0, 0, 798, 652}, false, false, false});
    set_one_sprite("assets/img/tombe.png",
    &spritesheet[SP_TOMBE], (init_sprite_t){{328, 1834},
    {0.06, 0.06}, {0, 0, 400, 538}, false, false, false});
}
