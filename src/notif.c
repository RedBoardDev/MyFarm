/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** notif.c
*/

#include "../include/rpg.h"

void draw_text_notif(rpg_t *rpg)
{
    unsigned int char_size = 0;
    sfVector2f origin = {0, 0};
    const char *text = sfText_getString(rpg->notif.text);
    sfVector2f pos = rpg->spritesheet[SP_NOTIF].pos;
    float zoom = get_zoom(rpg->begin.view.view);

    sfText_setCharacterSize(rpg->notif.text, 200 * zoom);
    char_size = sfText_getCharacterSize(rpg->notif.text);
    origin.x = (my_strlen(text) * char_size) / 4.5;
    origin.y = char_size / 1.5;
    sfText_setOrigin(rpg->notif.text, origin);
    sfText_setPosition(rpg->notif.text, pos);
    sfRenderWindow_drawSprite(rpg->begin.window,
    rpg->spritesheet[SP_NOTIF].sprite, NULL);
    write_text(rpg->begin.window, rpg->notif.text);
}

void draw_notif(rpg_t *rpg)
{
    float zoom = get_zoom(rpg->begin.view.view);
    sfVector2f pos_hide = {rpg->begin.view.center.x + ((WIDTH / 2) * zoom) +
    (250 * zoom),
    rpg->begin.view.center.y - ((HEIGHT / 2) * zoom) + (50 * zoom)};
    sfVector2f scale = {0.5 * zoom, 0.5 * zoom};

    sfSprite_setScale(rpg->spritesheet[SP_NOTIF].sprite, scale);
    if (rpg->notif.toggle_notif) {
        rpg->spritesheet[SP_NOTIF].active = true;
        rpg->notif.offset_hide.x = 0;
        rpg->notif.inc_pos = -4;
        sfClock_restart(rpg->spritesheet[SP_NOTIF].c_anim);
        rpg->notif.toggle_notif = false;
    }
    if (get_clock_time(rpg->spritesheet[SP_NOTIF].c_anim) >= SECOND_TO_MICRO(5)
    && rpg->spritesheet[SP_NOTIF].pos.x < pos_hide.x)
        rpg->notif.inc_pos = 4;
}

void send_notif(rpg_t *rpg, char *text)
{
    rpg->notif.toggle_notif = true;
    sfText_setString(rpg->notif.text, text);
}

void move_notif(rpg_t *rpg)
{
    float zoom = get_zoom(rpg->begin.view.view);
    float real_pos = 0;
    float pos_show = rpg->begin.view.center.x + ((WIDTH / 2) * zoom) -
    (250 * zoom);
    float pos_hide = rpg->begin.view.center.x + ((WIDTH / 2) * zoom) +
    (250 * zoom);
    float pos_y = rpg->begin.view.center.y - ((HEIGHT / 2) * zoom) +
    (50 * zoom);
    if (rpg->spritesheet[SP_NOTIF].pos.x > pos_hide) {
        rpg->notif.inc_pos = 0;
        rpg->notif.offset_hide.x = 0;
    }
    if (rpg->spritesheet[SP_NOTIF].pos.x < pos_show) {
        rpg->notif.inc_pos = 0;
        rpg->notif.offset_hide.x = 500;
    }
    rpg->notif.offset_hide.x = rpg->notif.offset_hide.x - rpg->notif.inc_pos;
    real_pos = rpg->begin.view.center.x + ((WIDTH / 2) * zoom) +
    ((250 - rpg->notif.offset_hide.x) * zoom);
    rpg->spritesheet[SP_NOTIF].pos = (sfVector2f){real_pos, pos_y};
}
