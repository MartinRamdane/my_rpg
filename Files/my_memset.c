/*
** EPITECH PROJECT, 2022
** my_memset.c
** File description:
** my_memset.c
*/

#include "../Includes/my.h"

char *my_memset(char *str, char c, int len)
{
    int i = 0;
    str = malloc(sizeof(char) * len);
    while (i < len) {
        str[i] = c;
        i += 1;
    }
    return (str);
}
