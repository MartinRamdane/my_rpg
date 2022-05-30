/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include "../Includes/my.h"

void move_water(el *water, sfClock *clock, int max)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.035) {
        if (water -> rect.left == max)
            water -> rect.left = 0;
        else
            water -> rect.left += 1;
        sfClock_restart(clock);
    }
}

void move_water2(el *water, sfClock *clock, int max)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.035) {
        if (water -> rect.left == max)
            water -> rect.left = 223;
        else
            water -> rect.left -= 1;
        sfClock_restart(clock);
    }
}

void move_cascade(el *cascade, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.035) {
        if (cascade -> rect.top == 0)
            cascade -> rect.top = 128;
        else
            cascade -> rect.top -= 1;
        sfClock_restart(clock);
    }
}

void move_mer(el *cascade, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.035) {
        if (cascade -> rect.top == 64)
            cascade -> rect.top = 0;
        else
            cascade -> rect.top += 1;
        sfClock_restart(clock);
    }
}

void move_torche1(el *torche_1, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (torche_1 -> rect.left == 48)
            torche_1 -> rect.left = 0;
        else
            torche_1 -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_torche11(el *torche_11, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (torche_11 -> rect.left == 48)
            torche_11 -> rect.left = 0;
        else
            torche_11 -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_torche111(el *torche_111, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (torche_111 -> rect.left == 48)
            torche_111 -> rect.left = 0;
        else
            torche_111 -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_torche2(el *torche_2, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (torche_2 -> rect.left == 48)
            torche_2 -> rect.left = 0;
        else
            torche_2 -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_torche22(el *torche_22, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (torche_22 -> rect.left == 48)
            torche_22 -> rect.left = 0;
        else
            torche_22 -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_torche3(el *torche_3, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (torche_3 -> rect.left == 48)
            torche_3 -> rect.left = 0;
        else
            torche_3 -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_torche33(el *torche_33, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (torche_33 -> rect.left == 48)
            torche_33 -> rect.left = 0;
        else
            torche_33 -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_torche4(el *torche_4, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (torche_4 -> rect.left == 48)
            torche_4 -> rect.left = 0;
        else
            torche_4 -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_torche44(el *torche_44, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (torche_44 -> rect.left == 48)
            torche_44 -> rect.left = 0;
        else
            torche_44 -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_smoke(el *water, sfClock *clock, int max)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    water->rect.top = 0;
    water->rect.height = 58;
    if (seconds > 0.15) {
        if (water -> rect.left >= 0 && water -> rect.left < 15) {
            water -> rect.left = 15;
            water -> rect.width = 35;
        } else if (water -> rect.left >= 15 && water -> rect.left < 44) {
            water -> rect.left = 44;
            water -> rect.width = 60;
        } else if (water -> rect.left >= 44) {
            water -> rect.left = 0;
            water -> rect.width = 16;
        }
        sfClock_restart(clock);
    }
}

void move_smoke_r(el *water, sfClock *clock, int max)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    water->rect.top = 0;
    water->rect.height = 58;
    if (seconds > 0.15) {
        if (water -> rect.left >= 0 && water -> rect.left < 44) {
            water -> rect.left = 44;
            water -> rect.width = 35;
        } else if (water -> rect.left >= 44 && water -> rect.left < 79) {
            water -> rect.left = 79;
            water -> rect.width = 16;
        } else if (water -> rect.left >= 79) {
            water -> rect.left = 0;
            water -> rect.width = 50;
        }
        sfClock_restart(clock);
    }
}

void move_smoke_d(el *water, sfClock *clock, int max)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    water->rect.left = 0;
    water->rect.width = 48;
    if (seconds > 0.15) {
        if (water -> rect.top == 0) {
            water -> rect.top = 52;
            water -> rect.height = 30;
        } else if (water -> rect.top == 52) {
            water -> rect.top = 84;
            water -> rect.height = 40;
        } else if (water -> rect.top == 84) {
            water -> rect.top = 0;
        }
        sfClock_restart(clock);
    }
}

void move_smoke_u(el *water, sfClock *clock, int max)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    water->rect.left = 0;
    water->rect.width = 48;
    if (seconds > 0.15) {
        if (water -> rect.top == 0) {
            water -> rect.top = 16;
            water -> rect.height = 30;
        } else if (water -> rect.top == 16) {
            water -> rect.top = 54;
            water -> rect.height = 60;
        } else if (water -> rect.top == 54) {
            water -> rect.top = 0;
            water -> rect.height = 16;
        }
        sfClock_restart(clock);
    }
}

void move_tcave4(el *tcave_4, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (tcave_4 -> rect.left == 48)
            tcave_4 -> rect.left = 0;
        else
            tcave_4 -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_tcave44(el *tcave_44, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (tcave_44 -> rect.left == 48)
            tcave_44 -> rect.left = 0;
        else
            tcave_44 -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_tcave444(el *tcave_444, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (tcave_444 -> rect.left == 48)
            tcave_444 -> rect.left = 0;
        else
            tcave_444 -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_tcave1(el *tcave_1, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (tcave_1 -> rect.left == 48)
            tcave_1 -> rect.left = 0;
        else
            tcave_1 -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_tcave11(el *tcave_11, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (tcave_11 -> rect.left == 48)
            tcave_11 -> rect.left = 0;
        else
            tcave_11 -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_tcave2(el *tcave_2, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (tcave_2 -> rect.left == 48)
            tcave_2 -> rect.left = 0;
        else
            tcave_2 -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_tcave22(el *tcave_22, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (tcave_22 -> rect.left == 48)
            tcave_22 -> rect.left = 0;
        else
            tcave_22 -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_tcave222(el *tcave_222, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (tcave_222 -> rect.left == 48)
            tcave_222 -> rect.left = 0;
        else
            tcave_222 -> rect.left += 16;
        sfClock_restart(clock);
    }
}

void move_tcave2222(el *tcave_2222, sfClock *clock)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > 0.1) {
        if (tcave_2222 -> rect.left == 48)
            tcave_2222 -> rect.left = 0;
        else
            tcave_2222 -> rect.left += 16;
        sfClock_restart(clock);
    }
}
