/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** cutscene_final.c
*/

#include "../../include/rpg.h"

static void move_cut_fps_ind(rpg_t *rpg)
{
    float delta = get_clock_time(rpg->begin.fps.clock) / 1000;

    rpg->begin.fps.timer += delta;
    while (rpg->begin.fps.timer >= 8) {
        if (rpg->cutscenes.status_move == 0)
            rpg->cutscenes.pos_player.x += 0.8;
        if (rpg->cutscenes.status_move == 1) {
            rpg->cutscenes.spritesheet[CS_FINAL_FLASK].pos.x += 1;
            rpg->cutscenes.spritesheet[CS_FINAL_FLASK].pos.y += 0.1;
        }
        if (rpg->cutscenes.status_move == 2) {
            rpg->cutscenes.spritesheet[CS_FINAL_MONIK].pos.y -= 0.8;
        }
        rpg->begin.fps.timer -= 8;
    }
    sfClock_restart(rpg->begin.fps.clock);
}

static void move_flask(rpg_t *rpg, sfSoundStatus st)
{
    if (st == sfPlaying) {
        rpg->cutscenes.status_move = 1;
        rpg->cutscenes.clock = sfClock_create();
        stop_sound(rpg->sound.sound_list[SOUND_WALK].sound);
        rpg->spritesheet[rpg->player_stats.skin].rect.left = 0;
        rpg->cutscenes.spritesheet[CS_FINAL_FLASK].active = true;
    }
}

static void cutscene_final_step(rpg_t *rpg)
{
    if (rpg->cutscenes.spritesheet[CS_FINAL_FLASK].pos.x >= 1506) {
        if (rpg->cutscenes.status_move == 1)
            play_sound(rpg->sound.sound_list[SOUND_GLASS_BREAK].sound,
            rpg->sound.volume_effect);
        rpg->cutscenes.status_move = 2;
        rpg->cutscenes.spritesheet[CS_FINAL_FLASK].active = false;
        rpg->cutscenes.spritesheet[CS_FINAL_MONIK].active = true;
    }
    if (rpg->cutscenes.status_move == 2
    && rpg->cutscenes.spritesheet[CS_FINAL_MONIK].pos.y <= 800) {
        sfSprite_setRotation(rpg->cutscenes.
        spritesheet[CS_FINAL_MONIK].sprite, 0);
        rpg->cutscenes.status_move = 3;
    }
    if (rpg->cutscenes.status_move == 3) {
        rpg->cutscenes.spritesheet[CS_FINAL_BUBULLE_HEART].active = true;
        if (get_clock_time(rpg->cutscenes.clock) >= SECOND_TO_MICRO(8))
            sfRenderWindow_close(rpg->begin.window);
    }
}

void cutscenes_final(rpg_t *rpg)
{
    sfSoundStatus st =
    sfSound_getStatus(rpg->sound.sound_list[SOUND_WALK].sound);

    if (rpg->all_events.enter)
        sfRenderWindow_close(rpg->begin.window);
    if (rpg->cutscenes.pos_player.x <= 1200) {
        if (st != sfPlaying) {
            play_sound(rpg->sound.sound_list[SOUND_WALK].sound,
            rpg->sound.volume_effect);
        }
        animate_player_cutscene(rpg, 1);
    } else
        move_flask(rpg, st);
    cutscene_final_step(rpg);
    move_cut_fps_ind(rpg);
    draw_cutscenes(rpg);
}
