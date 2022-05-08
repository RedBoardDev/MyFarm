/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_spritesheet_cutscenes.c
*/

#include "../../include/rpg.h"

static const int cutscene_begin[] = {CS_BEGIN_BACKGROUND, CS_PLAYER,
CS_BEGIN_BUBULLE, -1};
static const int cutscene_final[] = {CS_BEGIN_BACKGROUND, CS_PLAYER, -1};

void toggle_cutscene(rpg_t *rpg, int screen_id, bool status)
{
    rpg->screen[screen_id].active = status;

    if (!status)
        rpg->cutscenes.cutscene_nbr = -1;
    else
        rpg->cutscenes.cutscene_nbr = screen_id;
    for (int i = 0; rpg->screen[screen_id].const_screen[i] != -1; ++i)
        if (!(rpg->screen[screen_id].const_screen[i] == CS_BEGIN_BUBULLE
        && status))
            rpg->cutscenes.spritesheet[rpg->screen[screen_id].
            const_screen[i]].active = status;
}

static void init_spritehseet_cutscenes_norme(rpg_t *rpg)
{
    set_one_sprite("assets/img/cutscenes/mom_reborn.png",
    &rpg->cutscenes.spritesheet[CS_FINAL_MONIK],
    (init_sprite_t){{1520, 965}, {6, 6}, {0, 0, 33, 53},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    sfSprite_setRotation(rpg->cutscenes.spritesheet[CS_FINAL_MONIK].sprite, 90);
    set_one_sprite("assets/img/item/flask_revive.png",
    &rpg->cutscenes.spritesheet[CS_FINAL_FLASK],
    (init_sprite_t){{1190, 945}, {1, 1}, {0, 0, 64, 64},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/cutscenes/heart_bubulle.png",
    &rpg->cutscenes.spritesheet[CS_FINAL_BUBULLE_HEART],
    (init_sprite_t){{1340, 630}, {1, 1}, {0, 0, 203, 196},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
}

void init_spritehseet_cutscenes(rpg_t *rpg)
{
    rpg->cutscenes.status_move = 0;
    rpg->cutscenes.cutscene_nbr = -1;
    rpg->cutscenes.spritesheet = malloc(sizeof(spritesheet_t) * NBR_CS);
    rpg->cutscenes.pos_player = (sfVector2f){-20, 880};
    rpg->screen[SC_CUTSCENE_BEGIN].const_screen = cutscene_begin;
    rpg->screen[SC_CUTSCENE_FINAL].const_screen = cutscene_final;
    set_one_sprite("assets/img/cutscenes/cut_scene_background.png",
    &rpg->cutscenes.spritesheet[CS_BEGIN_BACKGROUND],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {1, 1}, {0, 0, 1920, 1080},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/cutscenes/chat_bubble.png",
    &rpg->cutscenes.spritesheet[CS_BEGIN_BUBULLE],
    (init_sprite_t){{1350, 650}, {1, 1}, {0, 0, 250, 232},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    init_spritehseet_cutscenes_norme(rpg);
}
