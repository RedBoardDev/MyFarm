/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** gui_shop.c
*/

#include "../../../include/rpg.h"

void put_shop_gui(rpg_t *rpg)
{
    if (!rpg->spritesheet[SP_GUI_SHOP].active) {
        rpg->spritesheet[SP_GUI_SHOP].active = true;
        rpg->spritesheet[SP_SHOP_BUTTON1].active = true;
        rpg->spritesheet[SP_SHOP_BUTTON2].active = true;
        rpg->spritesheet[SP_SHOP_BUTTON3].active = true;
        rpg->spritesheet[SP_SHOP_BUTTON4].active = true;
    } else {
        rpg->spritesheet[SP_GUI_SHOP].active = false;
        rpg->spritesheet[SP_SHOP_BUTTON1].active = false;
        rpg->spritesheet[SP_SHOP_BUTTON2].active = false;
        rpg->spritesheet[SP_SHOP_BUTTON3].active = false;
        rpg->spritesheet[SP_SHOP_BUTTON4].active = false;
    }
}

void shop_button1(rpg_t *rpg) //life
{
    printf("button1 %d\n", rpg->player_stats.money);
    if (check_if_in_inventory(rpg, SP_ITEM_BEETS) != -1
    && remove_money(rpg, 20) != 84) {
        remove_item_inventory(rpg, SP_ITEM_BEETS);
        add_item_inventory(rpg, SP_FLASK_LIFE);
    }
}

void shop_button2(rpg_t *rpg) //speed
{
    printf("button2 %d\n", rpg->player_stats.money);
    if (remove_money(rpg, 30) != 84)
        add_item_inventory(rpg, SP_FLASK_SPEED);
}

void shop_button3(rpg_t *rpg) //attack
{
    printf("button3 %d\n", rpg->player_stats.money);
    if (remove_money(rpg, 30) != 84)
        add_item_inventory(rpg, SP_FLASK_ATTACK);
}

void shop_button4(rpg_t *rpg) //drunk
{
    printf("button4 %d\n", rpg->player_stats.money);
    if (remove_money(rpg, 30) != 84)
        add_item_inventory(rpg, SP_FLASK_DRUNK);
}
