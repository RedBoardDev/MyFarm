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
    sfFloatRect proj =
    sfSprite_getGlobalBounds(rpg->spritesheet[SP_BOSS_GOLEM_PROJ].sprite);

    proj.left += 10;
    proj.top += 45;
    proj.width -= 110;
    proj.height -= 130;
    return (sfFloatRect_intersects(&player, &proj, NULL));
}

sfBool check_collision_hoe_to_golem(rpg_t *rpg)
{
    sfFloatRect golem =
    sfSprite_getGlobalBounds(rpg->spritesheet[SP_BOSS_GOLEM].sprite);
    sfFloatRect hoe =
    sfSprite_getGlobalBounds(rpg->spritesheet[SP_ITEM_HOE].sprite);

    golem.left += 40;
    golem.top += 30;
    golem.height -= 60;
    golem.width -= 80;
    return (sfFloatRect_intersects(&golem, &hoe, NULL));
}
