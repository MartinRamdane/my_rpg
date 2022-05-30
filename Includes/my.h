/*
** EPITECH PROJECT, 2021
** framebuffer.h
** File description:
** framebuffer
*/

#include <SFML/Audio.h>
#include <SFML/System.h>
#include <SFML/Graphics.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <SFML/Config.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <math.h>

#pragma once

#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

typedef struct clock {
    sfClock *clock1;
    sfClock *clock2;
    sfClock *clock3;
    sfClock *clock4;
    sfClock *clock5;
    sfClock *clock6;
    sfClock *clock7;
    sfClock *clock8;
    sfClock *clock9;
    sfClock *clock10;
    sfClock *clock11;
    sfClock *clock12;
    sfClock *clock13;
    sfClock *clock14;
    sfClock *clock15;
    sfClock *clock16;
    sfClock *clock17;
    sfClock *clock18;
    sfClock *clock19;
    sfClock *clock20;
    sfClock *clock21;
    sfClock *clock22;
    sfClock *clock23;
    sfClock *clock24;
    sfClock *clock25;
    sfClock *clock26;
    sfClock *clock27;
    sfClock *clock28;
    sfClock *clock29;
    sfClock *clock30;
    sfClock *clock31;
    sfClock *clock32;
    sfClock *clock33;
    sfClock *clock34;
    sfClock *clock35;
    sfClock *clock36;
    sfClock *clock37;
    sfClock *clock38;
    sfClock *clock39;
    sfClock *clock40;
    sfClock *clock41;
} c;

typedef struct element_game {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f pos_start;
    sfIntRect rect;
    int pnj_ac;
    int quest;
    int dir;
} el;

typedef struct skill {
    int id;
    int degat;
    int level;
    int get;
} skill;

typedef struct item {
    int id;
    el my_sprite;
    el logo_sprite;
    char *name;
    char *desc;
    int type;
    sfVector2f pos;
} item;

typedef struct statchar {
    int life;
    int stamina;
    int attack;
    int crit;
    int defense;
    int level;
} statchar;

typedef struct player {
    el *my_sprite;
    char *name;
    int class;
    int life;
    int endurance;
    item **inventaire;
    skill *skills;
    statchar *ply_stat;
    int boots;
    int const_stamina;
} player;

typedef struct pnj {
    el my_sprite;
    sfVector2f pos;
    int type;
    char *name;
    char **dialogue;
    statchar *pnj_stat;
    int life;
} png;

typedef struct dialogues {
    int a;
    int z;
} dialogues;

typedef struct button {
    el my_sprite;
    int type;
    int rect_w;
    int rect_h;
} btn;

typedef struct quest {
    sfText *text;
    sfText *title;
    int null;
    sfVector2f pos_txt;
    sfVector2f pos_title;
} quest;

typedef struct infogame {
    sfMusic **arr_music;
    sfSound **arr_sound;
    char *username;
    float vol_music;
    float vol_sound;
    int framerate;
    int move_foreward;
    int move_back;
    int move_rigth;
    int move_left;
    int map;
    int inventory;
    int sprint;
    int hit;
    int pause;
    int fps;
    char *resolution;
    int pos_player_x;
    int pos_player_y;
    int h1;
    int h2;
    int h3;
    int h4;
    int c1;
    int *my_quests;
    char *my_items;
    int boss;
} infogame;

typedef struct text {
    sfText *reso;
    char *str;
} text;

typedef struct dico {
    int val;
    char key;
} dico;

typedef struct liste_colisions {
    el element;
    struct liste_colisions *next;
} liste_colisions;

typedef struct ordre_quest {
    int quest1;
    int quest2;
    int quest3;
    int quest4;
} ordre_quest;

