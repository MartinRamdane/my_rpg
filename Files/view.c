/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** find dtr
*/

#include "../Includes/my.h"

int check_colisions(liste_colisions *liste, el *player)
{
    liste_colisions *tmp = malloc(sizeof(liste_colisions));
    tmp = liste;
    while (liste != NULL) {
        sfFloatRect bounds = sfSprite_getGlobalBounds(liste -> element.sprite);
        if (player -> dir == UP && sfFloatRect_contains(&bounds, player -> pos.x, player -> pos.y - 4)) {
            liste = tmp;
            return UP;
        }
        if (player -> dir == DOWN && sfFloatRect_contains(&bounds, player -> pos.x, player -> pos.y + 8)) {
            liste = tmp;
            return DOWN;
        }
        if (player -> dir == RIGHT && sfFloatRect_contains(&bounds, player -> pos.x + 4, player -> pos.y)) {
            liste = tmp;
            return RIGHT;
        }
        if (player -> dir == LEFT && sfFloatRect_contains(&bounds, player -> pos.x - 4, player -> pos.y)) {
            liste = tmp;
            return LEFT;
        }
        if (sfFloatRect_contains(&bounds, player -> pos.x, player -> pos.y - 4) && sfFloatRect_contains(&bounds, player -> pos.x + 4, player -> pos.y)) {
            liste = tmp; return player -> dir;
        }
        liste = liste -> next;
    }
    liste = tmp;
    return 20;
}

int move_view2(sfView *mini_map, sfView *view, player *my_player, c *clocks, int speed, float scds, liste_colisions * liste, int colision, infogame *gameinfos, el *smoke)
{
    if (sfKeyboard_isKeyPressed(gameinfos -> move_back) == sfTrue && my_player -> my_sprite->pos.y < 1000 && colision != DOWN) {
        if (speed >= 3 && my_player -> endurance > 0)
            my_player -> endurance -= 1;
        sfVector2f test = {0, speed}; my_player -> my_sprite->pos.y += speed;
        sfVector2f pos_d = {my_player -> my_sprite->pos.x - 4, my_player -> my_sprite->pos.y - 18};
        if (my_player -> my_sprite->pos.y <= 963)
            sfView_move(view, test);
        if (my_player -> my_sprite->pos.y <= 821) {
            sfView_move(mini_map, test);
        }
        my_player -> my_sprite->dir = DOWN;
        my_player -> my_sprite->texture = sfTexture_createFromFile("Pictures/walk_d.png", NULL);
        move_player(my_player -> my_sprite, clocks->clock1, scds);
        if (speed >= 3)
            return 2;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(gameinfos -> move_rigth) == sfTrue && my_player -> my_sprite->pos.x <= 1900 && colision != RIGHT) {
        if (speed >= 3 && my_player -> endurance > 0)
            my_player -> endurance -= 1;
        sfVector2f test = {speed, 0}; my_player -> my_sprite->pos.x += speed;
        sfVector2f pos_r = {my_player -> my_sprite->pos.x - 14, my_player -> my_sprite->pos.y + 3};
        smoke -> texture = sfTexture_createFromFile("Pictures/smoke_run_r .png", NULL);
        move_smoke_r(smoke, clocks->clock19, 100);
        smoke->pos = pos_r;
        smoke->pos.x += speed;
        if (my_player -> my_sprite->pos.x > 195 && my_player -> my_sprite->pos.x <= 1728) {
            sfView_move(view, test);
        }
         if (my_player -> my_sprite->pos.x > 465 && my_player -> my_sprite->pos.x <= 1441) {
            sfView_move(mini_map, test);
        };
        my_player -> my_sprite->texture = sfTexture_createFromFile("Pictures/walk_r.png", NULL);
        move_player(my_player -> my_sprite, clocks->clock1, scds); my_player -> my_sprite->dir = RIGHT;
        if (speed >= 3)
            return 2;
        return 1;
    }
    return 0;
}

int move_view(sfView *mini_map, sfView *view, player *my_player, c *clocks, liste_colisions *liste, infogame *gameinfos, int if_stamina, el *smoke)
{
    int colision = check_colisions(liste, my_player -> my_sprite);
    int speed = 2; float scds = 0.07;
    if (sfKeyboard_isKeyPressed(gameinfos -> sprint) && my_player -> endurance > 0 && if_stamina == 1) {
        if (my_player->boots == 1) {
            speed = 4; scds = 0.1;
        } else {
            speed = 3; scds = 0.1;
        }
    }
    if (sfKeyboard_isKeyPressed(gameinfos -> move_foreward) == sfTrue && my_player -> my_sprite->pos.y >= 224 && colision != UP) {
        if (speed >= 3 && my_player -> endurance > 0)
            my_player -> endurance -= 1;
        sfVector2f test = {0, - speed}; my_player -> my_sprite->pos.y -= speed;
        sfVector2f pos_u = {my_player -> my_sprite->pos.x - 3, my_player -> my_sprite->pos.y + 11};
        smoke -> pos = pos_u;
        smoke -> texture = sfTexture_createFromFile("Pictures/smoke_run_u.png", NULL);
        move_smoke_u(smoke, clocks->clock19, 100);
        smoke -> pos.y -= speed;
        if (my_player -> my_sprite->pos.y <= 966) {
            sfView_move(view, test);
        }
        if (my_player -> my_sprite->pos.y > 247 && my_player -> my_sprite->pos.y <= 822) {
            sfView_move(mini_map, test);
        }
        my_player -> my_sprite->dir = UP;
        my_player -> my_sprite->texture = sfTexture_createFromFile("Pictures/walk_u.png", NULL);
        move_player(my_player -> my_sprite, clocks->clock1, scds);
        if (speed >= 3)
            return 2;
        return 1;
    }
    if (sfKeyboard_isKeyPressed(gameinfos -> move_left) == sfTrue && my_player -> my_sprite->pos.x > 20 && colision != LEFT) {
        if (speed >= 3 && my_player -> endurance > 0)
            my_player -> endurance -= 1;
        sfVector2f test = {- speed, 0}; my_player -> my_sprite->pos.x -= speed;
        sfVector2f pos_l = {my_player -> my_sprite->pos.x + 7, my_player -> my_sprite->pos.y + 3};
        smoke -> texture = sfTexture_createFromFile("Pictures/smoke_run_l.png", NULL);
        smoke->pos = pos_l;
        move_smoke(smoke, clocks->clock10, 100);
        smoke->pos.x -= speed;
        if (my_player -> my_sprite->pos.x > 193 && my_player -> my_sprite->pos.x <= 1728) {
            sfView_move(view, test);
        }
         if (my_player -> my_sprite->pos.x > 461 && my_player -> my_sprite->pos.x <= 1441) {
            sfView_move(mini_map, test);
        }
        my_player -> my_sprite->texture = sfTexture_createFromFile("Pictures/walk_l.png", NULL);
        move_player(my_player -> my_sprite, clocks->clock1, scds); my_player -> my_sprite->dir = LEFT;
        if (speed >= 3)
            return 2;
        return 1;
    }
    return move_view2(mini_map, view, my_player, clocks, speed, scds, liste, colision, gameinfos, smoke);
}
