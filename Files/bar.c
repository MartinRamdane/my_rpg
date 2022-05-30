/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include "../Includes/my.h"

int up_stamina(el *bar_stamina, player *my_player, sfClock *clock, int *up)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.01) {
        if (bar_stamina -> rect.width != 400) {
            bar_stamina -> rect.width += 4;
            my_player -> endurance += 1;
        }
        sfClock_restart(clock);
    }
    if (bar_stamina -> rect.width == 400)
        *up = 0;
    if (*up == 1)
        return 0;
    return 1;
}
