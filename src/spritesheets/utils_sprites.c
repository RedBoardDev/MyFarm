/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** utils_sprites.c
*/

#include "../../include/rpg.h"

void set_one_sprite(char *filename, spritesheet_t *spritesheet,
init_sprite_t init_sprite)
{
    spritesheet->active = init_sprite.active;
    spritesheet->clickable = init_sprite.clickable;
    spritesheet->change_sprite_on_mouse = init_sprite.change_sprite_on_mouse;
    spritesheet->pos = init_sprite.pos;
    spritesheet->rect = init_sprite.rect;
    spritesheet->sprite = sfSprite_create();
    spritesheet->texture = sfTexture_createFromFile(filename, NULL);
    spritesheet->c_anim = sfClock_create();
    spritesheet->c_attack = sfClock_create();
    sfSprite_setScale(spritesheet->sprite, init_sprite.scale);
    sfSprite_setTexture(spritesheet->sprite, spritesheet->texture, sfFalse);
    sfSprite_setTextureRect(spritesheet->sprite, spritesheet->rect);
    sfSprite_setPosition(spritesheet->sprite, spritesheet->pos);
    sfSprite_setOrigin(spritesheet->sprite, (sfVector2f){init_sprite.rect.width
    / 2, init_sprite.rect.height / 2});
}

void draw_one_sprite(beginning_t *begin, sfSprite *sprite, sfIntRect rect,
sfVector2f pos)
{
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setPosition(sprite, pos);
    sfRenderWindow_drawSprite(begin->window, sprite, NULL);
}

void toggle_spritesheet_scene(rpg_t *rpg, bool status, int scene_enum)
{
    if (!status) {
        rpg->index_old_s = scene_enum;
    } else if (scene_enum != -1)
        set_zoom(rpg->begin.view.view, rpg->screen[scene_enum].view_zoom);
    if (scene_enum != -1)
        rpg->screen[scene_enum].active = status;
    for (int i = 0; rpg->screen[scene_enum].const_screen[i] != -1; ++i) {
        if (rpg->screen[scene_enum].const_screen[i] == SELECTED_PLAYER)
            rpg->spritesheet[rpg->player_stats.skin].active = status;
        else if (rpg->screen[scene_enum].const_screen[i] == CURSOR) {
            toggle_cursor(rpg->begin.window, status);
        } else
            rpg->spritesheet[rpg->screen[scene_enum].const_screen[i]].active =
            status;
    }
}

void disable_all_screens_gameplay(rpg_t *rpg)
{
    int current = get_current_screen(rpg);

    toggle_spritesheet_scene(rpg, false, SC_BASE);
    toggle_spritesheet_scene(rpg, false, SC_MAIN_MAP);
    toggle_spritesheet_scene(rpg, false, SC_GROTTE);
    toggle_spritesheet_scene(rpg, false, SC_INVENTORY);
    toggle_spritesheet_scene(rpg, false, SC_VICTORY_CEMETERY);
    toggle_spritesheet_scene(rpg, false, SC_PAUSE);
    if (current != -1)
        toggle_spritesheet_scene(rpg, false, current);
}

void draw_spritesheets(beginning_t *begin, spritesheet_t *spritesheet)
{
    sfVector2i po = sfMouse_getPositionRenderWindow(begin->window);
    spritesheet[SP_CURSOR].pos =
    sfRenderWindow_mapPixelToCoords(begin->window, po, begin->view.view);
    for (int i = 0; i < NBR_SP - 1; ++i)
        if (spritesheet[i].active)
            draw_one_sprite(begin, spritesheet[i].sprite, spritesheet[i].rect,
            spritesheet[i].pos);
}
