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
        if (rpg->cutsceens.spritesheet[i].active)
            draw_one_sprite(&rpg->begin,
            rpg->cutsceens.spritesheet[i].sprite,
            rpg->cutsceens.spritesheet[i].rect,
            rpg->cutsceens.spritesheet[i].pos);
    }
    draw_one_sprite(&rpg->begin,
    rpg->spritesheet[rpg->player_stats.skin].sprite,
    rpg->spritesheet[rpg->player_stats.skin].rect, rpg->cutsceens.pos_player);
    sfRenderWindow_display(rpg->begin.window);
}

void cutsceens_begin(rpg_t *rpg)
{
    rpg->cutsceens.pos_player.x++;
    animate_player_cutscene(rpg, 1);
    sfSprite_setScale(rpg->spritesheet[rpg->player_stats.skin].sprite,
    (sfVector2f){3, 3});
    draw_cutsceens_begin(rpg);
}
