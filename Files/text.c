/*
** EPITECH PROJECT, 2022
** text.c
** File description:
** text.c
*/

#include "../Includes/my.h"

sfText *make_text(int fontsize, sfVector2f pos, int spacing, sfColor color)
{
    sfText *my_text = sfText_create();
    sfText_setLetterSpacing(my_text, spacing);
    sfText_setColor(my_text, color);
    sfFont *font_base = sfFont_createFromFile("Fonts/Determination.ttf");
    sfText_setFont(my_text, font_base);
    sfText_setCharacterSize(my_text, fontsize);
    sfText_setPosition(my_text, pos);
    return (my_text);
}