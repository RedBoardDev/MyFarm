/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** utils_quest.c
*/

#include "../../../include/rpg.h"

void disable_quests(rpg_t *rpg, int quests_enum, bool scale)
{
    rpg->quest[quests_enum].step = -1;
    rpg->spritesheet[SP_BUBBLE_CHAT].active = false;
    if (scale)
        sfSprite_scale(rpg->spritesheet[SP_BUBBLE_CHAT].sprite,
        (sfVector2f){-1.f, 1.f});
}

// A SUPPRIMER SI PAS USE