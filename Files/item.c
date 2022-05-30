/*
** EPITECH PROJECT, 2022
** item.c
** File description:
** item.c
*/

#include "../Includes/my.h"

item make_item(char *str)
{
    int i = 0;
    char **list = list_parsing_item(str);
    item new_item;
    new_item.id = my_getnbr(list[0]);
    new_item.name = malloc(sizeof(char) * (my_strlen(list[2]) + 1));
    new_item.name = my_strcpy(new_item.name, list[2]);
    new_item.desc = malloc(sizeof(char) * (my_strlen(list[3]) + 1));
    new_item.desc = my_strcpy(new_item.desc, list[3]);
    new_item.type = my_getnbr(list[4]);
    new_item.my_sprite = init_element(0, 0, 16, 16, list[1]);
    new_item.logo_sprite = init_element(0, 0, 16, 16, list[1]);
    return (new_item);
}

item *make_list_item(void)
{
    item *list = malloc(sizeof(item) * 20);
    FILE *fd = fopen("config/item.txt", "r");
    char *line = NULL; size_t len = 0;
    int i = 0;
    while (getline(&line, &len, fd) != -1) {
        item new_item = make_item(line);
        list[i] = new_item;
        i ++;
    }
    fclose(fd);
    return (list);
}