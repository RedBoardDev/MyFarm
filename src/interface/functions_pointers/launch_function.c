/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** launch_function.c
*/

#include "../../../include/rpg.h"

void launch_begin_cutscene(rpg_t *rpg)
{
    sfSprite_setScale(rpg->spritesheet[rpg->player_stats.skin].sprite,
    (sfVector2f){5, 5});
    stop_sound(rpg->sound.sound_list[SOUND_MENU].sound);
    play_sound(rpg->sound.sound_list[SOUND_AMBIANT_CUTSCENE].sound,
    rpg->sound.volume_music);
    toggle_cutscene(rpg, SC_CUTSCENE_BEGIN, true);
}

void launch_final_cutscene(rpg_t *rpg)
{
    sfSprite_setScale(rpg->spritesheet[rpg->player_stats.skin].sprite,
    (sfVector2f){5, 5});
    stop_sound(rpg->sound.sound_list[SOUND_MAIN].sound);
    rpg->cutscenes.pos_player = (sfVector2f){-20, 880};
    play_sound(rpg->sound.sound_list[SOUND_AMBIANT_CUTSCENE].sound,
    rpg->sound.volume_music);
    button_option_game(rpg);
    toggle_cutscene(rpg, SC_CUTSCENE_FINAL, true);
}

void launch_game(rpg_t *rpg)
{
    sfClock_restart(rpg->spritesheet[SP_NPC_GUIDE].c_anim);
    rpg->spritesheet[rpg->player_stats.skin].pos =
    (sfVector2f){SPAWN_X, SPAWN_Y};
    set_view(rpg, (sfVector2f){SPAWN_X, SPAWN_Y});
    sfSprite_setScale(rpg->spritesheet[rpg->player_stats.skin].sprite,
    (sfVector2f){0.7, 0.7});
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
