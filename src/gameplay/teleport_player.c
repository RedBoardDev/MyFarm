/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** teleport.c
*/

#include "../../include/rpg.h"

static void teleport_grotte(rpg_t *rpg)
{
    if (rpg->screen[SC_MAIN_MAP].active) {
        rpg->boss_stats.life = 20;
        rpg->spritesheet[rpg->player_stats.skin].pos.x = 444 - 200;
        rpg->begin.view.center = rpg->screen[SC_GROTTE].view_pos;
        toggle_spritesheet_scene(rpg, false, SC_MAIN_MAP);
        toggle_spritesheet_scene(rpg, true, SC_GROTTE);
    } else {
        rpg->spritesheet[rpg->player_stats.skin].pos =
        rpg->screen[SC_MAIN_MAP].view_pos;
        rpg->begin.view.center = rpg->screen[SC_MAIN_MAP].view_pos;
        toggle_spritesheet_scene(rpg, false, SC_GROTTE);
        toggle_spritesheet_scene(rpg, true, SC_MAIN_MAP);
    }
}

static void teleport_cemetery(rpg_t *rpg)
{
    if (rpg->screen[SC_MAIN_MAP].active) {
        rpg->begin.view.center = rpg->screen[SC_CEMETERY].view_pos;
        rpg->boss_stats.life = 20;
        toggle_spritesheet_scene(rpg, false, SC_MAIN_MAP);
        toggle_spritesheet_scene(rpg, true, SC_CEMETERY);
    }
}

static void teleport_player_scene_norme(rpg_t *rpg, sfColor color)
{
    switch (color.b) {
    case B_TENTE:
            play_sound(rpg->sound.sound_list[SOUND_DOOR].sound,
            rpg->sound.volume);
            teleport_tente(rpg);
            break;
        case B_GROTTE:
            play_sound(rpg->sound.sound_list[SOUND_DOOR].sound,
            rpg->sound.volume);
            teleport_grotte(rpg);
            break;
        case B_CEMETERY:
            play_sound(rpg->sound.sound_list[SOUND_DOOR].sound,
            rpg->sound.volume);
            teleport_cemetery(rpg);
            break;
    default:
        break;
    }
}

void teleport_player_scene(rpg_t *rpg, sfImage *image, sfVector2f pos_player)
{
    sfColor color;

    color = get_color_from_player(image, pos_player);
    switch (color.b) {
        case B_BASE:
            play_sound(rpg->sound.sound_list[SOUND_DOOR].sound,
            rpg->sound.volume);
            teleport_base(rpg);
            break;
        case B_JAIL:
            play_sound(rpg->sound.sound_list[SOUND_DOOR].sound,
            rpg->sound.volume);
            teleport_jail(rpg);
            break;
        default:
            teleport_player_scene_norme(rpg, color);
            break;
    }
}
