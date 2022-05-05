/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** draw_cutsceens.c
*/

#include "../../include/rpg.h"

static void draw_cutsceens_begin(rpg_t *rpg)
{
    sfSprite_setTexture(rpg->begin.sprite, rpg->begin.texture, sfFalse);
    sfTexture_updateFromPixels(rpg->begin.texture,
    rpg->begin.framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(rpg->begin.window,
    rpg->begin.sprite, NULL);
    for (int i = 0; i < NBR_CS; ++i) {
        if (rpg->cutsceens.spritesheet[CS_BEGIN_BACKGROUND].active)
            draw_one_sprite(&rpg->begin,
            rpg->cutsceens.spritesheet[CS_BEGIN_BACKGROUND].sprite,
            rpg->cutsceens.spritesheet[CS_BEGIN_BACKGROUND].rect,
            rpg->cutsceens.spritesheet[CS_BEGIN_BACKGROUND].pos);
    }
    draw_one_sprite(&rpg->begin,
    rpg->spritesheet[rpg->player_stats.skin].sprite,
    rpg->spritesheet[rpg->player_stats.skin].rect, rpg->cutsceens.pos_player);
    sfRenderWindow_display(rpg->begin.window);
}

void cutsceens_begin(rpg_t *rpg)
{
    draw_cutsceens_begin(rpg);
}
