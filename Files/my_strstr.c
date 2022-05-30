/*
** EPITECH PROJECT, 2021
** my_strstr.c
** File description:
** find dtr
*/

#include "../Includes/my.h"

int my_strstr(char *str, char const *to_find)
{
    int i = 0, j = 0;
    while (str[i] != '\0') {
        if (str[i] != to_find[j])
            return 1;
            j = j + 1;
            i = i + 1;
    }
    return 0;
}
