/*
** EPITECH PROJECT, 2022
** inventory.c
** File description:
** inventory.c
*/

#include "../Includes/my.h"

item *make_inventory(void)
{
    item *inventory = malloc(sizeof(item)* 8);
    item vide;
    vide.type = 84;
    for (int i = 0; i < 8; i++) {
        vide.id = i;
        inventory[i] = vide;
    }
    return (inventory);
}

int add_elem_inventory(item *inventory, item objet)
{
    int i = 0;
    while (inventory[i].type != 84) {
        i = i + 1;
        if (i >= 8) {
            break;
        }
    }
    if (i >= 8)
        return (0);
    inventory[i] = objet;
    return 1;
}

int get_nb_items(item *inventory)
{
    int i = 0;
    while (inventory[i].type != 84) {
        i = i + 1;
        if (i >= 8) {
            break;
        }
    }
    return i;
}

int *init_other_slot_disable(int *selected, int num)
{
    int i = 0;
    while (i < 8) {
        if (selected[i] == 1 && i != num) {
            selected[i] = 0;
        }
        i = i + 1;
    }
    return (selected);
}

void print_slot(sfRenderWindow *window, el *slot, int *selected, item *inv, int num, int *list_selected)
{
    sfSprite_setPosition(slot -> sprite, slot -> pos);
    sfVector2f pos_slot = sfSprite_getPosition(slot -> sprite);
    sfVector2i pos_mouse = sfMouse_getPosition(window);
    sfSprite_setTexture(slot -> sprite, slot -> texture, sfTrue);
    sfFloatRect bounds = sfSprite_getGlobalBounds(slot -> sprite);
    if (sfFloatRect_contains(&bounds, pos_mouse.x, pos_mouse.y) && sfMouse_isButtonPressed(sfMouseLeft)) {
        *selected = 1;
        slot -> rect.left = 64;
    } else if ((sfMouse_isButtonPressed(sfMouseLeft) && (!sfFloatRect_contains(&bounds, pos_mouse.x, pos_mouse.y) && *selected == 1) && (pos_mouse.x < 1613 || pos_mouse.x > 1873) && (pos_mouse.y < 476 || pos_mouse.y > 552))) {
        *selected = 0; slot -> rect.left = 0;
    }
    if (list_selected[num] == 0)
        slot -> rect.left = 0;
    if (inv[num].type != 84) {
        inv[num].my_sprite.pos.y = pos_slot.y + 3;
        inv[num].my_sprite.pos.x = pos_slot.x + 3;
        sfVector2f scale = {3.5, 3.5};
        sfSprite_setScale(inv[num].my_sprite.sprite, scale);
        print_sprite(window, inv[num].my_sprite);
    }
    print_sprite(window, *slot);
}

void get_action_items(int type, player *ply, item objet, item *inv, int i, int *selected)
{
    if (type == 2) {
        if (objet.id == 2) {
            if (ply->life <= 65) {
                ply->life += 35;
            } else {
                ply->life = 100;
            }
            inv[i].type = 84;
            selected[i] = 0;
        }
        if (objet.id == 3) {
            if (ply->life <= 75) {
                ply->life += 15;
            } else {
                ply->life = 100;
            }
            inv[i].type = 84;
            selected[i] = 0;
        }
    } else if (type == 3) {
        if (objet.id == 4) {
            ply->boots = 1;
            inv[i].type = -84;
            selected[i] = 0;
        }
        if (objet.id == 1) {
            ply->ply_stat->attack += 5;
            inv[i].type = 84;
            selected[i] = 0;
        }
        if (objet.id == 5) {
            ply->ply_stat->defense += 5;
            inv[i].type = 84;
            selected[i] = 0;
        }
    }
}

void button_item_use(int type, item *inv, item objet, btn *button, sfRenderWindow *window, sfEvent event, player *ply, int i, int *selected)
{
    sfSprite_setPosition(button -> my_sprite.sprite, button -> my_sprite.pos);
    sfSprite_setTexture(button->my_sprite.sprite, button->my_sprite.texture, sfTrue);
    if (get_mouse_button(window, button->my_sprite) == 1) {
        if (button->type == 1)
            button->my_sprite.rect.left = button->my_sprite.rect.width;
        if (sfMouse_isButtonPressed(sfMouseLeft)) {
            get_action_items(type, ply, objet, inv, i, selected);
        }
    } else if (button->my_sprite.rect.left == button->my_sprite.rect.width)
        button->my_sprite.rect.left = 0;
    sfSprite_setTextureRect(button->my_sprite.sprite, button->my_sprite.rect);
    sfRenderWindow_drawSprite(window, button->my_sprite.sprite, NULL);
}

void print_info_items(sfRenderWindow *window, int *selected, el info_item, item *inv, sfEvent event, player *ply)
{
    int i = 0; int ok = 0;
    btn *btn_use = make_button(1, 60, 41);
    btn_use->my_sprite = init_element(1710, 490, 60, 41, "Pictures/content/btn_useittem.png");
    btn *btn_equip = make_button(1, 100, 41);
    btn_equip->my_sprite = init_element(1690, 490, 100, 41, "Pictures/content/btn_equipitem.png");
    while (i < 8) {
        if (selected[i] == 1) {
            ok = 1;
            break;
        }
        i = i + 1;
    }
    if (ok == 0)
        return;
    if (inv[i].type != 84) {
        print_sprite(window, info_item);
        print_items(window, inv, i);
        if (inv[i].type == 2) {
            button_item_use(2, inv, inv[i], btn_use, window, event, ply, i, selected);
        }
        if (inv[i].type == 3) {
            button_item_use(3, inv, inv[i], btn_equip, window, event, ply, i, selected);
        }
    }
}

char *take_str_desc(char *desc, int *indice)
{
    char *str = malloc(sizeof(char) * my_strlen(desc));
    int i = 0;
    while (desc[*indice] != '&' && desc[*indice] != '\0') {
        if (desc[*indice] == '&')
            break;
        str[i] = desc[*indice];
        i = i + 1; *indice = *indice + 1;
    }
    str[i] = '\0';
    return (str);
}

void print_items(sfRenderWindow *window, item *inv, int i)
{
    sfVector2f pos = {1615, 344};
    inv[i].logo_sprite.pos = pos;
    sfVector2f scale = {4, 4};
    sfSprite_setScale(inv[i].logo_sprite.sprite, scale);
    print_sprite(window, inv[i].logo_sprite);
    sfText *title_item = make_text(32, init_pos(1700, 348), 1, sfWhite);
    sfText_setString(title_item, inv[i].name);
    sfRenderWindow_drawText(window, title_item, NULL);
    sfText *desc_item = make_text(25, init_pos(1616, 426), 1, sfWhite);
    sfText *desc_item2 = make_text(25, init_pos(1616, 446), 1, sfWhite);
    int indice = 0;
    char *first_line = take_str_desc(inv[i].desc, &indice);
    indice++;
    char *second_line = take_str_desc(inv[i].desc, &indice);
    sfText_setString(desc_item, first_line);
    sfText_setString(desc_item2, second_line);
    sfRenderWindow_drawText(window, desc_item, NULL);
    sfRenderWindow_drawText(window, desc_item2, NULL);
}

void recup_inventory(item *list_item, item *plt_inv, infogame *gameinfos)
{
    if (gameinfos->my_items[0] == 'a')
        return;
    for (int i = 0; gameinfos->my_items[i]; i++) {
        add_elem_inventory(plt_inv, list_item[gameinfos->my_items[i] - 48]);
    }
}
