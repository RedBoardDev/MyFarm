/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** animate_player.c
*/

#include "../../include/rpg.h"

static void move_animate_player(rpg_t *rpg)
{
    rpg->spritesheet[rpg->player_stats.skin].rect.left += 48;
    if (rpg->all_events.down || rpg->all_events.s)
        rpg->spritesheet[rpg->player_stats.skin].rect.top = 0;
    if (rpg->all_events.up || rpg->all_events.z)
        rpg->spritesheet[rpg->player_stats.skin].rect.top = 64 * 3;
    if (rpg->all_events.left || rpg->all_events.q)
        rpg->spritesheet[rpg->player_stats.skin].rect.top = 64 * 1;
    if (rpg->all_events.right || rpg->all_events.d)
        rpg->spritesheet[rpg->player_stats.skin].rect.top = 64 * 2;
    if (rpg->spritesheet[rpg->player_stats.skin].rect.left >= 192)
        rpg->spritesheet[rpg->player_stats.skin].rect.left = 0;
    sfClock_restart(rpg->spritesheet[rpg->player_stats.skin].c_anim);
    play_sound(rpg->sound.sound_list[SOUND_WALK].sound, rpg->sound.volume);
}

void animate_player(rpg_t *rpg)
{
    sfColor color = get_color_from_player(rpg->imgs_colors.main_map,
    rpg->spritesheet[rpg->player_stats.skin].pos);
    float time_player =
    get_clock_time(rpg->spritesheet[rpg->player_stats.skin].c_anim);

    if (!rpg->all_events.down && !rpg->all_events.up && !rpg->all_events.left
    && !rpg->all_events.right && !rpg->all_events.s && !rpg->all_events.z
    && !rpg->all_events.q && !rpg->all_events.d)
        rpg->spritesheet[rpg->player_stats.skin].rect.left = 0;
    else if (time_player >= 200000)
        move_animate_player(rpg);
    if (!rpg->screen[SC_MAIN_MAP].active)
        return;
    if (color.g == 255
    && rpg->spritesheet[rpg->player_stats.skin].rect.top < 256)
        rpg->spritesheet[rpg->player_stats.skin].rect.top += 256;
    else if (color.g != 255
    && rpg->spritesheet[rpg->player_stats.skin].rect.top >= 256)
        rpg->spritesheet[rpg->player_stats.skin].rect.top -= 256;
}

void animate_selected_skin(rpg_t *rpg)
{
    float time_player =
    get_clock_time(rpg->spritesheet[rpg->player_stats.skin].c_anim);
    if (time_player >= 200000) {
        rpg->spritesheet[rpg->player_stats.skin].rect.left += 48;
        sfClock_restart(rpg->spritesheet[rpg->player_stats.skin].c_anim);
    }
    if (rpg->spritesheet[rpg->player_stats.skin].rect.left >= 192)
        rpg->spritesheet[rpg->player_stats.skin].rect.left = 0;
}
