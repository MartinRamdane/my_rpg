/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include "../Includes/my.h"

void move_player(el *player, sfClock *clock, float scds)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.07) {
        if (player -> rect.left == 48)
            player -> rect.left = 0;
        else
            player -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_pnj(el *player, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.08) {
        if (player -> rect.left == 48)
            player -> rect.left = 0;
        else
            player -> rect.left += 16;
        sfClock_restart(clock);
    }
}


void attack_player(el *player, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (player -> rect.left == 16)
            player -> rect.left = 0;
        else
            player -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_blob(el *player, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.08) {
        if (player -> rect.left == 64)
            player -> rect.left = 0;
        else
            player -> rect.left += 16;
        sfClock_restart(clock);
    }
}
