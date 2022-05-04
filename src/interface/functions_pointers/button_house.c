/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button_house.c
*/

#include "../../../include/rpg.h"

void open_big_maps(rpg_t *rpg)
{
    if (!rpg->spritesheet[SP_MINIMAP_TAVERNE].active)
        rpg->spritesheet[SP_MINIMAP_TAVERNE].active = true;
    else
        rpg->spritesheet[SP_MINIMAP_TAVERNE].active = false;
}

void button_bed_saving(rpg_t *rpg)
{
    if (!rpg->spritesheet[SP_BED_SLEEP].rect.left) {
        rpg->spritesheet[SP_BED_SLEEP].rect.left +=
        rpg->spritesheet[SP_BED_SLEEP].rect.width;
        rpg->spritesheet[rpg->player_stats.skin].active = false;
        rpg->spritesheet[SP_BED_SLEEP].c_anim = sfClock_create();
        draw_all(rpg);
        save_file("save", rpg);
        while (get_clock_time(rpg->spritesheet[SP_BED_SLEEP].c_anim)
        <= SECOND_TO_MICRO(5));
    } else {
        rpg->spritesheet[SP_BED_SLEEP].rect.left -=
        rpg->spritesheet[SP_BED_SLEEP].rect.width;
        rpg->spritesheet[rpg->player_stats.skin].active = true;
    }
}
