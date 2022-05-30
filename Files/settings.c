/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include "../Includes/my.h"

void change_bar(sfRenderWindow *window, el *rond, sfEvent event, el bar)
{
    sfVector2i pos_mouse = sfMouse_getPosition(window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(bar.sprite);
    if (sfMouse_isButtonPressed(sfMouseLeft) && sfFloatRect_contains(&bounds, pos_mouse.x, pos_mouse.y)) {
        rond -> pos.x = pos_mouse.x;
    }
}

void change_fps(sfRenderWindow *window, sfEvent event, el *fps_select, el *fps_select2)
{
    sfVector2i pos_mouse = sfMouse_getPosition(window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(fps_select -> sprite);
    if (event.type == sfEvtMouseButtonPressed && sfFloatRect_contains(&bounds, pos_mouse.x, pos_mouse.y)) {
        if (fps_select -> rect.left == 0) {
            fps_select -> rect.left = 100;
            fps_select2 -> rect.left = 0;
        } else {
            fps_select -> rect.left = 0;
        }
    }
}

void print_arrow_left(sfRenderWindow *window, el *arrow, sfEvent event, text *resolution, infogame *gameinfos)
{
    sfVector2i pos_mouse = sfMouse_getPosition(window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(arrow -> sprite);
    sfVector2f pos_resolution = {1289, 624};
    if (sfFloatRect_contains(&bounds, pos_mouse.x, pos_mouse.y)) {
        arrow -> rect.left = 40;
    }
    else
        arrow -> rect.left = 0;
    if (event.type == sfEvtMouseButtonPressed && sfFloatRect_contains(&bounds, pos_mouse.x, pos_mouse.y)) {
        if (my_strstr(resolution->str, "2560x1600") == 0) {
            sfText_setString(resolution -> reso, "1920x1080");
            resolution -> str = "1920x1080";
            gameinfos -> resolution = "1920x1080";
            sfText_setPosition(resolution->reso, pos_resolution); return;
        }
        if (my_strstr(resolution->str, "1920x1080") == 0) {
            sfText_setString(resolution -> reso, "1600x900");
            resolution -> str = "1600x900";
            gameinfos -> resolution = "1600x900";
            pos_resolution.x += 13;
            sfText_setPosition(resolution->reso, pos_resolution); return;
        }
        if (my_strstr(resolution->str, "1600x900") == 0) {
            sfText_setString(resolution -> reso, "1280x720");
            resolution -> str = "1280x720";
            gameinfos -> resolution = "1280x720";
            pos_resolution.x += 13;
            sfText_setPosition(resolution->reso, pos_resolution); return;
        }
    }
}

void print_arrow_right(sfRenderWindow *window, el *arrow, sfEvent event, text *resolution, infogame *gameinfos)
{
    sfVector2i pos_mouse = sfMouse_getPosition(window);
    sfFloatRect bounds = sfSprite_getGlobalBounds(arrow -> sprite);
    sfVector2f pos_resolution = {1289, 624};
    if (sfFloatRect_contains(&bounds, pos_mouse.x, pos_mouse.y)) {
        arrow -> rect.left = 40;
    }
    else
        arrow -> rect.left = 0;
    if (event.type == sfEvtMouseButtonPressed && sfFloatRect_contains(&bounds, pos_mouse.x, pos_mouse.y)) {
        if (my_strstr(resolution->str, "1280x720") == 0) {
            sfText_setString(resolution -> reso, "1600x900");
            resolution -> str = "1600x900";
            gameinfos -> resolution = "1600x900";
            pos_resolution.x += 13;
            sfText_setPosition(resolution->reso, pos_resolution); return;
        }
        if (my_strstr(resolution->str, "1600x900") == 0) {
            sfText_setString(resolution -> reso, "1920x1080");
            resolution -> str = "1920x1080";
            gameinfos -> resolution = "1920x1080";
            sfText_setPosition(resolution->reso, pos_resolution); return;
        }
        if (my_strstr(resolution->str, "1920x1080") == 0) {
            sfText_setString(resolution -> reso, "2560x1600");
            resolution -> str = "2560x1600";
            gameinfos -> resolution = "2560x1600";
            sfText_setPosition(resolution->reso, pos_resolution); return;
        }
    }
}

int ex_btn(sfRenderWindow *window, btn *button, sfEvent event, int action, infogame *gameinfos)
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

int settings(sfRenderWindow *window, infogame *gameinfos, int a)
{
    sfEvent event;
    sfVector2f pos_resolution = {1289, 624};
    sfVector2f origin_rond = {45, 45};
    btn *btn_input = make_button(1, 250, 103);
    btn *btn_quit = make_button(1, 200, 103);
    el fond = init_element(0, 0, 1920, 1080, "Pictures/settings.png");
    el slide_bar_white = init_element(197, 412, 600, 20, "Pictures/slidebarwhite.png");
    el slide_bar_white2 = init_element(197, 652, 600, 20, "Pictures/slidebarwhite.png");
    el slide_bar_yellow = init_element(197, 412, 300, 20, "Pictures/slidebaryellow.png");
    el slide_bar_yellow2 = init_element(197, 652, 300, 20, "Pictures/slidebaryellow.png");
    el rond_blanc = init_element(gameinfos -> vol_music * 6 + (253 - 45) , 415, 90, 90, "Pictures/slidepoint.png");
    el rond_blanc2 = init_element(gameinfos -> vol_sound * 6 + (253 - 45), 659, 90, 90, "Pictures/slidepoint.png");
    sfSprite_setOrigin(rond_blanc.sprite, origin_rond);
    sfSprite_setOrigin(rond_blanc2.sprite, origin_rond);
    el fpsselect = init_element(1367, 348, 100, 100, "Pictures/fpsselect.png");
    el fpsselect2 = init_element(1715, 348, 100, 100, "Pictures/fpsselect.png");
    if (gameinfos -> fps == 30)
        fpsselect.rect.left = 100;
    else
        fpsselect2.rect.left = 100;
    el arrow_left = init_element(1205, 645, 40, 68, "Pictures/resoleft.png");
    el arrow_right = init_element(1669, 645, 40, 68, "Pictures/resoright.png");
    text my_reso;
    my_reso.reso = make_text(75, pos_resolution, 1, sfYellow);
    sfText_setString(my_reso.reso, gameinfos -> resolution); my_reso.str = gameinfos -> resolution;
    btn_input -> my_sprite = init_button(init_pos(650, 950), btn_input, "Pictures/btn_input.png");
    btn_quit -> my_sprite = init_button(init_pos(1060, 950), btn_quit, "Pictures/btn_quit.png");
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            change_fps(window, event, &fpsselect, &fpsselect2);
            change_fps(window, event, &fpsselect2, &fpsselect);
            print_arrow_left(window, &arrow_left, event, &my_reso, gameinfos);
            print_arrow_right(window, &arrow_right, event, &my_reso, gameinfos);
        }
        change_bar(window, &rond_blanc, event, slide_bar_white);
        change_bar(window, &rond_blanc2, event, slide_bar_white2);
        slide_bar_yellow.rect.width = rond_blanc.pos.x - 253 + 45;
        slide_bar_yellow2.rect.width = rond_blanc2.pos.x - 253 + 45;
        gameinfos -> vol_music = slide_bar_yellow.rect.width / 6;
        gameinfos -> vol_sound = slide_bar_yellow2.rect.width / 6;
        sfMusic_setVolume(gameinfos -> arr_music[0], gameinfos -> vol_music);
        if (fpsselect.rect.left == 100)
            gameinfos -> fps = 30;
        else
            gameinfos -> fps = 60;
        print_sprite(window, fond);
        print_sprite(window, slide_bar_white);
        print_sprite(window, slide_bar_white2);
        print_sprite(window, slide_bar_yellow);
        print_sprite(window, slide_bar_yellow2);
        print_sprite(window, rond_blanc);
        print_sprite(window, rond_blanc2);
        print_sprite(window, fpsselect);
        print_sprite(window, fpsselect2);
        print_sprite(window, arrow_left);
        print_sprite(window, arrow_right);
        sfRenderWindow_drawText(window, my_reso.reso, NULL);
        print_btn(window, btn_input, event, 6, gameinfos, 0);
        if (a == 1)
            print_btn(window, btn_quit, event, 5, gameinfos, 0);
        else {
            if (ex_btn(window, btn_quit, event, 0, gameinfos) == 1)
                return 0;
        }
        sfRenderWindow_display(window);
    }
    return 0;
}