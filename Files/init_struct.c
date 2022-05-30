/*
** EPITECH PROJECT, 2021
** init_sruct.c
** File description:
** runner
*/

#include "../Includes/my.h"

el init_element(int posx, int posy, int rect_width, int rect_heigh, char *fil)
{
    el element;
    element.texture = sfTexture_createFromFile(fil, NULL);
    element.sprite = sfSprite_create();
    element.pos.x = posx;
    element.pos.y = posy;
    element.pos_start.x = posx;
    element.pos_start.y = posy;
    element.rect.height = rect_heigh;
    element.rect.left = 0;
    element.rect.width = rect_width;
    element.rect.top = 0;
    element.dir = RIGHT;
    element.quest = 0;
    sfSprite_setPosition(element.sprite, element.pos);
    return element;
}

c init_clocks(void)
{
    c clocks;
    clocks.clock1 = sfClock_create();
    clocks.clock2 = sfClock_create();
    clocks.clock3 = sfClock_create();
    clocks.clock4 = sfClock_create();
    clocks.clock5 = sfClock_create();
    clocks.clock6 = sfClock_create();
    clocks.clock7 = sfClock_create();
    clocks.clock8 = sfClock_create();
    clocks.clock9 = sfClock_create();
    clocks.clock10 = sfClock_create();
    clocks.clock11 = sfClock_create();
    clocks.clock12 = sfClock_create();
    clocks.clock13 = sfClock_create();
    clocks.clock14 = sfClock_create();
    clocks.clock15 = sfClock_create();
    clocks.clock16 = sfClock_create();
    clocks.clock17 = sfClock_create();
    clocks.clock18 = sfClock_create();
    clocks.clock19 = sfClock_create();
    clocks.clock20 = sfClock_create();
    clocks.clock21 = sfClock_create();
    clocks.clock22 = sfClock_create();
    clocks.clock23 = sfClock_create();
    clocks.clock24 = sfClock_create();
    clocks.clock25 = sfClock_create();
    clocks.clock26 = sfClock_create();
    clocks.clock27 = sfClock_create();
    clocks.clock28 = sfClock_create();
    clocks.clock29 = sfClock_create();
    clocks.clock30 = sfClock_create();
    clocks.clock31 = sfClock_create();
    clocks.clock32 = sfClock_create();
    clocks.clock33 = sfClock_create();
    clocks.clock34 = sfClock_create();
    clocks.clock35 = sfClock_create();
    clocks.clock36 = sfClock_create();
    clocks.clock37 = sfClock_create();
    clocks.clock38 = sfClock_create();
    clocks.clock39 = sfClock_create();
    clocks.clock40 = sfClock_create();
    clocks.clock41 = sfClock_create();
    return clocks;
}

sfVector2f init_pos(int x, int y)
{
    sfVector2f pos;
    pos.x = x;
    pos.y = y;
    return (pos);
}