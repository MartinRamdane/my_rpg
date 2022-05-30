/*
** EPITECH PROJECT, 2021
** my_strcpy.c
** File description:
** str copy
*/

#include "../Includes/my.h"

char *my_strcpy(char *dest, char const *src)
{
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strcpy_pos(char *dest, char const *src, int i)
{
    int j = 0;
    while (src[i] != '\0') {
        dest[j] = src[i];
        i = i + 1;
        j += 1;
    }
    dest[i] = '\0';
    return dest;
}

char *my_strcpy_pos_eq(char *dest, char const *src, int i)
{
    int j = 0;
    while (src[i] != '=') {
        dest[j] = src[i];
        i = i + 1;
        j += 1;
    }
    dest[i] = '\0';
    return dest;
}
