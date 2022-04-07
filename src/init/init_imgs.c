/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** init_imgs.c
*/

#include "../../include/rpg.h"

void init_imgs(rpg_t *rpg)
{
    rpg->imgs_colors.main_map =
    sfImage_createFromFile("assets/img/main_map_colors.png");
    rpg->imgs_colors.backgrounds =
    sfImage_createFromFile("assets/img/house/all_backgrounds_colors.png");
}
