/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button_menu.c
*/

#include "../../../include/rpg.h"

void how_play(rpg_t *rpg)
{
    sfSprite_setColor(rpg->spritesheet[SP_BACKGROUND_HOW_PLAY].sprite,
    (sfColor){255, 255, 255, 140});
    toggle_spritesheet_scene(rpg, false, SC_MENU);
    toggle_spritesheet_scene(rpg, true, SC_HOW_PLAY);
    sfClock_restart(rpg->spritesheet[SP_NPC_GUIDE].c_anim);
}

void display_custom_skins(rpg_t *rpg)
{
    reset_all_players(rpg);
    sfSprite_setColor(rpg->spritesheet[SP_BACKGROUND_SC_MENU].sprite,
    (sfColor){255, 255, 255, 180});
    toggle_spritesheet_scene(rpg, false, SC_MENU);
    toggle_spritesheet_scene(rpg, true, SC_CUSTOM_SKINS);
}

void set_player(rpg_t *rpg)
{
    sfSprite_setScale(rpg->spritesheet[rpg->player_stats.skin].sprite,
    (sfVector2f){0.7, 0.7});
}

void launch_begin_cutscene(rpg_t *rpg)
{
    rpg->screen[SC_CUTSCENE_BEGIN].active = true;
    sfSprite_setScale(rpg->spritesheet[rpg->player_stats.skin].sprite,
    (sfVector2f){5, 5});
    sfClock_restart(rpg->cutsceens.clock);
    stop_sound(rpg->sound.sound_list[SOUND_MENU].sound);
}

void launch_game(rpg_t *rpg)
{
    rpg->spritesheet[rpg->player_stats.skin].pos =
    (sfVector2f){SPAWN_X, SPAWN_Y};
    set_view(rpg, (sfVector2f){SPAWN_X, SPAWN_Y});
    set_player(rpg);
    stop_all_sounds(rpg);
    play_main_sound(rpg);
    if (rpg->screen[SC_MENU].active) {
        toggle_spritesheet_scene(rpg, false, SC_CUSTOM_SKINS);
        toggle_spritesheet_scene(rpg, false, SC_MENU);
    }
    if (rpg->screen[SC_CUSTOM_SKINS].active) {
        toggle_spritesheet_scene(rpg, false, SC_MENU);
        toggle_spritesheet_scene(rpg, false, SC_CUSTOM_SKINS);
    }
    toggle_spritesheet_scene(rpg, true, SC_MAIN_MAP);
}

void button_option_main_menu(rpg_t *rpg)
{
    toggle_spritesheet_scene(rpg, false, SC_MENU);
    toggle_spritesheet_scene(rpg, true, SC_OPTION);
    set_view(rpg, rpg->screen[SC_OPTION].view_pos);
}
