/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** die.c
*/

#include "../include/rpg.h"

void return_home(rpg_t *rpg)
{
    init_all_events(&rpg->all_events);
    rpg->player_stats.incr_pos.x = 0;
    rpg->player_stats.incr_pos.y = 0;
    rpg->player_stats.speed = 1.0;
    rpg->player_stats.life = 20.0;
    move_life_bar(rpg, rpg->player_stats.life * 5);
    set_view(rpg, rpg->screen[SC_MAIN_MAP].view_pos);
    for (int i = 0; i < NBR_SP; ++i)
        rpg->spritesheet[i].active = false;
    for (int i = 0; i < NBR_SC; ++i)
        rpg->screen[i].active = false;
    toggle_spritesheet_scene(rpg, true, SC_MAIN_MAP);
    set_view(rpg, (sfVector2f){SPAWN_X, SPAWN_Y});
    rpg->spritesheet[rpg->player_stats.skin].pos =
    (sfVector2f){SPAWN_X, SPAWN_Y};
    send_notif(rpg, "Back home");
}

void stop_all_sounds(rpg_t *rpg)
{
    for (int i = 0; i < NBR_SOUND; ++i)
        stop_sound(rpg->sound.sound_list[i].sound);
}

void die_player(rpg_t *rpg)
{
    stop_all_sounds(rpg);
    play_sound(rpg->sound.sound_list[SOUND_DIE_PLAYER].sound,
    rpg->sound.volume_effect);
    play_main_sound(rpg);
    return_home(rpg);
}
