/*
** EPITECH PROJECT, 2022
** button.c
** File description:
** button.c
*/

#include "../Includes/my.h"

btn *make_button(int type, int rect_w, int rect_h)
{
    btn *button = malloc(sizeof(btn));
    button -> type = type;
    button -> rect_w = rect_w;
    button -> rect_h = rect_h;
    return (button);
}

el init_button(sfVector2f pos, btn *button, char *text)
{
    el element;
    element.texture = sfTexture_createFromFile(text, NULL);
    element.sprite = sfSprite_create();
    element.pos.x = pos.x;
    element.pos.y = pos.y;
    element.rect.height = button -> rect_h;
    element.rect.width = button -> rect_w;
    element.rect.top = 0;
    if (button -> type == 1)
        element.rect.left = 0;
    else
        element.rect.left = element.rect.width * 2;
    sfSprite_setPosition(element.sprite, element.pos);
    return (element);
}

int get_mouse_button(sfRenderWindow *window, el my_sprite)
{
    sfVector2i mouse_pos = sfMouse_getPosition(window);
    if (mouse_pos.x >= my_sprite.pos.x && mouse_pos.y >= my_sprite.pos.y
        && mouse_pos.x <= my_sprite.pos.x + my_sprite.rect.width
        && mouse_pos.y <= my_sprite.pos.y + my_sprite.rect.height) {
        return 1;
    }
    return 0;
}

void launch_actions(sfRenderWindow *window, infogame *gameinfos, int action, int a)
{
    switch (action){
        case 1:
            newgame(window, gameinfos);
            break;
        case 3:
            settings(window, gameinfos, a);
            break;
        case 4:
            sfRenderWindow_close(window);
            break;
        case 5:
            menu(window, gameinfos);
            break;
        case 6:
            input(window, gameinfos, a);
            break;
        default:
            break;
    }
}

void print_btn(sfRenderWindow *window, btn *button, sfEvent event, int action, infogame *gameinfos, int a)
{
    sfSprite_setPosition(button -> my_sprite.sprite, button -> my_sprite.pos);
    sfSprite_setTexture(button->my_sprite.sprite, button->my_sprite.texture, sfTrue);
    if (get_mouse_button(window, button->my_sprite) == 1) {
        if (button->type == 1)
            button->my_sprite.rect.left = button->my_sprite.rect.width;
        if (event.type == sfEvtMouseButtonPressed)
            launch_actions(window, gameinfos, action, a);
    } else if (button->my_sprite.rect.left == button->my_sprite.rect.width)
        button->my_sprite.rect.left = 0;
    sfSprite_setTextureRect(button->my_sprite.sprite, button->my_sprite.rect);
    sfRenderWindow_drawSprite(window, button->my_sprite.sprite, NULL);
}