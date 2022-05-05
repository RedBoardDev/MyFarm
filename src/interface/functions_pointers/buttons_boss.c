/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** buttons_boss.c
*/

#include "../../../include/rpg.h"

void button_next_grotte(rpg_t *rpg)
{
    return_home(rpg);
    send_notif(rpg, "Bring the potato back");
}
