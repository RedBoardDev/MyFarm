/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** draw_all.c
*/

#include "../include/rpg.h"

void draw_sfImage(sfRenderWindow *window, sfImage *image, sfVector2f pos,
sfIntRect rect)
{
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    sfSprite *sprite = sfSprite_create();
    sfImage_createMaskFromColor(image, (sfColor){0, 0, 0, 100}, 100);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite, rect);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

static void draw_spritesheets(beginning_t *begin, spritesheet_t *spritesheet)
{
    sfVector2i po = sfMouse_getPositionRenderWindow(begin->window);
    spritesheet[SP_CURSOR].pos =
    sfRenderWindow_mapPixelToCoords(begin->window, po, begin->view.view);
    for (int i = 0; i < NBR_SP - 1; ++i)
        if (spritesheet[i].active)
            draw_one_sprite(begin, spritesheet[i].sprite, spritesheet[i].rect,
            spritesheet[i].pos);
}

void draw_inventory(inventory_t inventory, beginning_t *begin,
spritesheet_t *spritesheet)
{
    write_text(begin->window, inventory.money);
    for (int i = 0; i < 10; ++i) {
        if (inventory.cases[i] != -1)
            draw_one_sprite(begin, spritesheet[i].sprite,
            spritesheet[i].rect, spritesheet[i].pos);
    }
}

void draw_all_text(rpg_t *rpg)
{
    float zoom = get_zoom(rpg->begin.view.view);
    sfVector2f pos_l = {rpg->begin.view.center.x - ((WIDTH / 2) * zoom) + (10 * zoom), rpg->begin.view.center.y + ((HEIGHT / 2) * zoom) - (40 * zoom)};
    sfVector2f pos = {pos_l.x + (70 * zoom), pos_l.y};
    sfVector2f scale = {0.3 * zoom, 0.3 * zoom};

    send_chat_bubble_soldiers(rpg);
    if (get_clock_time(rpg->begin.fps_disp.display_clock) >= SECOND_TO_MICRO(0.2)) {
        sfText_setString(rpg->begin.fps_disp.fps_text, my_itoa(rpg->begin.fps_disp.fps));
        sfClock_restart(rpg->begin.fps_disp.display_clock);
    }
    sfText_setPosition(rpg->begin.fps_disp.fps_text, pos);
    sfText_setScale(rpg->begin.fps_disp.fps_text, scale);
    sfText_setPosition(rpg->begin.fps_disp.legende, pos_l);
    sfText_setScale(rpg->begin.fps_disp.legende, scale);
    write_text(rpg->begin.window, rpg->begin.fps_disp.fps_text);
    write_text(rpg->begin.window, rpg->begin.fps_disp.legende);
}

// void display_rect_sprite(rpg_t *rpg, sfFloatRect rect)
// {
//     sfRectangleShape *sh = sfRectangleShape_create();
//     sfColor c = {255, 0, 0, 100};

//     sfRectangleShape_setPosition(sh, (sfVector2f){rect.left, rect.top});
//     sfRectangleShape_setSize(sh, (sfVector2f){rect.width, rect.height});
//     sfRectangleShape_setFillColor(sh, c);
//     sfRenderWindow_drawRectangleShape(rpg->begin.window, sh, NULL);
//     sfRectangleShape_destroy(sh);
// }

void draw_all(rpg_t *rpg)
{
    sfSprite_setTexture(rpg->begin.sprite, rpg->begin.texture, sfFalse);
    sfTexture_updateFromPixels(rpg->begin.texture,
    rpg->begin.framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(rpg->begin.window,
    rpg->begin.sprite, NULL);
    draw_spritesheets(&rpg->begin, rpg->spritesheet);
    draw_all_text(rpg);
    if (rpg->screen[SC_INVENTORY].active)
        draw_inventory(rpg->player_stats.inventory,
        &rpg->begin, rpg->spritesheet);
    if (rpg->spritesheet[SP_CURSOR].active)
        draw_one_sprite(&rpg->begin, rpg->spritesheet[SP_CURSOR].sprite,
        rpg->spritesheet[SP_CURSOR].rect, rpg->spritesheet[SP_CURSOR].pos);
    // sfFloatRect exe = sfSprite_getGlobalBounds(rpg->spritesheet[SP_BOSS_EXECUTIONER].sprite);

    // exe.left += 50;
    // exe.width -= 50;
    // display_rect_sprite(rpg, exe);
    sfRenderWindow_display(rpg->begin.window);
}
