/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** utils.c
*/

#include "../../include/rpg.h"

void remove_life_player(rpg_t *rpg, int offset)
{
    rpg->player_stats.life -= offset;
    sfClock_restart(rpg->player_stats.last_damage);
}

sfBool check_collision_executioner(rpg_t *rpg)
{
    sfFloatRect player =
    sfSprite_getGlobalBounds(rpg->spritesheet[rpg->player_stats.skin].sprite);
    sfFloatRect executioner =
    sfSprite_getGlobalBounds(rpg->spritesheet[SP_BOSS_EXECUTIONER].sprite);

    executioner.left += 40;
    executioner.width -= 40;
    return (sfFloatRect_intersects(&player, &executioner, NULL));
}

sfBool check_collision_golem_proj(rpg_t *rpg)
{
    sfFloatRect player =
    sfSprite_getGlobalBounds(rpg->spritesheet[rpg->player_stats.skin].sprite);
    sfFloatRect executioner =
    sfSprite_getGlobalBounds(rpg->spritesheet[SP_BOSS_GOLEM_PROJ].sprite);

    executioner.left += 40;
    executioner.width -= 40;
    return (sfFloatRect_intersects(&player, &executioner, NULL));
}
