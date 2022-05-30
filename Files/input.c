/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include "../Includes/my.h"

void print_case_key(sfRenderWindow *window, el *case_key, int *selected)
{
    sfVector2i pos_mouse = sfMouse_getPosition(window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(case_key -> sprite);
    if (sfFloatRect_contains(&bounds, pos_mouse.x, pos_mouse.y)) {
        case_key -> rect.left = 286;
        if (sfMouse_isButtonPressed(sfMouseLeft))
            *selected = 1;
    }
    else if (sfMouse_isButtonPressed(sfMouseLeft) || (!sfFloatRect_contains(&bounds, pos_mouse.x, pos_mouse.y) && *selected != 1)) {
        case_key -> rect.left = 0; *selected = 0;
    }
    print_sprite(window, *case_key);
}

int *list_btn_selected(void)
{
    int *list = malloc(sizeof(int) * 9);
    for (int i = 0; i < 9; i++) {
        list[i] = 0;
    }
    return (list);
}

void change_move(sfVector2f *pos_move, int touch, int x)
{
    char *key = malloc(sizeof(char) * 20);
    key = my_strcpy(key, get_char(touch));
    int len = my_strlen(key);
    if (len > 3)
        pos_move -> x = x - (len * 16);
    else if (len == 1)
        pos_move -> x = x;
    else if (len == 2)
        pos_move -> x = x - 20;
    else if (len == 3)
        pos_move -> x = x - 40;
}

int change_key(infogame *gameinfos, int selected, sfEvent event, sfText *text, sfVector2f pos_origin, int touch)
{
    if (event.type == sfEvtKeyPressed && selected == 1) {
        int i_key = get_key();
        char *key = malloc(sizeof(char) * 20);
        key = my_strcpy(key, get_char(i_key));
        if (i_key != touch) {
            int len = my_strlen(key);
            sfVector2f pos = {pos_origin.x, pos_origin.y};
            if (len > 3)
                pos.x = pos_origin.x - (len * 16);
            else if (len == 1)
                pos.x = pos_origin.x;
            else if (len == 2)
                pos.x = pos_origin.x - 20;
            else if (len == 3)
                pos.x = pos_origin.x - 40;
            sfText_setPosition(text, pos);
        }
        sfText_setString(text, key);
        return i_key;
    }
    return touch;
}

int input(sfRenderWindow *window, infogame *gameinfos, int a)
{
    sfEvent event;
    sfVector2f pos_move_forward = {746, 290};
    sfVector2f pos_orirgin_move_forward = {746, 290};
    sfVector2f pos_move_back = {746, 410};
    sfVector2f pos_orirgin_move_back = {746, 410};
    sfVector2f pos_move_right = {746, 530};
    sfVector2f pos_orirgin_move_right = {746, 530};
    sfVector2f pos_move_left = {746, 650};
    sfVector2f pos_orirgin_move_left = {746, 650};
    sfVector2f pos_move_map = {1606, 290};
    sfVector2f pos_orirgin_move_map = {1606, 290};
    sfVector2f pos_move_inventory = {1606, 410};
    sfVector2f pos_orirgin_move_inventory = {1606, 410};
    sfVector2f pos_move_pause = {1606, 530};
    sfVector2f pos_orirgin_move_pause = {1606, 530};
    sfVector2f pos_move_sprint = {1606, 650};
    sfVector2f pos_orirgin_move_sprint = {1606, 650};
    sfVector2f pos_move_hit = {1606, 770};
    sfVector2f pos_orirgin_move_hit = {1606, 770};
    btn *btn_quit = make_button(1, 200, 103);
    int *btn_selected = list_btn_selected();
    btn_quit -> my_sprite = init_button(init_pos(860, 950), btn_quit, "Pictures/content/btn_exit.png");
    el fond = init_element(0, 0, 1920, 1080, "Pictures/inputsettings.png");
    el move_forward = init_element(621, 292, 286, 100, "Pictures/casekey.png");
    el move_back = init_element(621, 412, 286, 100, "Pictures/casekey.png");
    el move_right = init_element(621, 532, 286, 100, "Pictures/casekey.png");
    el move_left = init_element(621, 652, 286, 100, "Pictures/casekey.png");
    el move_map = init_element(1482, 292, 286, 100, "Pictures/casekey.png");
    el move_inventory = init_element(1482, 412, 286, 100, "Pictures/casekey.png");
    el move_pause = init_element(1482, 532, 286, 100, "Pictures/casekey.png");
    el move_sprint = init_element(1482, 652, 286, 100, "Pictures/casekey.png");
    el move_hit = init_element(1482, 772, 286, 100, "Pictures/casekey.png");
    change_move(&pos_move_forward, gameinfos -> move_foreward, 746); change_move(&pos_move_back, gameinfos -> move_back, 746);
    change_move(&pos_move_right, gameinfos -> move_rigth, 746); change_move(&pos_move_left, gameinfos -> move_left, 746);
    change_move(&pos_move_map, gameinfos -> map, 1606); change_move(&pos_move_inventory, gameinfos -> inventory, 1606);
    change_move(&pos_move_pause, gameinfos -> pause, 1606); change_move(&pos_move_sprint, gameinfos -> sprint, 1606);
    change_move(&pos_move_hit, gameinfos -> hit, 1606);
    sfText *text_move_forward = make_text(75, pos_move_forward, 1, sfYellow);
    sfText *text_move_back = make_text(75, pos_move_back, 1, sfYellow);
    sfText *text_move_right = make_text(75, pos_move_right, 1, sfYellow);
    sfText *text_move_left = make_text(75, pos_move_left, 1, sfYellow);
    sfText *text_move_map = make_text(75, pos_move_map, 1, sfYellow);
    sfText *text_move_inventory = make_text(75, pos_move_inventory, 1, sfYellow);
    sfText *text_move_pause = make_text(75, pos_move_pause, 1, sfYellow);
    sfText *text_move_sprint = make_text(75, pos_move_sprint, 1, sfYellow);
    sfText *text_move_hit = make_text(75, pos_move_hit, 1, sfYellow);
    sfText_setString(text_move_forward, get_char(gameinfos -> move_foreward));
    sfText_setString(text_move_back, get_char(gameinfos -> move_back));
    sfText_setString(text_move_right, get_char(gameinfos -> move_rigth));
    sfText_setString(text_move_left, get_char(gameinfos -> move_left));
    sfText_setString(text_move_map, get_char(gameinfos -> map));
    sfText_setString(text_move_inventory, get_char(gameinfos -> inventory));
    sfText_setString(text_move_pause, get_char(gameinfos -> pause));
    sfText_setString(text_move_sprint, get_char(gameinfos -> sprint));
    sfText_setString(text_move_hit, get_char(gameinfos -> hit));
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            gameinfos -> move_foreward = change_key(gameinfos, btn_selected[0], event, text_move_forward, pos_orirgin_move_forward, gameinfos -> move_foreward);
            gameinfos -> move_back = change_key(gameinfos, btn_selected[1], event, text_move_back, pos_orirgin_move_back, gameinfos -> move_back);
            gameinfos -> move_rigth = change_key(gameinfos, btn_selected[2], event, text_move_right, pos_orirgin_move_right, gameinfos -> move_rigth);
            gameinfos -> move_left = change_key(gameinfos, btn_selected[3], event, text_move_left, pos_orirgin_move_left, gameinfos -> move_left);
            gameinfos -> map = change_key(gameinfos, btn_selected[4], event, text_move_map, pos_orirgin_move_map, gameinfos -> map);
            gameinfos -> inventory = change_key(gameinfos, btn_selected[5], event, text_move_inventory, pos_orirgin_move_inventory, gameinfos -> inventory);
            gameinfos -> pause = change_key(gameinfos, btn_selected[6], event, text_move_pause, pos_orirgin_move_pause, gameinfos -> pause);
            gameinfos -> sprint = change_key(gameinfos, btn_selected[7], event, text_move_sprint, pos_orirgin_move_sprint, gameinfos -> sprint);
            gameinfos -> hit = change_key(gameinfos, btn_selected[8], event, text_move_hit, pos_orirgin_move_hit, gameinfos -> hit);
        }
        print_sprite(window, fond);
        print_case_key(window, &move_forward, &btn_selected[0]);
        print_case_key(window, &move_back, &btn_selected[1]);
        print_case_key(window, &move_right, &btn_selected[2]);
        print_case_key(window, &move_left, &btn_selected[3]);
        print_case_key(window, &move_map, &btn_selected[4]);
        print_case_key(window, &move_inventory, &btn_selected[5]);
        print_case_key(window, &move_pause, &btn_selected[6]);
        print_case_key(window, &move_sprint, &btn_selected[7]);
        print_case_key(window, &move_hit, &btn_selected[8]);
        if (a == 1)
            print_btn(window, btn_quit, event, 5, gameinfos, 0);
        else {
            if (ex_btn(window, btn_quit, event, 0, gameinfos) == 1)
                return 0;
        }
        sfRenderWindow_drawText(window, text_move_forward, NULL);
        sfRenderWindow_drawText(window, text_move_back, NULL);
        sfRenderWindow_drawText(window, text_move_right, NULL);
        sfRenderWindow_drawText(window, text_move_left, NULL);
        sfRenderWindow_drawText(window, text_move_map, NULL);
        sfRenderWindow_drawText(window, text_move_inventory, NULL);
        sfRenderWindow_drawText(window, text_move_pause, NULL);
        sfRenderWindow_drawText(window, text_move_sprint, NULL);
        sfRenderWindow_drawText(window, text_move_hit, NULL);
        sfRenderWindow_display(window);
    }
    return 0;
}