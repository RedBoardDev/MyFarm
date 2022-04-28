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
    rpg->quest[QUEST_SOLDIER] = (quest_t) {.step = 0};
    rpg->quest[QUEST_SOLDIER].dialog =
    create_text((init_text_t){30, "\0", sfBlack,
    {825, 765}, "assets/fonts/NotoSerif-Regular.ttf"});
    rpg->quest[QUEST_SELLER] = (quest_t) {.step = 0};
    rpg->quest[QUEST_SELLER].dialog =
    create_text((init_text_t){30, "\0", sfBlack,
    {825, 765}, "assets/fonts/NotoSerif-Regular.ttf"});
}
