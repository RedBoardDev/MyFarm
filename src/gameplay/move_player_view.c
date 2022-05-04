/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** move_player_view.c
*/

#include "../../include/rpg.h"

static bool color_is_white(sfColor color)
{
    return (color.r == 254 && color.g == 254 && color.b == 254);
}

static float getsp(rpg_t *rpg, sfColor color)
{
    sfSoundStatus st;

    if (color_is_white(color)) {
        st = sfSound_getStatus(rpg->sound.sound_list[SOUND_WATER].sound);
        if (st != sfPlaying)
            play_sound(rpg->sound.sound_list[SOUND_WATER].sound,
            rpg->sound.volume_effect);
        stop_sound(rpg->sound.sound_list[SOUND_WALK].sound);
        return (SPEED_PLAYER / 4);
    } else {
        st = sfSound_getStatus(rpg->sound.sound_list[SOUND_WALK].sound);
        if (st != sfPlaying)
            play_sound(rpg->sound.sound_list[SOUND_WALK].sound,
            rpg->sound.volume_effect / 1.9);
        stop_sound(rpg->sound.sound_list[SOUND_WATER].sound);
        return (SPEED_PLAYER);
    }
}

void move_player_and_view_horizontal(rpg_t *rpg, sfImage *image,
sfVector2f pos_player, bool move_view)
{
    sfColor color;
    if (rpg->all_events.right || rpg->all_events.d) {
        color = get_color_from_player(image,
        (sfVector2f){pos_player.x + 2, pos_player.y});
        if (rpg->spritesheet[rpg->player_stats.skin].pos.x > 385 &&
        rpg->begin.view.center.x < 1535 && color.r != 255 && move_view)
            rpg->begin.view.center.x += getsp(rpg, color);
        if (color.r != 255)
            rpg->spritesheet[rpg->player_stats.skin].pos.x += getsp(rpg, color);
    }
    if (rpg->all_events.left || rpg->all_events.q) {
        color = get_color_from_player(image,
        (sfVector2f){pos_player.x - 2, pos_player.y});
        if (rpg->spritesheet[rpg->player_stats.skin].pos.x < 1535 &&
        rpg->begin.view.center.x > 385 && color.r != 255 && move_view)
            rpg->begin.view.center.x -= getsp(rpg, color);
        if (color.r != 255)
            rpg->spritesheet[rpg->player_stats.skin].pos.x -= getsp(rpg, color);
    }
    set_view(rpg, rpg->begin.view.center);
}

void move_player_and_view_vertical(rpg_t *rpg, sfImage *image,
sfVector2f pos_player, bool move_view)
{
    sfColor color;
    if (rpg->all_events.up || rpg->all_events.z) {
        color = get_color_from_player(image,
        (sfVector2f){pos_player.x, pos_player.y - 2});
        if (rpg->spritesheet[rpg->player_stats.skin].pos.y < 1920 - 217 &&
        rpg->begin.view.center.y > 216 && color.r != 255 && move_view)
            rpg->begin.view.center.y -= getsp(rpg, color);
        if (color.r != 255)
            rpg->spritesheet[rpg->player_stats.skin].pos.y -= getsp(rpg, color);
    }
    if (rpg->all_events.down || rpg->all_events.s) {
        color = get_color_from_player(image,
        (sfVector2f){pos_player.x, pos_player.y + 2});
        if (rpg->spritesheet[rpg->player_stats.skin].pos.y > 216 &&
        rpg->begin.view.center.y < 1920 - 217 && color.r != 255 && move_view)
            rpg->begin.view.center.y += getsp(rpg, color);
        if (color.r != 255)
            rpg->spritesheet[rpg->player_stats.skin].pos.y += getsp(rpg, color);
    }
    set_view(rpg, rpg->begin.view.center);
}
