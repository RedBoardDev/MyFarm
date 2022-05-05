/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** collisions.c
*/

#include "../../include/rpg.h"

sfBool check_collision_executioner(rpg_t *rpg)
{
    sfFloatRect player =
    sfSprite_getGlobalBounds(rpg->spritesheet[rpg->player_stats.skin].sprite);
    sfFloatRect executioner =
    sfSprite_getGlobalBounds(rpg->spritesheet[SP_BOSS_EXECUTIONER].sprite);

    executioner.left += 50;
    executioner.top += 30;
    executioner.height -= 50;
    executioner.width -= 100;
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
    sfFloatRect hoe;
    int item = get_item_inv(rpg, I_ATTACK);

    if (item == -1)
        return (sfFalse);
    hoe = sfSprite_getGlobalBounds(
    rpg->spritesheet[item].sprite);
    golem.left += 40;
    golem.top += 30;
    golem.height -= 90;
    golem.width -= 80;
    return (sfFloatRect_intersects(&golem, &hoe, NULL));
}
