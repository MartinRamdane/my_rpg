/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include "../Includes/my.h"

void do_map(sfRenderWindow *window, el map, el player, int *m, sfEvent event, sfView *view, float *zoom, infogame *gameinfos, el pnj, el pnj2, el pnj3, el dog2)
{
    sfVector2f move = {0, 0};
    if (sfKeyboard_isKeyPressed(sfKeyUp) == sfTrue) {
        *zoom = 0.95;
        sfVector2f vec = sfView_getSize(view);
        if (vec.y > 112.0 && vec.x > 200.0)
            sfView_zoom(view, *zoom);
    }
    if (sfKeyboard_isKeyPressed(sfKeyDown) == sfTrue) {
        *zoom = 1.05;
        sfVector2f vec = sfView_getSize(view);
        if (vec.x < 1860.0 && vec.y < 1020.0) {
            sfView_zoom(view, *zoom);
        }
    }
    if (sfKeyboard_isKeyPressed(gameinfos -> move_foreward) == sfTrue)
        move.y = -5;
    if (sfKeyboard_isKeyPressed(gameinfos -> move_left) == sfTrue)
        move.x = -5;
    if (sfKeyboard_isKeyPressed(gameinfos -> move_back) == sfTrue)
        move.y = 5;
    if (sfKeyboard_isKeyPressed(gameinfos -> move_rigth) == sfTrue)
        move.x = 5;
    sfView_move(view, move);
    sfRenderWindow_clear(window, sfBlack);
    sfRenderWindow_setView(window, view);
    print_sprite(window, map); print_sprite(window, player);
    print_sprite(window, pnj);
    print_sprite(window, pnj2);
    print_sprite(window, pnj3);
    print_sprite(window, dog2);
    if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue)
        *m = 0;
}