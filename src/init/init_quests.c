/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_quests.c
*/

#include "../../include/rpg.h"

void init_quests(rpg_t *rpg)
{
    rpg->quest = malloc(sizeof(quest_t) * NBR_QUEST);
    rpg->quest[QUEST_SOLDIER] = (quest_t) {.step = 0, .finished = false};
    rpg->quest[QUEST_SOLDIER].npc =
    create_text((init_text_t){30,"\0", sfBlack,
    {855, 785}, "assets/fonts/NotoSerif-Regular.ttf"});
    rpg->quest[QUEST_SOLDIER].player =
    create_text((init_text_t){30,"\0", sfBlack,
    {800, 800}, "assets/fonts/NotoSerif-Regular.ttf"});
}
