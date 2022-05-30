/*
** EPITECH PROJECT, 2022
** newgame.c
** File description:
** newgame.c
*/

#include "../Includes/my.h"

void make_newgame(sfRenderWindow *window, btn *button, sfEvent event, statchar *stat, infogame *gameinfos)
{
    sfSprite_setPosition(button -> my_sprite.sprite, button -> my_sprite.pos);
    sfSprite_setTexture(button->my_sprite.sprite, button->my_sprite.texture, sfTrue);
    if (get_mouse_button(window, button->my_sprite) == 1) {
        if (button->type == 1)
            button->my_sprite.rect.left = button->my_sprite.rect.width;
        if (event.type == sfEvtMouseButtonPressed) {
            sfMusic_stop(gameinfos -> arr_music[0]);
            intro(window, gameinfos);
            game(window, gameinfos, stat);
        }
    } else if (button->my_sprite.rect.left == button->my_sprite.rect.width)
        button->my_sprite.rect.left = 0;
    sfSprite_setTextureRect(button->my_sprite.sprite, button->my_sprite.rect);
    sfRenderWindow_drawSprite(window, button->my_sprite.sprite, NULL);
}

int newgame(sfRenderWindow *window, infogame *gameinfos)
{
    sfEvent event;
    btn *btn_continue = make_button(2, 400, 102);
    btn *btn_exit = make_button(1, 200, 102);
    btn_continue -> my_sprite = init_button(init_pos(760, 663), btn_continue, "Pictures/content/btn_continue.png");
    btn_exit -> my_sprite = init_button(init_pos(860, 782), btn_exit, "Pictures/content/btn_exit.png");
    el cadre = init_element(360, 422, 1200, 150, "Pictures/content/cadre_input.png");
    el heroinput = init_element(820, 44, 279, 287, "Pictures/content/doginput.png");
    gameinfos -> username = my_memset(gameinfos -> username, '\0', 17);
    gameinfos -> username[16] = '\0'; int i = 0;
    sfText *playerText = make_text(100, init_pos(420, 430), 2, sfWhite);
    el cursor = init_element(400, 450, 7, 96, "Pictures/content/cursor.png");
    statchar *stat = malloc(sizeof(statchar)); stat->attack = 10; stat->defense = 10; stat->life = 100;
    stat->crit = 5; stat-> stamina = 100; stat -> level = 1;
    sfSound_setVolume(gameinfos->arr_sound[1], gameinfos->vol_sound);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (event.type == sfEvtTextEntered) {
                if (i < 16 && event.text.unicode != 8 && event.text.unicode != 10) {
                    gameinfos -> username[i] = event.text.unicode;
                    sfText_setString(playerText, gameinfos -> username);
                    i = i + 1;
                    cursor.pos.x += 70; sfSound_play(gameinfos -> arr_sound[1]);
                }
                if (event.text.unicode == 8 && i > 0 && event.text.unicode != 10) {
                    i = i - 1;
                    gameinfos -> username[i] = '\0';
                    sfText_setString(playerText, gameinfos -> username);
                    cursor.pos.x -= 70; sfSound_play(gameinfos -> arr_sound[1]);
                }
            }
            if (sfKeyboard_isKeyPressed(sfKeyEnter) && my_strlen(gameinfos->username) >= 1) {
                sfMusic_stop(gameinfos -> arr_music[0]);
                intro(window, gameinfos);
                game(window, gameinfos, stat);
            }
        }
        if (my_strlen(gameinfos -> username) >= 1) {
            btn_continue -> type = 1;
            btn_continue -> my_sprite = init_button(init_pos(760, 663), btn_continue, "Pictures/content/btn_continue.png");
        } else {
            btn_continue -> type = 2;
            btn_continue -> my_sprite = init_button(init_pos(760, 663), btn_continue, "Pictures/content/btn_continue.png");
        }
        make_newgame(window, btn_continue, event, stat, gameinfos);
        print_btn(window, btn_exit, event, 5, gameinfos, 0);
        print_sprite(window, cadre);
        print_sprite(window, heroinput);
        print_sprite(window, cursor);
        sfRenderWindow_drawText(window, playerText, NULL);
        sfRenderWindow_display(window);
    }
    return 1;
}