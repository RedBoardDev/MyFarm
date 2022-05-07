/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** utils_cutscenes.c
*/

#include "../../include/rpg.h"

void draw_cutscenes(rpg_t *rpg)
{
    sfSprite_setTexture(rpg->begin.sprite, rpg->begin.texture, sfFalse);
    sfTexture_updateFromPixels(rpg->begin.texture,
    rpg->begin.framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(rpg->begin.window,
    rpg->begin.sprite, NULL);
    for (int i = 0; i < NBR_CS; ++i) {
        if (!rpg->cutscenes.spritesheet[i].active)
            continue;
        if (i == CS_PLAYER)
            draw_one_sprite(&rpg->begin,
            rpg->spritesheet[rpg->player_stats.skin].sprite,
            rpg->spritesheet[rpg->player_stats.skin].rect,
            rpg->cutscenes.pos_player);
        else
            draw_one_sprite(&rpg->begin,
            rpg->cutscenes.spritesheet[i].sprite,
            rpg->cutscenes.spritesheet[i].rect,
            rpg->cutscenes.spritesheet[i].pos);
    }
    sfRenderWindow_display(rpg->begin.window);
}

void cutscenes_choose(rpg_t *rpg)
{
    switch (rpg->cutscenes.cutscene_nbr) {
    case SC_CUTSCENE_BEGIN:
        cutscenes_begin(rpg);
        break;
    case SC_CUTSCENE_FINAL:
        cutscenes_final(rpg);
        break;
    default:
        rpg->cutscenes.cutscene_nbr = -1;
        break;
    }
}
