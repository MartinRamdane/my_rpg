/*
** EPITECH PROJECT, 2021
** my_strcat.c
** File description:
** str cat
*/

#include "../Includes/my.h"

char *my_strcat(char *dest, char const *src)
{
    char *str = malloc(sizeof(char) * (my_strlen(dest) + my_strlen(src)) + 1);
    str = my_strcpy(str, dest);
    int j = my_strlen(dest), i = 0;
    while (src[i] != '\0') {
        str[j] = src[i];
        i = i + 1;
        j = j + 1;
    }
    str[j] = '\0';
    return str;
}
