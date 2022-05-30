/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include "../Includes/my.h"

void attack(el *player, c *clocks, int if_run, infogame *gameinfos)
{
    if (sfKeyboard_isKeyPressed(gameinfos -> hit) == sfTrue && if_run == 0) {
        if (player -> dir == UP) {
            player -> texture = sfTexture_createFromFile("Pictures/hit_u.png", NULL);
            attack_player(player, clocks -> clock1);
        }
        if (player -> dir == RIGHT && if_run == 0) {
            player -> texture = sfTexture_createFromFile("Pictures/hit_r.png", NULL);
            attack_player(player, clocks -> clock1);
        }
        if (player -> dir == DOWN && if_run == 0) {
            player -> texture = sfTexture_createFromFile("Pictures/hit_d.png", NULL);
            attack_player(player, clocks -> clock1);
        }
        if (player -> dir == LEFT && if_run == 0) {
            player -> texture = sfTexture_createFromFile("Pictures/hit_l.png", NULL);
            attack_player(player, clocks -> clock1);
        }
    }
}

void change_perso(el *player, sfEvent event)
{
    if (event.type == sfEvtKeyReleased) {
        if (player -> dir == UP) {
            player -> texture = sfTexture_createFromFile("Pictures/walk_u.png", NULL);
            player -> rect.left = 0;
        }
        if (player -> dir == RIGHT) {
            player -> texture = sfTexture_createFromFile("Pictures/walk_r.png", NULL);
            player -> rect.left = 0;
        }
        if (player -> dir == DOWN) {
            player -> texture = sfTexture_createFromFile("Pictures/walk_d.png", NULL);
            player -> rect.left = 0;
        }
        if (player -> dir == LEFT) {
            player -> texture = sfTexture_createFromFile("Pictures/walk_l.png", NULL);
            player -> rect.left = 0;
        }
    }
}

