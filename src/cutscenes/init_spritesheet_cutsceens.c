/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_spritesheet_cutsceens.c
*/

#include "../../include/rpg.h"

static const int cutscene_begin[] = {CS_BEGIN_BACKGROUND, CS_BEGIN_BUBULLE,-1};

void toggle_cutscene(rpg_t *rpg, int screen_id, bool status)
{
    rpg->screen[screen_id].active = status;

    for (int i = 0; rpg->screen[screen_id].const_screen[i] != -1; ++i)
        if (!(rpg->screen[screen_id].const_screen[i] == CS_BEGIN_BUBULLE
        && status))
            rpg->cutsceens.spritesheet[rpg->screen[screen_id].
            const_screen[i]].active = status;
}

void init_spritehseet_cutsceens(rpg_t *rpg)
{
    rpg->cutsceens.spritesheet = malloc(sizeof(spritesheet_t) * NBR_CS);
    rpg->cutsceens.pos_player = (sfVector2f){-20, 880};
    rpg->screen[SC_CUTSCENE_BEGIN].const_screen = cutscene_begin;
    set_one_sprite("assets/img/cutsceens/cut_scene_background.png",
    &rpg->cutsceens.spritesheet[CS_BEGIN_BACKGROUND],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {1, 1}, {0, 0, 1920, 1080},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/cutsceens/chat_bubble.png",
    &rpg->cutsceens.spritesheet[CS_BEGIN_BUBULLE],
    (init_sprite_t){{1350, 650}, {1, 1}, {0, 0, 250, 232},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
}
