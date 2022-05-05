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
    rpg->quest[QUEST_SOLDIER].step = 0;
    rpg->quest[QUEST_SOLDIER].active = 0;
    rpg->quest[QUEST_SOLDIER].dialog =
    create_text((init_text_t){30, "\0", sfBlack,
    {92, 210}, "assets/fonts/NotoSerif-Regular.ttf"});
    rpg->quest[QUEST_SELLER].step = 0;
    rpg->quest[QUEST_SELLER].active = 0;
    rpg->quest[QUEST_SELLER].dialog =
    create_text((init_text_t){30, "\0", sfBlack,
    {990, 20}, "assets/fonts/NotoSerif-Regular.ttf"});
    rpg->quest[QUEST_GUIDE].step = 0;
    rpg->quest[QUEST_GUIDE].active = 0;
    rpg->quest[QUEST_GUIDE].dialog =
    create_text((init_text_t){30, "\0", sfBlack,
    {860, 945}, "assets/fonts/NotoSerif-Regular.ttf"});
    set_one_sprite("assets/img/bubble_chat.png",
    &rpg->quest[QUEST_SOLDIER].bubulle, (init_sprite_t){{120, 230},
    {0.08, 0.08}, {0, 0, 798, 652}, false, false, false});
    set_one_sprite("assets/img/bubble_chat.png",
    &rpg->quest[QUEST_GUIDE].bubulle, (init_sprite_t){{885, 965},
    {0.08, 0.08}, {0, 0, 798, 652}, false, false, false});
    set_one_sprite("assets/img/bubble_chat.png",
    &rpg->quest[QUEST_SELLER].bubulle, (init_sprite_t){{1015, 35},
    {0.08, 0.08}, {0, 0, 798, 652}, false, false, false});
    rpg->quest[QUEST_SOLDIER].speaker = -1;
    rpg->quest[QUEST_SELLER].speaker = -1;
    rpg->quest[QUEST_GUIDE].speaker = -1;
}
