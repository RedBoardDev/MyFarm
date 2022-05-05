/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** draw_all.c
*/

#include "../include/rpg.h"

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

void draw_inventory(inventory_t inventory,
spritesheet_t *spritesheet, rpg_t *rpg)
{
    int enum_sprite_place = 0;

    for (int i = SP_ITEM_SHOVEL; i <= SP_FLASK_DRUNK; ++i)
        rpg->spritesheet[i].active = false;
    for (int i = 0; i < 12; ++i) {
        enum_sprite_place = inventory.inventory_case[i].item_spritesheet;
        if (enum_sprite_place >= SP_ITEM_SHOVEL
        && enum_sprite_place <= SP_FLASK_DRUNK) {
            spritesheet[enum_sprite_place].active = true;
            sfSprite_setRotation(spritesheet[enum_sprite_place].sprite, 0);
            spritesheet[enum_sprite_place].pos = (i == 11 ?
            rpg->all_events.mouse.pos_view : inventory.inventory_case[i].pos);
        }
    }
}

void draw_all_text(rpg_t *rpg)
{
    send_chat_bubble(rpg, "assets/quest_dialog/soldiers.txt", QUEST_SOLDIER);
    send_chat_bubble(rpg, "assets/quest_dialog/seller.txt", QUEST_SELLER);
    send_chat_bubble(rpg, "assets/quest_dialog/guide.txt", QUEST_GUIDE);
    if (rpg->screen[SC_OPTION].active)
        draw_text_fps_settings(rpg);
    if (rpg->params.show_fps)
        draw_fps(rpg);
    if (rpg->screen[SC_INVENTORY].active) {
        write_text(rpg->begin.window, rpg->player_stats.inventory.money);
        draw_quests_inventory(rpg);
    }
    draw_text_notif(rpg);
}

void draw_main_item(rpg_t *rpg)
{
    int item_nb = get_item_inv(rpg, I_ATTACK);
    sfVector2f pos_main_item = rpg->spritesheet[rpg->player_stats.skin].pos;
    sfVector2f scale_item;
    sfVector2f scale_item2;

    if (item_nb != -1 && !rpg->player_stats.attack) {
        scale_item = sfSprite_getScale(rpg->spritesheet[item_nb].sprite);
        scale_item2 = sfSprite_getScale(rpg->spritesheet[item_nb].sprite);
        scale_item.x /= 2;
        scale_item.y /= 2;
        pos_main_item.x -= 20;
        pos_main_item.y += 5;
        sfSprite_setScale(rpg->spritesheet[item_nb].sprite, scale_item);
        draw_one_sprite(&rpg->begin, rpg->spritesheet[item_nb].sprite,
        rpg->spritesheet[item_nb].rect, pos_main_item);
        sfSprite_setScale(rpg->spritesheet[item_nb].sprite, scale_item2);
    }
}

void draw_all(rpg_t *rpg)
{
    sfSprite_setTexture(rpg->begin.sprite, rpg->begin.texture, sfFalse);
    sfTexture_updateFromPixels(rpg->begin.texture,
    rpg->begin.framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(rpg->begin.window,
    rpg->begin.sprite, NULL);
    if (rpg->screen[SC_INVENTORY].active)
        draw_inventory(rpg->player_stats.inventory, rpg->spritesheet, rpg);
    if (rpg->screen[SC_MAIN_MAP].active && !rpg->screen[SC_INVENTORY].active
    && check_if_in_inventory(rpg, SP_ITEM_PRISONER_PEE) == -1)
        rpg->spritesheet[SP_ITEM_PRISONER_PEE].active = true;
    else if (!rpg->screen[SC_INVENTORY].active)
        rpg->spritesheet[SP_ITEM_PRISONER_PEE].active = false;
    rpg->spritesheet[SP_MINIMAP].active = ((rpg->screen[SC_MAIN_MAP].active &&
    rpg->params.dark_mode) ? true : false);
    rpg->spritesheet[SP_MINIMAP_LAYER].active =
    rpg->spritesheet[SP_MINIMAP].active;
    draw_spritesheets(&rpg->begin, rpg->spritesheet);
    if (!rpg->screen[SC_INVENTORY].active)
        draw_main_item(rpg);
    draw_all_text(rpg);
    if (rpg->spritesheet[SP_CURSOR].active)
        draw_one_sprite(&rpg->begin, rpg->spritesheet[SP_CURSOR].sprite,
        rpg->spritesheet[SP_CURSOR].rect, rpg->spritesheet[SP_CURSOR].pos);
    sfRenderWindow_display(rpg->begin.window);
}
