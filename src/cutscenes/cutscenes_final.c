/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** cutscene_final.c
*/

#include "../../include/rpg.h"

// static void move_cut_fps_ind(rpg_t *rpg)
// {
//     float delta = get_clock_time(rpg->begin.fps.clock) / 1000;

//     rpg->begin.fps.timer += delta;
//     while (rpg->begin.fps.timer >= 8) {
//         rpg->cutscenes.pos_player.x += 0.8;
//         rpg->begin.fps.timer -= 8;
//     }
//     sfClock_restart(rpg->begin.fps.clock);
// }

void cutscenes_final(rpg_t *rpg)
{
    // sfSoundStatus st =
    // sfSound_getStatus(rpg->sound.sound_list[SOUND_WALK].sound);

    // if (rpg->all_events.enter) {
    //     toggle_cutscene(rpg, SC_CUTSCENE_FINAL, false);
    // }
    // if (rpg->cutscenes.pos_player.x <= 1200) {
    //     if (st != sfPlaying)
    //         play_sound(rpg->sound.sound_list[SOUND_WALK].sound,
    //         rpg->sound.volume_effect);
    //     move_cut_fps_ind(rpg);
    //     animate_player_cutscene(rpg, 1);
    // }
    rpg->cutscenes.spritesheet[CS_BEGIN_BACKGROUND].active = true;
    draw_cutscenes(rpg);
}