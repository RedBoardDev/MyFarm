/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** collisions_npc.c
*/

#include "../../include/rpg.h"

sfBool check_collision_npc(rpg_t *rpg, int enum_npc,
sfFloatRect offset_collision)
{
    sfFloatRect player =
    sfSprite_getGlobalBounds(rpg->spritesheet[rpg->player_stats.skin].sprite);
    sfFloatRect npc =
    sfSprite_getGlobalBounds(rpg->spritesheet[enum_npc].sprite);

    npc.left += offset_collision.left;
    npc.top += offset_collision.top;
    npc.height += offset_collision.height;
    npc.width += offset_collision.width;
    return (sfFloatRect_intersects(&player, &npc, NULL));
}
