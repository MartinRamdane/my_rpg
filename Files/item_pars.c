/*
** EPITECH PROJECT, 2022
** item_pars.c
** File description:
** item_pars.c
*/

#include "../Includes/my.h"

char **list_parsing_item(char *line)
{
    char **list = malloc(sizeof(char *) * 5);
    char *tmp = malloc(sizeof(char) * 100);
    int i = 0; int j = 0; int k = 0;
    while (line[i] != '\n') {
        if (line[i] == ',' || line[i] == ';') {
            i++; tmp[k] = '\0';
            list[j] = malloc(sizeof(char) * (my_strlen(tmp) + 1));
            list[j] = my_strcpy(list[j], tmp);
            j++;
            k = 0;
            free(tmp);
            tmp = malloc(sizeof(char) * 100);
        }
        if (line[i] == '\n')
            break;
        tmp[k] = line[i];
        i++; k++;
    }
    free(tmp);
    return (list);
}