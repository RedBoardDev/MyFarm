/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_spritesheet_cutsceens.c
*/

#include "../../include/rpg.h"

void init_spritehseet_cutsceens(rpg_t *rpg)
{
    rpg->cutsceens.spritesheet = malloc(sizeof(spritesheet_t) * NBR_CS);
    rpg->cutsceens.pos_player = (sfVector2f){400, 800};
    set_one_sprite("assets/img/cutsceens/background_begin.png",
    &rpg->cutsceens.spritesheet[CS_BEGIN_BACKGROUND],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {1, 1}, {0, 0, 1920, 1080},
    .clickable = false, .active = true, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/skins/npc_front.png",
    &rpg->cutsceens.spritesheet[CS_PLAYER_FRONT],
    (init_sprite_t){{400, 800}, {1, 1}, {0, 0, 304 / 8, 51},
    .clickable = false, .active = true, .change_sprite_on_mouse = false});
}
