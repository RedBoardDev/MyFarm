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
    sfSoundStatus st =
    sfSound_getStatus(rpg->sound.sound_list[SOUND_WALK].sound);

    if (get_clock_time(rpg->cutsceens.clock) >= SECOND_TO_MICRO(20)
    || rpg->all_events.enter) {
        rpg->screen[SC_CUTSCENE_BEGIN].active = false;
        launch_game(rpg);
    }
    if (rpg->cutsceens.pos_player.x <= 1200) {
        if (st != sfPlaying)
            play_sound(rpg->sound.sound_list[SOUND_WALK].sound,
            rpg->sound.volume_effect);
        rpg->cutsceens.pos_player.x += 0.8;
        animate_player_cutscene(rpg, 1);
    } else {
        if (st == sfPlaying)
            stop_sound(rpg->sound.sound_list[SOUND_WALK].sound);
        rpg->cutsceens.spritesheet[CS_BEGIN_BUBULLE].active = true;
    }
    draw_cutsceens_begin(rpg);
}