int my_strlen(char const *str);
int my_getnbr(char *str);
char *my_itoi(int nb);
int my_putstr(char const *str);
int my_strstr(char *str, char const *to_find);
void my_putchar(char c);
void print_text(sfRenderWindow *window, char *str, sfVector2f pos, int len);
int my_put_nbr(int nb);
int my_printf(const char *format, ...);
void print_text(sfRenderWindow *window, char *str, sfVector2f pos, int len);
el init_element(int posx, int posy, int rect_width, int rect_heigh, char *fil);
void print_sprite(sfRenderWindow *window, el element);
int move_view(sfView *mini_map, sfView *view, player *my_player, c *clocks, liste_colisions *liste, infogame *gameinfos, int if_stamina, el *smoke);
c init_clocks(void);
void move_player(el *player, sfClock *clock, float scds);
void attack_player(el *player, sfClock *clock);
void attack(el *player, c *clock, int if_run, infogame *gameinfos);
void change_perso(el *player, sfEvent event);
void do_map(sfRenderWindow *window, el map, el player, int *m, sfEvent event, sfView *view, float *zoom, infogame *gameinfos, el pnj, el pnj2, el pnj3, el dog2);
void inter_pnj(sfRenderWindow *window, el player, el *png, dialogues *d);
void move_pnj(el *player, sfClock *clock);
sfVector2f init_pos(int x, int y);
int menu(sfRenderWindow *window, infogame *gameinfos);
int newgame(sfRenderWindow *window, infogame *gameinfos);
el init_button(sfVector2f pos, btn *button, char *text);
btn *make_button(int type, int rect_w, int rect_h);
sfText *make_text(int fontsize, sfVector2f pos, int spacing, sfColor color);
int func_newgame(sfRenderWindow *window);
void print_btn(sfRenderWindow *window, btn *button, sfEvent event, int action, infogame *gameinfos, int a);
sfMusic *play_sound(char *filepath, int vol);
sfSound *make_sound(char *filepath, int vol);
sfMusic **tab_music(void);
sfSound **tab_sound(void);
char *my_memset(char *str, char c, int len);
int game(sfRenderWindow *window, infogame *gameinfos, statchar *stat);
liste_colisions *create_liste();
char *my_strcpy(char *dest, char const *src);
char *my_strcat(char *dest, char const *src);
char **my_str_to_word_array(char const *str);
char **my_str_to_word_array2(char const *str);
char **my_str_to_word_array3(char const *str);
int my_getnbr_pos(char *str, int i);
void print_liste_colisions(sfRenderWindow *window, liste_colisions *liste);
int settings(sfRenderWindow *window, infogame *gameinfos, int a);
int my_strstr(char *str, char const *to_find);
int input(sfRenderWindow *window, infogame *gameinfos, int a);
char *get_char(int key);
int get_key(void);
void move_water(el *water, sfClock *clock, int max);
void move_water2(el *water, sfClock *clock, int max);
void move_cascade(el *cascade, sfClock *clock);
int up_stamina(el *bar_stamina, player *my_player, sfClock *clock, int *up);
char **list_parsing_item(char *line);
item *make_list_item(void);
item *make_inventory(void);
int add_elem_inventory(item *inventory, item objet);
void print_slot(sfRenderWindow *window, el *slot, int *selected, item *inv, int num, int *list_selected);
void print_info_items(sfRenderWindow *window, int *selected, el info_item, item *inv, sfEvent event, player *ply);
void print_items(sfRenderWindow *window, item *inv, int i);
int get_mouse_button(sfRenderWindow *window, el my_sprite);
void recup_save(infogame *gameinfo, statchar *stat);
int get_pos_virgule(char *str);
void do_save(infogame *gameinfo, statchar *stat);
void intro(sfRenderWindow *window, infogame *gameinfos);
int fight(sfRenderWindow *window, player *ply, png *mob, infogame *gameinfos, item* inv);
void anim_txt(sfClock *clock, char *txt, int *i, sfText *texte, float scds);
void if_continuer(sfClock *clock, int *continuer, int scds);
int spawn_ennemy(el pnj, c *clocks, sfRenderWindow *window, el player);
int ia_enemy(el *ennemy, c *clocks, el *player, sfRenderWindow *window);
void my_sleep(int scds);
void move_mer(el *cascade, sfClock *clock);
char *get_txt_pos(char *str, int x);
quest do_lord_pnj2(sfRenderWindow *window, infogame *gameinfos, el map, player my_player, el pnj, sfView *view, sfView *mini_view, el cadre, int *nb_quest);
quest do_lord_pnj(sfRenderWindow *window, infogame *gameinfos, el map, player my_player, el pnj, sfView *view, sfView *mini_view, el cadre, int *nb_quest);
quest do_lord_pnj3(sfRenderWindow *window, infogame *gameinfos, el map, player my_player, el pnj, sfView *view, sfView *mini_view, el cadre, int *nb_quest);
quest do_lord_pnj4(sfRenderWindow *window, infogame *gameinfos, el map, player my_player, el pnj, sfView *view, sfView *mini_view, el cadre, int *nb_quest);
quest do_boss(sfRenderWindow *window, infogame *gameinfos, el map, player my_player, el pnj, sfView *view, sfView *mini_view, el cadre, int *nb_quest);
int house1(sfRenderWindow *window, infogame *gameinfos, statchar *stat, player *my_player, item *ply_inv);
int house2(sfRenderWindow *window, infogame *gameinfos, statchar *stat, player *my_player, item *ply_inv);
int house3(sfRenderWindow *window, infogame *gameinfos, statchar *stat, player *my_player, item *ply_inv);
int house4(sfRenderWindow *window, infogame *gameinfos, statchar *stat, player *my_player, item *ply_inv);
int cave(sfRenderWindow *window, infogame *gameinfos, statchar *stat, player *my_player, item *ply_inv);
void move_torche1(el *torche_1, sfClock *clock);
void move_torche11(el *torche_11, sfClock *clock);
void move_torche111(el *torche_111, sfClock *clock);
void move_torche2(el *torche_2, sfClock *clock);
void move_torche22(el *torche_22, sfClock *clock);
void move_torche3(el *torche_3, sfClock *clock);
void move_torche33(el *torche_33, sfClock *clock);
void move_torche4(el *torche_4, sfClock *clock);
void move_torche44(el *torche_44, sfClock *clock);
void move_smoke(el *water, sfClock *clock, int max);
void move_smoke_r(el *water, sfClock *clock, int max);
void move_smoke_d(el *water, sfClock *clock, int max);
void move_smoke_u(el *water, sfClock *clock, int max);
void smoking_run(el player, el *smoke, sfRenderWindow *window);
int *fill_int_arr(int taille);
liste_colisions *create_liste1();
liste_colisions *create_liste2();
int inter_objet(sfRenderWindow *window, el *obj, el player);
void get_quest(infogame *gameinfos, quest *quest1, quest *quest2, quest *quest3, quest *quest4, el *pnj1, el *pnj2, el *pnj3, el *pnj4, int *nb_quest);
int ad_colisions_enemy(el *sorcier, liste_colisions *liste, el player);
int do_pause(sfRenderWindow *window, infogame *gameinfos);
void move_blob(el *player, sfClock *clock);
int ex_btn(sfRenderWindow *window, btn *button, sfEvent event, int action, infogame *gameinfos);
void recup_inventory(item *list_item, item *plt_inv, infogame *gameinfos);
int get_nb_items(item *inventory);
void do_loose(sfRenderWindow *window, infogame *gameinfos);
void win(sfRenderWindow *window, infogame *gameinfos);
