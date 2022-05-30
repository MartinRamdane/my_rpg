/*
** EPITECH PROJECT, 2021
** my_put_nbr.c
** File description:
** put nbr
*/

#include "../Includes/my.h"

int my_put_nbr(int nb)
{
    if (nb < 0) {
        my_putchar('-');
        nb = nb * (-1);
    }
    int unit = nb;
    if (nb >= 10) {
        unit = unit % 10;
        nb = nb / 10;
        my_put_nbr(nb);
        my_putchar(unit + 48);
    } else {
        my_putchar(nb + 48);
    }
    return 0;
}
