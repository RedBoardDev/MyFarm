/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button_house.c
*/

#include "../../../include/rpg.h"

void open_big_maps(rpg_t *rpg)
{
    if (!rpg->spritesheet[SP_MINIMAP].active)
        rpg->spritesheet[SP_MINIMAP].active = true;
    else
        rpg->spritesheet[SP_MINIMAP].active = false;
}

void button_bed_saving(rpg_t *rpg)
{
    if (!rpg->spritesheet[SP_BED_SLEEP].rect.left) {
        rpg->spritesheet[SP_BED_SLEEP].rect.left +=
        rpg->spritesheet[SP_BED_SLEEP].rect.width;
        rpg->spritesheet[rpg->player_stats.skin].active = false;
    } else {
        rpg->spritesheet[SP_BED_SLEEP].rect.left -=
        rpg->spritesheet[SP_BED_SLEEP].rect.width;
        rpg->spritesheet[rpg->player_stats.skin].active = true;
    }
}
