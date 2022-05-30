/*
** EPITECH PROJECT, 2022
** colisions
** File description:
** colisions
*/

#include "../Includes/my.h"

void print_liste_colisions(sfRenderWindow *window, liste_colisions *liste)
{
    liste_colisions *tmp = malloc(sizeof(liste_colisions));
    tmp = liste;
    while (liste != NULL) {
        print_sprite(window, liste -> element);
        liste = liste -> next;
    }
    liste = tmp;
}

int ad_colisions_enemy(el *sorcier, liste_colisions *liste, el player)
{
    while (liste != NULL) {
        sfFloatRect bounds = sfSprite_getGlobalBounds(liste -> element.sprite);
        if (sfFloatRect_contains(&bounds, sorcier->pos.x + 4, sorcier->pos.y)) {
            if (player.pos.x < sorcier->pos.x)
                return 0;
            else
                return 1;
        } if (sfFloatRect_contains(&bounds, sorcier->pos.x - 4, sorcier->pos.y)) {
            if (player.pos.x > sorcier->pos.x)
                return 0;
            else
                return 1;
        } if (sfFloatRect_contains(&bounds, sorcier->pos.x, sorcier->pos.y + 8)) {
            if (player.pos.y < sorcier->pos.y)
                return 0;
            else
                return 1;
        } if (sfFloatRect_contains(&bounds, sorcier->pos.x, sorcier->pos.y - 8)) {
            if (player.pos.y > sorcier->pos.y)
                return 0;
            else
                return 1;
        }
        liste = liste->next;
    }
    return 0;
}