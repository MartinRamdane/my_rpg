/*
** EPITECH PROJECT, 2021
** my_putstr.c
** File description:
** isneg
*/

#include "../Includes/my.h"

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
    str = &str[0];
    return 0;
}
