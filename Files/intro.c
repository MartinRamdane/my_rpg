/*
** EPITECH PROJECT, 2022
** button.c
** File description:
** button.c
*/

#include "../Includes/my.h"

char *get_txt_pos(char *str, int x)
{
    int i = 0;
    char *txt = malloc(sizeof(char) * (x + 1));
    while (str[i] && i < x) {
        txt[i] = str[i];
        i += 1;
    }
    txt[i] = '\0';
    return txt;
}

void anim_txt(sfClock *clock, char *txt, int *i, sfText *texte, float scds)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > scds) {
        *i += 1;
        sfText_setString(texte, get_txt_pos(txt, *i));
        sfClock_restart(clock);
    }
}

void if_continuer(sfClock *clock, int *continuer, int scds)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock);
    seconds = time.microseconds / 1000000.0;
    if (seconds > scds) {
        *continuer = 1;
    }
}

void intro(sfRenderWindow *window, infogame *gameinfos)
{
    sfEvent event;
    sfVector2u size_window = {my_getnbr(gameinfos -> resolution), my_getnbr_pos(gameinfos -> resolution, 5)};
    sfRenderWindow_setSize(window, size_window);
    sfMusic *music = sfMusic_createFromFile("music/music_intro.ogg");
    sfMusic_setLoop(music, sfTrue); sfMusic_setVolume(music, gameinfos->vol_music);
    sfMusic_play(music);
    int i = 0;
    sfClock *clock = sfClock_create();
    sfClock *clock2 = sfClock_create();
    int s = 5;
    char *txt = malloc(sizeof(char) * 53);
    sfVector2f pos = {150, 500};
    sfText *texte = make_text(62, pos, 1, sfWhite);
    int continuer = 0;
    float scds = 0.06;
    txt = my_strcpy(txt, "After a long sleep, you woke up in a strange land...");
    sfText_setString(texte, get_txt_pos(txt, i));
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEnter))
                scds = 0.01;
            if (sfKeyboard_isKeyPressed(sfKeyEnter) && i > 52)
                s = 2;
        }
        if (i > 52)
            if_continuer(clock2, &continuer, s);
        if (continuer == 1) {
            sfMusic_stop(music);
            return;
        }
        anim_txt(clock, txt, &i, texte, scds);
        sfRenderWindow_drawText(window, texte, NULL);
        sfRenderWindow_display(window);
    }
}
