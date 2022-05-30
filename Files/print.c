/*
** EPITECH PROJECT, 2021
** print.c
** File description:
** print
*/

#include "../Includes/my.h"

void print_text_origin(sfRenderWindow *window, char *str, sfVector2f pos, int len)
{
    sfText *texte;
    texte = sfText_create();
    sfFont *font;
    font = sfFont_createFromFile("Pictures/LeagueSpartan-Regular.ttf");
    sfVector2f origin = {my_strlen(str) / 2, 1};
    sfText_setOrigin(texte, origin);
    sfText_setFont(texte, font);
    sfText_setString(texte, str);
    sfText_setColor(texte, sfBlack);
    sfText_setCharacterSize(texte, len);
    sfText_setPosition(texte, pos);
    sfRenderWindow_drawText(window, texte, NULL);
}

void print_text(sfRenderWindow *window, char *str, sfVector2f pos, int len)
{
    sfText *texte;
    texte = sfText_create();
    sfFont *font;
    font = sfFont_createFromFile("Pictures/LeagueSpartan-Regular.ttf");
    sfText_setFont(texte, font);
    sfText_setString(texte, str);
    sfText_setColor(texte, sfBlack);
    sfText_setCharacterSize(texte, len);
    sfText_setPosition(texte, pos);
    sfRenderWindow_drawText(window, texte, NULL);
}

sfVector2f makepos(int x, int y)
{
    sfVector2f pos = {x, y};
    return (pos);
}

void print_error_txt(sfRenderWindow *window, char *str, sfVector2f pos, int len)
{
    sfText *texte;
    texte = sfText_create();
    sfFont *font;
    font = sfFont_createFromFile("Pictures/LeagueSpartan-Regular.ttf");
    sfText_setFont(texte, font);
    sfText_setString(texte, str);
    sfText_setColor(texte, sfRed);
    sfText_setCharacterSize(texte, len);
    sfText_setPosition(texte, pos);
    sfRenderWindow_drawText(window, texte, NULL);
}

void print_sprite(sfRenderWindow *window, el element)
{
    sfSprite_setPosition(element.sprite, element.pos);
    sfSprite_setTexture(element.sprite, element.texture, sfTrue);
    sfSprite_setTextureRect(element.sprite, element.rect);
    sfRenderWindow_drawSprite(window, element.sprite, NULL);
}