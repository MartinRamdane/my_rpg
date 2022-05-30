/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include "../Includes/my.h"

void do_loose(sfRenderWindow *window, infogame *gameinfos)
{
    FILE *fp = fopen("config/save.txt", "w");
    fclose(fp);
    sfMusic_stop(gameinfos->arr_music[2]);
    sfMusic_setLoop(gameinfos->arr_music[3], sfTrue); sfMusic_setVolume(gameinfos->arr_music[3], gameinfos->vol_music);
    sfMusic_play(gameinfos->arr_music[3]);
    sfEvent event;
    btn *btn_exit = make_button(1, 200, 102);
    btn_exit -> my_sprite = init_button(init_pos(860, 830), btn_exit, "Pictures/content/btn_exit.png");
    el background = init_element(0, 0, 1920, 1080, "Pictures/losescreen.png");
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        print_sprite(window, background);
        print_btn(window, btn_exit, event, 5, gameinfos, 0);
        sfRenderWindow_display(window);
    }
}

void win(sfRenderWindow *window, infogame *gameinfos)
{
    FILE *fp = fopen("config/save.txt", "w");
    fclose(fp);
    sfMusic_stop(gameinfos->arr_music[2]);
    sfMusic_setLoop(gameinfos->arr_music[3], sfTrue); sfMusic_setVolume(gameinfos->arr_music[3], gameinfos->vol_music);
    sfMusic_play(gameinfos->arr_music[3]);
    sfEvent event;
    btn *btn_exit = make_button(1, 200, 102);
    btn_exit -> my_sprite = init_button(init_pos(860, 831), btn_exit, "Pictures/content/btn_exit.png");
    el background = init_element(0, 0, 1920, 1080, "Pictures/winscreen.png");
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        print_sprite(window, background);
        print_btn(window, btn_exit, event, 5, gameinfos, 0);
        sfRenderWindow_display(window);
    }
}
