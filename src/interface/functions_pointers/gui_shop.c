/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** gui_shop.c
*/

#include "../../../include/rpg.h"

void put_shop_gui(rpg_t *rpg)
{
    if (rpg->quest[QUEST_SELLER].active == -1) {
        if (!rpg->screen[SC_GUI_SHOP].active) {
            toggle_spritesheet_scene(rpg, true, SC_GUI_SHOP);
        } else if (rpg->screen[SC_GUI_SHOP].active) {
            toggle_spritesheet_scene(rpg, false, SC_GUI_SHOP);
            rpg->spritesheet[SP_CURSOR].active = true;
        }
    }
}

void shop_button1(rpg_t *rpg)
{
    if (remove_money(rpg, 30) != 84)
        add_item_inventory(rpg, SP_ITEM_ARMOR);
}

void shop_button2(rpg_t *rpg)
{
    if (remove_money(rpg, 20) != 84)
        add_item_inventory(rpg, SP_FLASK_SPEED);
}

void shop_button3(rpg_t *rpg)
{
    if (remove_money(rpg, 30) != 84)
        add_item_inventory(rpg, SP_FLASK_ATTACK);
}

void shop_button4(rpg_t *rpg)
{
    if (remove_money(rpg, 30) != 84)
        add_item_inventory(rpg, SP_FLASK_DRUNK);
}
