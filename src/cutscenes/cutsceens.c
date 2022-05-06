/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** draw_cutsceens.c
*/

#include "../../include/rpg.h"

static void draw_cutsceens(rpg_t *rpg)
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

static void move_cut_fps_ind(rpg_t *rpg)
{
    float delta = get_clock_time(rpg->begin.fps.clock) / 1000;

    rpg->begin.fps.timer += delta;
    while (rpg->begin.fps.timer >= 8) {
        rpg->cutsceens.pos_player.x += 0.8;
        rpg->begin.fps.timer -= 8;
    }
    sfClock_restart(rpg->begin.fps.clock);
}

static void play_sound_and_launch_game(rpg_t *rpg, sfSoundStatus st)
{
    if (st == sfPlaying) {
        rpg->cutsceens.clock = sfClock_create();
        stop_sound(rpg->sound.sound_list[SOUND_WALK].sound);
        rpg->spritesheet[rpg->player_stats.skin].rect.left = 0;
        rpg->cutsceens.spritesheet[CS_BEGIN_BUBULLE].active = true;
    }
    if (get_clock_time(rpg->cutsceens.clock) >= SECOND_TO_MICRO(4)) {
        rpg->screen[SC_CUTSCENE_BEGIN].active = false;
        launch_game(rpg);
    }
}

void cutsceens_begin(rpg_t *rpg)
{
    sfSoundStatus st =
    sfSound_getStatus(rpg->sound.sound_list[SOUND_WALK].sound);

    if (rpg->all_events.enter) {
        toggle_cutscene(rpg, SC_CUTSCENE_BEGIN, false);
        launch_game(rpg);
    }
    if (rpg->cutsceens.pos_player.x <= 1200) {
        if (st != sfPlaying)
            play_sound(rpg->sound.sound_list[SOUND_WALK].sound,
            rpg->sound.volume_effect);
        move_cut_fps_ind(rpg);
        animate_player_cutscene(rpg, 1);
    } else
        play_sound_and_launch_game(rpg, st);
    draw_cutsceens(rpg);
}
