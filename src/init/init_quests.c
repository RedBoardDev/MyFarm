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
    rpg->quest[QUEST_SOLDIER].active = 0;
    rpg->quest[QUEST_SOLDIER].pos_dialog = (sfVector2f){120, 230};
    rpg->quest[QUEST_SOLDIER].scale = (sfVector2f){0.08, 0.08};
    rpg->quest[QUEST_SOLDIER].dialog =
    create_text((init_text_t){30, "\0", sfBlack,
    {92, 210}, "assets/fonts/NotoSerif-Regular.ttf"});
    rpg->quest[QUEST_SELLER] = (quest_t) {.step = 0};
    rpg->quest[QUEST_SELLER].active = 0;
    rpg->quest[QUEST_SELLER].pos_dialog = (sfVector2f){1020, 40};
    rpg->quest[QUEST_SELLER].scale = (sfVector2f){0.08, 0.08};
    rpg->quest[QUEST_SELLER].dialog =
    create_text((init_text_t){30, "\0", sfBlack,
    {1015, 35}, "assets/fonts/NotoSerif-Regular.ttf"});
}
