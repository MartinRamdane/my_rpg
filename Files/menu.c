/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include "../Includes/my.h"

int check_save_file(void)
{
    int fd = open("config/save.txt", O_RDONLY);
    if (fd == -1) {
        close(fd);
        return 1;
    }
    char *buff = malloc(sizeof(char));
    int rd = read(fd, buff, 1);
    close(fd);
    if (buff[0] == '\0')
        return 1;
    return 0;
}

void continue_game(sfRenderWindow *window, btn *button, sfEvent event, infogame *gameinfos)
{
    sfSprite_setPosition(button -> my_sprite.sprite, button -> my_sprite.pos);
    sfSprite_setTexture(button->my_sprite.sprite, button->my_sprite.texture, sfTrue);
    if (get_mouse_button(window, button->my_sprite) == 1) {
        if (button->type == 1)
            button->my_sprite.rect.left = button->my_sprite.rect.width;
        if (event.type == sfEvtMouseButtonPressed && button->type == 1) {
            statchar *stat = malloc(sizeof(statchar));
            recup_save(gameinfos, stat);
            game(window, gameinfos, stat);
        }
    } else if (button->my_sprite.rect.left == button->my_sprite.rect.width)
        button->my_sprite.rect.left = 0;
    sfSprite_setTextureRect(button->my_sprite.sprite, button->my_sprite.rect);
    sfRenderWindow_drawSprite(window, button->my_sprite.sprite, NULL);
}

int menu(sfRenderWindow *window, infogame *gameinfos)
{
    sfEvent event;
    sfMusic_play(gameinfos->arr_music[0]);
    sfMusic_setLoop(gameinfos->arr_music[0], sfTrue);
    sfMusic_stop(gameinfos->arr_music[3]);
    btn *btn_newgame = make_button(1, 400, 102);
    btn *btn_continue = make_button(2, 400, 102);
    btn *btn_settings = make_button(1, 400, 102);
    btn *btn_exit = make_button(1, 200, 102);
    if (check_save_file() == 0)
        btn_continue->type = 1;
    btn_newgame -> my_sprite = init_button(init_pos(760, 401), btn_newgame, "Pictures/content/btn_newgame.png");
    btn_continue -> my_sprite = init_button(init_pos(760, 540), btn_continue, "Pictures/content/btn_continue.png");
    btn_settings -> my_sprite = init_button(init_pos(760, 685), btn_settings, "Pictures/content/btn_settings.png");
    btn_exit -> my_sprite = init_button(init_pos(860, 830), btn_exit, "Pictures/content/btn_exit.png");
    el title = init_element(647, 90, 625, 167, "Pictures/content/logo.png");
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
        }
        sfMusic_setVolume(gameinfos->arr_music[0], gameinfos->vol_music);
        print_btn(window, btn_newgame, event, 1, gameinfos, 0);
        continue_game(window, btn_continue, event, gameinfos);
        print_btn(window, btn_settings, event, 3, gameinfos, 0);
        print_btn(window, btn_exit, event, 4, gameinfos, 0);
        print_sprite(window, title);
        sfRenderWindow_display(window);
    }
    return 0;
}