/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** q_soldiers.c
*/

#include "../../../include/rpg.h"

sfBool check_collision_npc(rpg_t *rpg)
{
    sfFloatRect player = sfSprite_getGlobalBounds(rpg->spritesheet[rpg->player_stats.skin].sprite);
    sfFloatRect npc = sfSprite_getGlobalBounds(rpg->spritesheet[SP_NPC_SOLDIER].sprite);

    npc.left += 30;
    npc.width += 30;
    return (sfFloatRect_intersects(&player, &npc, NULL));
}

void quest_soldiers(rpg_t *rpg)
{
    if (check_collision_npc(rpg))
        printf("True");
}
