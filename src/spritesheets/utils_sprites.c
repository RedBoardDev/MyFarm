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

void toggle_spritesheet_scene(rpg_t *rpg, bool status, int *screen_i,
int scene)
{
    if (!status) {
        rpg->old_screen = screen_i;
        rpg->index_old_s = scene;
    }
    if (scene != -1)
        rpg->screen[scene].active = status;
    for (int i = 0; screen_i[i] != -1; ++i)
        if (screen_i[i] == SELECTED_PLAYER)
            rpg->spritesheet[rpg->player_stats.skin].active = status;
        else if (screen_i[i] == CURSOR)
            toggle_cursor(rpg->begin.window, status);
        else {
            printf("screen I %i\n", screen_i[i]);
            rpg->spritesheet[screen_i[i]].active = status;
        }
}
