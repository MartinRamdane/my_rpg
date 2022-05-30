/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include "../Includes/my.h"

int resume_btn(sfRenderWindow *window, btn *button, sfEvent event, int action, infogame *gameinfos)
{
    sfSprite_setPosition(button -> my_sprite.sprite, button -> my_sprite.pos);
    sfSprite_setTexture(button->my_sprite.sprite, button->my_sprite.texture, sfTrue);
    if (get_mouse_button(window, button->my_sprite) == 1) {
        if (button->type == 1)
            button->my_sprite.rect.left = button->my_sprite.rect.width;
        if (event.type == sfEvtMouseButtonPressed)
            return 1;
    } else if (button->my_sprite.rect.left == button->my_sprite.rect.width)
        button->my_sprite.rect.left = 0;
    sfSprite_setTextureRect(button->my_sprite.sprite, button->my_sprite.rect);
    sfRenderWindow_drawSprite(window, button->my_sprite.sprite, NULL);
    return 0;
}

int do_pause(sfRenderWindow *window, infogame *gameinfos)
{
    sfEvent event;
    el background = init_element(0, 0, 1920, 1080, "Pictures/pause.png");
    btn *btn_resume = make_button(1, 300, 102);
    btn *btn_settings = make_button(1, 400, 102);
    btn *btn_exit = make_button(1, 200, 102);
    btn_resume -> my_sprite = init_button(init_pos(810, 341), btn_resume, "Pictures/content/btn_resume.png");
    btn_settings -> my_sprite = init_button(init_pos(760, 508), btn_settings, "Pictures/content/btn_settings.png");
    btn_exit -> my_sprite = init_button(init_pos(860, 675), btn_exit, "Pictures/content/btn_exit.png");
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEscape))
                return 0;
        }
        print_sprite(window, background);
        if (resume_btn(window, btn_resume, event, 7, gameinfos) == 1)
            return 0;
        print_btn(window, btn_settings, event, 3, gameinfos, 0);
        print_btn(window, btn_exit, event, 5, gameinfos, 1);
        sfRenderWindow_display(window);
    }
    return 0;
}