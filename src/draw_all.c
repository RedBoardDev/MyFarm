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
spritesheet_t *spritesheet, rpg_t *rpg)
{
    int enum_sprite_place = 0;

    write_text(begin->window, inventory.money);
    for (int i = 0; i < 12; ++i) {
        enum_sprite_place = inventory.inventory_case[i].item_spritesheet;
        if (enum_sprite_place >= SP_ITEM_SHOVEL
        && enum_sprite_place <= SP_ITEM_BEETS) {
            spritesheet[enum_sprite_place].active = true;
            spritesheet[enum_sprite_place].pos = (i == 11 ? rpg->all_events.mouse.pos_view : inventory.inventory_case[i].pos);
        }
    }
}

void draw_all_text(rpg_t *rpg)
{
    send_chat_bubble_soldiers(rpg);
    send_chat_bubble_seller(rpg);
    if (rpg->screen[SC_OPTION].active)
        draw_text_fps_settings(rpg);
    if (rpg->params.show_fps)
        draw_fps(rpg);
}

void draw_all(rpg_t *rpg)
{
    sfSprite_setTexture(rpg->begin.sprite, rpg->begin.texture, sfFalse);
    sfTexture_updateFromPixels(rpg->begin.texture,
    rpg->begin.framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(rpg->begin.window,
    rpg->begin.sprite, NULL);
    for (int i = SP_ITEM_SHOVEL; i <= SP_ITEM_BEETS; ++i)
        rpg->spritesheet[i].active = false;
    if (rpg->screen[SC_INVENTORY].active)
        draw_inventory(rpg->player_stats.inventory,
        &rpg->begin, rpg->spritesheet, rpg);
    draw_spritesheets(&rpg->begin, rpg->spritesheet);
    draw_all_text(rpg);
    if (rpg->spritesheet[SP_CURSOR].active)
        draw_one_sprite(&rpg->begin, rpg->spritesheet[SP_CURSOR].sprite,
        rpg->spritesheet[SP_CURSOR].rect, rpg->spritesheet[SP_CURSOR].pos);
    sfRenderWindow_display(rpg->begin.window);
    // printf("%f - %f\n", rpg->spritesheet[SP_CURSOR].pos.x, rpg->spritesheet[SP_CURSOR].pos.y);
}
