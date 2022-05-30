/*
** EPITECH PROJECT, 2021
** my_itoi.c
** File description:
** itoi
*/

#include "../Includes/my.h"

char *my_revstr(char *str)
{
    int i = 0, len = my_strlen(str) - 1;
    char tmp;
    while (i < len) {
        tmp = str[len];
        str[len] = str[i];
        str[i] = tmp;
        len = len - 1;
        i = i + 1;
    }
    return str;
}

int my_intlen(int nb)
{
    int i = 1;
    int k = 1;
    while (nb / k > 9) {
        i = i + 1;
        k = k * 10;
    }
    return i;
}

char *my_itoi(int nb)
{
    int count = 1;
    int i = nb;
    while (i >= 10) {
        i = i / 10;
        count += 1;
    }
    char *str = malloc(sizeof(char) * count + 1);
    i = count - 1;
    while (i >= 0) {
        str[i] = nb % 10 + 48;
        nb = nb / 10;
        i = i - 1;
    }
    str[count] = '\0';
    return (str);
}