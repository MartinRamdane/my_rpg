/*
** EPITECH PROJECT, 2022
** colisions
** File description:
** colisions
*/

#include "../Includes/my.h"

char **get_pos()
{
    int fd = open("config/positions.txt", O_RDONLY);
    struct stat s;
    stat("config/positions.txt", &s);
    char *buffer = malloc(sizeof(char) * (s.st_size + 1));
    read(fd, buffer, s.st_size);
    buffer[s.st_size]= '\0';
    close(fd);
    char **tab = my_str_to_word_array(buffer);
    return tab;
}

char **get_pos1()
{
    int fd = open("config/maison.txt", O_RDONLY);
    struct stat s;
    stat("config/maison.txt", &s);
    char *buffer = malloc(sizeof(char) * (s.st_size + 1));
    read(fd, buffer, s.st_size);
    buffer[s.st_size]= '\0';
    close(fd);
    char **tab = my_str_to_word_array2(buffer);
    return tab;
}

char **get_pos2()
{
    int fd = open("config/cave.txt", O_RDONLY);
    struct stat s;
    stat("config/maison.txt", &s);
    char *buffer = malloc(sizeof(char) * (s.st_size + 1));
    read(fd, buffer, s.st_size);
    buffer[s.st_size]= '\0';
    close(fd);
    char **tab = my_str_to_word_array3(buffer);
    return tab;
}

char *get_name(char *str)
{
    char *result = malloc(sizeof(char) * 42);
    int i = 0;
    while (str[i] != ',') {
        result[i] = str[i];
        i++;
    }
    result[i] = '\0';
    return result;
}

sfVector2i get_coord(char *str)
{
    sfVector2i coord;
    int i = 0;
    while (str[i] != ',')
        i++;
    i += 2;
    coord.x = my_getnbr_pos(str, i);
    while (str[i] != ',')
        i++;
    i += 2;
    coord.y = my_getnbr_pos(str, i);
    return coord;
}

sfVector2i get_rect(char *str)
{
    sfVector2i coord;
    int i = 0, tmp = 0;
    while (tmp != 3) {
        if (str[i] == ',')
            tmp += 1;
        i++;
    }
    i += 1;
    coord.x = my_getnbr_pos(str, i);
    while (str[i] != ',')
        i++;
    i += 2;
    coord.y = my_getnbr_pos(str, i);
    return coord;
}

liste_colisions *create_liste()
{
    char **positions = get_pos();
    liste_colisions *liste = NULL;
    for (int i = 0; positions[i]; i++) {
        char *name = get_name(positions[i]);
        sfVector2i coord = get_coord(positions[i]);
        sfVector2i rect = get_rect(positions[i]);
        liste_colisions *element = malloc(sizeof(liste_colisions));
        element -> element = init_element(coord.x, coord.y, rect.x, rect.y, name);
        element -> next = liste;
        liste = element;
    }
    return liste;
}

liste_colisions *create_liste1()
{
    char **positions = get_pos1();
    liste_colisions *liste = NULL;
    for (int i = 0; positions[i]; i++) {
        char *name = get_name(positions[i]);
        sfVector2i coord = get_coord(positions[i]);
        sfVector2i rect = get_rect(positions[i]);
        liste_colisions *element = malloc(sizeof(liste_colisions));
        element -> element = init_element(coord.x, coord.y, rect.x, rect.y, name);
        element -> next = liste;
        liste = element;
    }
    return liste;
}

liste_colisions *create_liste2()
{
    char **positions = get_pos2();
    liste_colisions *liste = NULL;
    for (int i = 0; positions[i]; i++) {
        char *name = get_name(positions[i]);
        sfVector2i coord = get_coord(positions[i]);
        sfVector2i rect = get_rect(positions[i]);
        liste_colisions *element = malloc(sizeof(liste_colisions));
        element -> element = init_element(coord.x, coord.y, rect.x, rect.y, name);
        element -> next = liste;
        liste = element;
    }
    return liste;
}
