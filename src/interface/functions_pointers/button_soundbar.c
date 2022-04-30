/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button_soundbar.c
*/

#include "../../../include/rpg.h"

int check_click_soundbox(rpg_t *rpg)
{
    sfFloatRect collision_music =
    sfSprite_getGlobalBounds(rpg->spritesheet[SP_SOUND_SLIDER_MUSIC].sprite);

    sfFloatRect collision_effect =
    sfSprite_getGlobalBounds(rpg->spritesheet[SP_SOUND_SLIDER_EFFECT].sprite);

    if (check_mouse_on_one_button_int(rpg->all_events.mouse.pos,
    collision_music)) {
        rpg->all_events.mouse.left = false;
        return (SP_SOUND_SLIDER_MUSIC);
    } else if (check_mouse_on_one_button_int(rpg->all_events.mouse.pos,
    collision_effect)) {
        rpg->all_events.mouse.left = false;
        return (SP_SOUND_SLIDER_EFFECT);
    }
    return (0);
}

static void modify_sound_volume(rpg_t *rpg, int type, int volume)
{
    if (type == SP_SOUND_SLIDER_MUSIC) {
        rpg->sound.volume_music = volume;
        for (int i = SOUND_MENU; i < NBR_SOUND; ++i)
            sfSound_setVolume(rpg->sound.sound_list[i].sound,
            rpg->sound.volume_music);
    } else {
        rpg->sound.volume_effect = volume;
        for (int i = 0; i <= SOUND_DIE_PLAYER; ++i)
            sfSound_setVolume(rpg->sound.sound_list[i].sound,
            rpg->sound.volume_effect);
    }
}

void move_sound_box(rpg_t *rpg)
{
    int pos_x = rpg->all_events.mouse.pos.x;

    if (!rpg->sound.volume_active)
        return;
    if (pos_x >= 200 && pos_x <= 708) {
        rpg->spritesheet[rpg->sound.volume_active].pos.x = pos_x;
        if (rpg->sound.volume_active == SP_SOUND_SLIDER_MUSIC)
            modify_sound_volume(rpg, SP_SOUND_SLIDER_MUSIC,
            (pos_x - 200) / 5.05);
        else if (rpg->sound.volume_active == SP_SOUND_SLIDER_EFFECT)
            modify_sound_volume(rpg, SP_SOUND_SLIDER_EFFECT,
            (pos_x - 200) / 5.05);
    }
    rpg->sound.volume_music < 1 ? rpg->sound.volume_music = 0 : 0;
    rpg->sound.volume_effect < 1 ? rpg->sound.volume_effect = 0 : 0;
}

void button_toggle_sound_effect(rpg_t *rpg)
{
    if (rpg->spritesheet[SP_SOUND_EFFECT].rect.left == 0) {
        rpg->spritesheet[SP_SOUND_EFFECT].rect.left += 300;
        rpg->sound.volume_effect_backup = rpg->sound.volume_effect;
        rpg->sound.volume_effect = 0;
        rpg->spritesheet[SP_SOUND_SLIDER_EFFECT].pos.x = 200;
    } else {
        rpg->spritesheet[SP_SOUND_EFFECT].rect.left -= 300;
        rpg->sound.volume_effect = rpg->sound.volume_effect_backup;
        rpg->spritesheet[SP_SOUND_SLIDER_EFFECT].pos.x =
        rpg->sound.volume_effect * 5.05 + 200;
    }
    modify_sound_volume(rpg, SP_SOUND_SLIDER_EFFECT,
    rpg->sound.volume_effect);
}

void button_toggle_sound_music(rpg_t *rpg)
{
    if (rpg->spritesheet[SP_SOUND_MUSIC].rect.left == 0) {
        rpg->spritesheet[SP_SOUND_MUSIC].rect.left += 300;
        rpg->sound.volume_music_backup = rpg->sound.volume_music;
        rpg->sound.volume_music = 0;
        rpg->spritesheet[SP_SOUND_SLIDER_MUSIC].pos.x = 200;
    } else {
        rpg->spritesheet[SP_SOUND_MUSIC].rect.left -= 300;
        rpg->sound.volume_music = rpg->sound.volume_music_backup;
        rpg->spritesheet[SP_SOUND_SLIDER_MUSIC].pos.x =
        rpg->sound.volume_music * 5.05 + 200;
    }
    modify_sound_volume(rpg, SP_SOUND_SLIDER_MUSIC,
    rpg->sound.volume_music);
}
