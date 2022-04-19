/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** utils_quest.c
*/

#include "../../../include/rpg.h"

sfBool check_collision_npc(rpg_t *rpg)
{
    sfFloatRect player =
    sfSprite_getGlobalBounds(rpg->spritesheet[rpg->player_stats.skin].sprite);
    sfFloatRect npc =
    sfSprite_getGlobalBounds(rpg->spritesheet[SP_NPC_SOLDIER].sprite);

    npc.left += 15;
    npc.width += 15;
    npc.height += 15;
    npc.top += 15;
    return (sfFloatRect_intersects(&player, &npc, NULL));
}

void disable_quests(rpg_t *rpg, int quests_enum, bool scale)
{
    rpg->quest[quests_enum].step = -1;
    rpg->spritesheet[SP_BUBBLE_CHAT].active = false;
    if (scale)
        sfSprite_scale(rpg->spritesheet[SP_BUBBLE_CHAT].sprite,
        (sfVector2f){-1.f, 1.f});
}
