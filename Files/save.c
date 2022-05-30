/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include "../Includes/my.h"

void do_save(infogame *gameinfo, statchar *stat)
{
    FILE *fp = fopen("config/save.txt", "w");
    fclose(fp);
    int fd = open("config/save.txt", O_WRONLY);
    int pos = 0;
    write(fd, gameinfo->username, my_strlen(gameinfo->username));
    pos += my_strlen(gameinfo->username);
    write(fd, "\n", 1); pos += 1;
    write(fd, my_itoi(gameinfo->pos_player_y), my_strlen(my_itoi(gameinfo->pos_player_y)));
    pos += my_strlen(my_itoi(gameinfo->pos_player_y));
    write(fd, ",", 1); pos += 1;
    write(fd, my_itoi(gameinfo->pos_player_x), my_strlen(my_itoi(gameinfo->pos_player_x)));
    pos += my_strlen(my_itoi(gameinfo->pos_player_x));
    write(fd, "\n", 1); pos += 1;
    write(fd, my_itoi(stat->life), my_strlen(my_itoi(stat->life)));
    pos += my_strlen(my_itoi(stat->life));
    write(fd, "\n", 1); pos += 1;
    write(fd, my_itoi(stat->stamina), my_strlen(my_itoi(stat->stamina)));
    pos += my_strlen(my_itoi(stat->stamina));
    write(fd, "\n", 1); pos += 1;
    write(fd, my_itoi(stat->defense), my_strlen(my_itoi(stat->defense)));
    pos += my_strlen(my_itoi(stat->defense));
    write(fd, "\n", 1); pos += 1;
    write(fd, my_itoi(stat->crit), my_strlen(my_itoi(stat->crit)));
    pos += my_strlen(my_itoi(stat->crit));
    write(fd, "\n", 1); pos += 1;
    write(fd, my_itoi(stat->level), my_strlen(my_itoi(stat->level)));
    pos += my_strlen(my_itoi(stat->level));
    write(fd, "\n", 1); pos += 1;
    write(fd, my_itoi(stat->attack), my_strlen(my_itoi(stat->attack)));
    write(fd, "\n", 1);
    write(fd, my_itoi(gameinfo->my_quests[0]), 1);
    write(fd, my_itoi(gameinfo->my_quests[1]), 1);
    write(fd, my_itoi(gameinfo->my_quests[2]), 1);
    write(fd, my_itoi(gameinfo->my_quests[3]), 1);
    write(fd, "\n", 1);
    write(fd, gameinfo->my_items, my_strlen(gameinfo->my_items));
    write(fd, "\n", 1);
    close(fd);
}

void recup_save(infogame *gameinfo, statchar *stat)
{
    FILE *fd = fopen("config/save.txt", "r");
    char **tab = malloc(sizeof(char *) * 11);
    int i = 0; size_t size = 0;
    char *tmp = NULL;
    while (getline(&tmp, &size, fd) != -1) {
        tmp[my_strlen(tmp) - 1] = '\0';
        tab[i] = malloc(sizeof(char) * (my_strlen(tmp) + 1));
        tab[i] = my_strcpy(tab[i], tmp);
        i++;
    }
    tab[i] = NULL;
    gameinfo->username = malloc(sizeof(char) * (my_strlen(tab[0]) + 1));
    gameinfo->username = my_strcpy(gameinfo->username, tab[0]);
    gameinfo->pos_player_y = my_getnbr(tab[1]);
    gameinfo->pos_player_x = my_getnbr_pos(tab[1], get_pos_virgule(tab[1]));
    stat->life = my_getnbr(tab[2]);
    stat->stamina = my_getnbr(tab[3]);
    stat->defense = my_getnbr(tab[4]);
    stat->crit = my_getnbr(tab[5]);
    stat->level = my_getnbr(tab[6]);
    stat->attack = my_getnbr(tab[7]);
    gameinfo->my_quests[0] = tab[8][0] - 48;
    gameinfo->my_quests[1] = tab[8][1] - 48;
    gameinfo->my_quests[2] = tab[8][2] - 48;
    gameinfo->my_quests[3] = tab[8][3] - 48;
    gameinfo->my_items = malloc(sizeof(char) * (my_strlen(tab[9]) + 1));
    gameinfo->my_items = my_strcpy(gameinfo->my_items, tab[9]);
}