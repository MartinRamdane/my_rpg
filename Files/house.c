/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include "../Includes/my.h"

int house1(sfRenderWindow *window, infogame *gameinfos, statchar *stat, player *my_player, item *ply_inv)
{
    item *list_item = make_list_item();
    int *selected = fill_int_arr(8);
    el slot0 = init_element(1352, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot1 = init_element(1489, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot2 = init_element(1629, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot3 = init_element(1769, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot4 = init_element(1352, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot5 = init_element(1489, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot6 = init_element(1629, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot7 = init_element(1769, 193, 64, 64, "Pictures/content/cadreslot.png");
    sfVector2u size_window = {my_getnbr(gameinfos -> resolution), my_getnbr_pos(gameinfos -> resolution, 5)};
    sfRenderWindow_setSize(window, size_window);
    sfEvent event; c clocks = init_clocks();
    sfMusic_stop(gameinfos -> arr_music[0]);
    el map = init_element(0, 0, 1920, 1080, "Pictures/map.png");
    my_player->my_sprite->pos.x = 960; my_player->my_sprite->pos.y = 650;
    el house = init_element(0, 0, 1920, 1080, "Pictures/interieur_maison.png");
    el cadre = init_element(1440, 0, 480, 270, "Pictures/contour.png");
    el torche_1 = init_element(888, 404, 16, 16, "Pictures/torche_1.png");
    el torche_11 = init_element(968, 404, 16, 16, "Pictures/torche_1.png");
    el torche_111 = init_element(1032, 404, 16, 16, "Pictures/torche_1.png");
    el torche_2 = init_element(1064, 468, 16, 16, "Pictures/torche_2.png");
    el torche_22 = init_element(1064, 596, 16, 16, "Pictures/torche_2.png");
    el torche_3 = init_element(920, 660, 16, 16, "Pictures/torche_3.png");
    el torche_33 = init_element(984, 660, 16, 16, "Pictures/torche_3.png");
    el torche_4 = init_element(840, 468, 16, 16, "Pictures/torche_4.png");
    el torche_44 = init_element(840, 612, 16, 16, "Pictures/torche_4.png");
    el logohealth = init_element(24, 849, 64, 64, "Pictures/content/logohealth.png");
    el logostamina = init_element(24, 952, 64, 64, "Pictures/content/logostamina.png");
    el back_healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthbg.png");
    el cadre_healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthcadre.png");
    el healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthbar.png");
    el back_staminabar = init_element(101, 959, 400, 50, "Pictures/content/healthbg.png");
    el cadre_staminabar = init_element(101, 959, 400, 50, "Pictures/content/healthcadre.png");
    el staminabar = init_element(101, 959, 400, 50, "Pictures/content/staminabar.png");
    liste_colisions *liste = create_liste1();
    sfFloatRect rect_view = {0, 0, 1920, 1080};
    sfFloatRect rect_mini_view = {0, 0, 1920, 1080};
    sfFloatRect rect_mini_map = {0.75, 0, 0.25, 0.25};
    sfView *view = sfView_createFromRect(rect_view);
    sfVector2f center = {960, 650};
    sfView_setCenter(view, center);
    sfView *view_all = sfView_createFromRect(rect_view);
    sfView *mini_map = sfView_createFromRect(rect_mini_view);
    sfView_setCenter(mini_map, center);
    sfView *view_map = sfView_createFromRect(rect_view);
    sfVector2f pos = {960, 540}; int m = 0; float zoom = 1.0;
    el smoke = init_element(my_player->my_sprite->pos.x, my_player->my_sprite->pos.y, 16, 58, "Pictures/smoke_run_l.png");
    sfVector2f smoke_scale = {0.15, 0.15};
    sfSprite_setScale(smoke.sprite, smoke_scale);
    int if_run; int inv = 0; int up = 0;
    sfView_setViewport(mini_map, rect_mini_map); sfView_zoom(view, 0.20); int if_stamina = 0;
    sfView_zoom(mini_map, 0.50); sfRenderWindow_setFramerateLimit(window, gameinfos -> fps);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (sfKeyboard_isKeyPressed(gameinfos -> map) == sfTrue)
                m = 1;
            if (sfKeyboard_isKeyPressed(gameinfos -> inventory) == sfTrue && inv == 0) {
                inv = 1;
            }
            if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue && inv == 1) {
                inv = 0;
            }
        }
        if (my_player->my_sprite->pos.y >= 664 && my_player->my_sprite->pos.y <= 670 && my_player->my_sprite->pos.x >= 950 && my_player->my_sprite->pos.x <= 970) {
                gameinfos->h1 = 2;
                return 0;
        }
        sfRenderWindow_setView(window, view);
        healthbar.rect.width = my_player->life * 4;
        staminabar.rect.width = my_player->endurance * 4;
        if (my_player->endurance == 0)
            up = 1;
        if (inv == 0)
            if_run = move_view(mini_map, view, my_player, &clocks, liste, gameinfos, if_stamina, &smoke);
        if (if_run != 2)
            if_stamina = up_stamina(&staminabar, my_player, clocks.clock6, &up);
        stat->stamina = my_player->endurance;
        attack(my_player->my_sprite, &clocks, if_run, gameinfos);
        print_sprite(window, house);
        print_liste_colisions(window, liste);
        move_torche1(&torche_1, clocks.clock24);
        print_sprite(window, torche_1);
        move_torche11(&torche_11, clocks.clock25);
        print_sprite(window, torche_11);
        move_torche111(&torche_111, clocks.clock26);
        print_sprite(window, torche_111);
        move_torche2(&torche_2, clocks.clock27);
        print_sprite(window, torche_2);
        move_torche22(&torche_22, clocks.clock28);
        print_sprite(window, torche_22);
        move_torche3(&torche_3, clocks.clock29);
        print_sprite(window, torche_3);
        move_torche33(&torche_33, clocks.clock30);
        print_sprite(window, torche_33);
        move_torche4(&torche_4, clocks.clock31);
        print_sprite(window, torche_4);
        move_torche44(&torche_44, clocks.clock32);
        print_sprite(window, torche_44);
        print_sprite(window, *my_player->my_sprite);
        sfRenderWindow_setView(window, view_all);
        if (inv == 1) {
            el inventory = init_element(1294, 18, 600, 299, "Pictures/content/cadreinventaire.png");
            el perso = init_element(260, 150, 479, 622, "Pictures/content/infopersonnage.png");
            el info_item = init_element(1591, 326, 300, 250, "Pictures/content/cadreinfo.png");
            el ico_life = init_element(320, 461, 64, 64, "Pictures/content/icolife.png");
            el ico_defense = init_element(320, 536, 64, 64, "Pictures/content/icodefense.png");
            el ico_attak = init_element(320, 611, 64, 64, "Pictures/content/icoattak.png");
            el ico_stamina = init_element(546, 461, 64, 64, "Pictures/content/icostamina.png");
            el ico_crit = init_element(546, 536, 64, 64, "Pictures/content/icocrit.png");
            el ico_level = init_element(546, 611, 64, 64, "Pictures/content/icolevel.png");
            int x_text = 497 - (my_strlen(gameinfos->username) * 12);
            sfText *ply_name = make_text(48, init_pos(x_text, 160), 1, sfWhite);
            sfText_setString(ply_name, gameinfos->username);
            sfText *txt_life = make_text(32, init_pos(404, 475), 1, sfWhite);
            sfText *txt_defense = make_text(32, init_pos(404, 545), 1, sfWhite);
            sfText *txt_attak = make_text(32, init_pos(404, 627), 1, sfWhite);
            sfText *txt_stamina = make_text(32, init_pos(634, 475), 1, sfWhite);
            sfText *txt_crit = make_text(32, init_pos(634, 545), 1, sfWhite);
            sfText *txt_level = make_text(32, init_pos(634, 627), 1, sfWhite);
            sfText_setString(txt_life, my_itoi(stat->life));
            sfText_setString(txt_defense, my_itoi(stat->defense));
            sfText_setString(txt_attak, my_itoi(stat->attack));
            sfText_setString(txt_stamina, my_itoi(stat->stamina));
            sfText_setString(txt_crit, my_itoi(stat->crit));
            sfText_setString(txt_level, my_itoi(stat->level));
            print_sprite(window, inventory);
            print_sprite(window, perso);
            print_sprite(window, ico_life);
            print_sprite(window, ico_stamina);
            print_sprite(window, ico_defense);
            print_sprite(window, ico_crit);
            print_sprite(window, ico_level);
            print_sprite(window, ico_attak);
            print_slot(window, &slot0, &selected[0], ply_inv, 0, selected);
            print_slot(window, &slot1, &selected[1], ply_inv, 1, selected);
            print_slot(window, &slot2, &selected[2], ply_inv, 2, selected);
            print_slot(window, &slot3, &selected[3], ply_inv, 3, selected);
            print_slot(window, &slot4, &selected[4], ply_inv, 4, selected);
            print_slot(window, &slot5, &selected[5], ply_inv, 5, selected);
            print_slot(window, &slot6, &selected[6], ply_inv, 6, selected);
            print_slot(window, &slot7, &selected[7], ply_inv, 7, selected);
            sfRenderWindow_drawText(window, ply_name, NULL);
            sfRenderWindow_drawText(window, txt_life, NULL);
            sfRenderWindow_drawText(window, txt_defense, NULL);
            sfRenderWindow_drawText(window, txt_attak, NULL);
            sfRenderWindow_drawText(window, txt_stamina, NULL);
            sfRenderWindow_drawText(window, txt_crit, NULL);
            sfRenderWindow_drawText(window, txt_level, NULL);
            print_info_items(window, selected, info_item, ply_inv, event, my_player);
        }
        print_sprite(window, logohealth);
        print_sprite(window, logostamina);
        print_sprite(window, back_healthbar);
        print_sprite(window, healthbar);
        print_sprite(window, cadre_healthbar);
        print_sprite(window, back_staminabar);
        print_sprite(window, staminabar);
        print_sprite(window, cadre_staminabar);
        sfRenderWindow_display(window);
    }
    return 0;
}

int house2(sfRenderWindow *window, infogame *gameinfos, statchar *stat, player *my_player, item *ply_inv)
{
    item *list_item = make_list_item();
    int *selected = fill_int_arr(8);
    el slot0 = init_element(1352, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot1 = init_element(1489, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot2 = init_element(1629, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot3 = init_element(1769, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot4 = init_element(1352, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot5 = init_element(1489, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot6 = init_element(1629, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot7 = init_element(1769, 193, 64, 64, "Pictures/content/cadreslot.png");
    sfVector2u size_window = {my_getnbr(gameinfos -> resolution), my_getnbr_pos(gameinfos -> resolution, 5)};
    sfRenderWindow_setSize(window, size_window);
    sfEvent event; c clocks = init_clocks();
    sfMusic_stop(gameinfos -> arr_music[0]);
    el map = init_element(0, 0, 1920, 1080, "Pictures/map.png");
    my_player->my_sprite->pos.x = 960; my_player->my_sprite->pos.y = 650;
    el house = init_element(0, 0, 1920, 1080, "Pictures/interieur_maison.png");
    el cadre = init_element(1440, 0, 480, 270, "Pictures/contour.png");
    el torche_1 = init_element(888, 404, 16, 16, "Pictures/torche_1.png");
    el torche_11 = init_element(968, 404, 16, 16, "Pictures/torche_1.png");
    el torche_111 = init_element(1032, 404, 16, 16, "Pictures/torche_1.png");
    el torche_2 = init_element(1064, 468, 16, 16, "Pictures/torche_2.png");
    el torche_22 = init_element(1064, 596, 16, 16, "Pictures/torche_2.png");
    el torche_3 = init_element(920, 660, 16, 16, "Pictures/torche_3.png");
    el torche_33 = init_element(984, 660, 16, 16, "Pictures/torche_3.png");
    el torche_4 = init_element(840, 468, 16, 16, "Pictures/torche_4.png");
    el torche_44 = init_element(840, 612, 16, 16, "Pictures/torche_4.png");
    el logohealth = init_element(24, 849, 64, 64, "Pictures/content/logohealth.png");
    el logostamina = init_element(24, 952, 64, 64, "Pictures/content/logostamina.png");
    el back_healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthbg.png");
    el cadre_healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthcadre.png");
    el healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthbar.png");
    el back_staminabar = init_element(101, 959, 400, 50, "Pictures/content/healthbg.png");
    el cadre_staminabar = init_element(101, 959, 400, 50, "Pictures/content/healthcadre.png");
    el staminabar = init_element(101, 959, 400, 50, "Pictures/content/staminabar.png");
    liste_colisions *liste = create_liste1();
    sfFloatRect rect_view = {0, 0, 1920, 1080};
    sfFloatRect rect_mini_view = {0, 0, 1920, 1080};
    sfFloatRect rect_mini_map = {0.75, 0, 0.25, 0.25};
    sfView *view = sfView_createFromRect(rect_view);
    sfVector2f center = {960, 650};
    sfView_setCenter(view, center);
    sfView *view_all = sfView_createFromRect(rect_view);
    sfView *mini_map = sfView_createFromRect(rect_mini_view);
    sfView_setCenter(mini_map, center);
    sfView *view_map = sfView_createFromRect(rect_view);
    sfVector2f pos = {960, 540}; int m = 0; float zoom = 1.0;
    int if_run; int inv = 0; int up = 0;
    sfView_setViewport(mini_map, rect_mini_map); sfView_zoom(view, 0.20); int if_stamina = 0;
    sfView_zoom(mini_map, 0.50); sfRenderWindow_setFramerateLimit(window, gameinfos -> fps);
    el smoke = init_element(my_player->my_sprite->pos.x, my_player->my_sprite->pos.y, 16, 58, "Pictures/smoke_run_l.png");
    sfVector2f smoke_scale = {0.15, 0.15};
    sfSprite_setScale(smoke.sprite, smoke_scale);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (sfKeyboard_isKeyPressed(gameinfos -> map) == sfTrue)
                m = 1;
            if (sfKeyboard_isKeyPressed(gameinfos -> inventory) == sfTrue && inv == 0) {
                inv = 1;
            }
            if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue && inv == 1) {
                inv = 0;
            }
        }
        if (my_player->my_sprite->pos.y >= 664 && my_player->my_sprite->pos.y <= 670 && my_player->my_sprite->pos.x >= 950 && my_player->my_sprite->pos.x <= 970) {
                gameinfos->h2 = 2;
                return 0;
        }
        sfRenderWindow_setView(window, view);
        healthbar.rect.width = my_player->life * 4;
        staminabar.rect.width = my_player->endurance * 4;
        if (my_player->endurance == 0)
            up = 1;
        if (inv == 0)
            if_run = move_view(mini_map, view, my_player, &clocks, liste, gameinfos, if_stamina, &smoke);
        if (if_run != 2)
            if_stamina = up_stamina(&staminabar, my_player, clocks.clock6, &up);
        stat->stamina = my_player->endurance;
        attack(my_player->my_sprite, &clocks, if_run, gameinfos);
        print_liste_colisions(window, liste);
        print_sprite(window, house);
        move_torche1(&torche_1, clocks.clock24);
        print_sprite(window, torche_1);
        move_torche11(&torche_11, clocks.clock25);
        print_sprite(window, torche_11);
        move_torche111(&torche_111, clocks.clock26);
        print_sprite(window, torche_111);
        move_torche2(&torche_2, clocks.clock27);
        print_sprite(window, torche_2);
        move_torche22(&torche_22, clocks.clock28);
        print_sprite(window, torche_22);
        move_torche3(&torche_3, clocks.clock29);
        print_sprite(window, torche_3);
        move_torche33(&torche_33, clocks.clock30);
        print_sprite(window, torche_33);
        move_torche4(&torche_4, clocks.clock31);
        print_sprite(window, torche_4);
        move_torche44(&torche_44, clocks.clock32);
        print_sprite(window, torche_44);
        print_sprite(window, *my_player->my_sprite);
        sfRenderWindow_setView(window, view_all);
        if (inv == 1) {
            el inventory = init_element(1294, 18, 600, 299, "Pictures/content/cadreinventaire.png");
            el perso = init_element(260, 150, 479, 622, "Pictures/content/infopersonnage.png");
            el info_item = init_element(1591, 326, 300, 250, "Pictures/content/cadreinfo.png");
            el ico_life = init_element(320, 461, 64, 64, "Pictures/content/icolife.png");
            el ico_defense = init_element(320, 536, 64, 64, "Pictures/content/icodefense.png");
            el ico_attak = init_element(320, 611, 64, 64, "Pictures/content/icoattak.png");
            el ico_stamina = init_element(546, 461, 64, 64, "Pictures/content/icostamina.png");
            el ico_crit = init_element(546, 536, 64, 64, "Pictures/content/icocrit.png");
            el ico_level = init_element(546, 611, 64, 64, "Pictures/content/icolevel.png");
            int x_text = 497 - (my_strlen(gameinfos->username) * 12);
            sfText *ply_name = make_text(48, init_pos(x_text, 160), 1, sfWhite);
            sfText_setString(ply_name, gameinfos->username);
            sfText *txt_life = make_text(32, init_pos(404, 475), 1, sfWhite);
            sfText *txt_defense = make_text(32, init_pos(404, 545), 1, sfWhite);
            sfText *txt_attak = make_text(32, init_pos(404, 627), 1, sfWhite);
            sfText *txt_stamina = make_text(32, init_pos(634, 475), 1, sfWhite);
            sfText *txt_crit = make_text(32, init_pos(634, 545), 1, sfWhite);
            sfText *txt_level = make_text(32, init_pos(634, 627), 1, sfWhite);
            sfText_setString(txt_life, my_itoi(stat->life));
            sfText_setString(txt_defense, my_itoi(stat->defense));
            sfText_setString(txt_attak, my_itoi(stat->attack));
            sfText_setString(txt_stamina, my_itoi(stat->stamina));
            sfText_setString(txt_crit, my_itoi(stat->crit));
            sfText_setString(txt_level, my_itoi(stat->level));
            print_sprite(window, inventory);
            print_sprite(window, perso);
            print_sprite(window, ico_life);
            print_sprite(window, ico_stamina);
            print_sprite(window, ico_defense);
            print_sprite(window, ico_crit);
            print_sprite(window, ico_level);
            print_sprite(window, ico_attak);
            print_slot(window, &slot0, &selected[0], ply_inv, 0, selected);
            print_slot(window, &slot1, &selected[1], ply_inv, 1, selected);
            print_slot(window, &slot2, &selected[2], ply_inv, 2, selected);
            print_slot(window, &slot3, &selected[3], ply_inv, 3, selected);
            print_slot(window, &slot4, &selected[4], ply_inv, 4, selected);
            print_slot(window, &slot5, &selected[5], ply_inv, 5, selected);
            print_slot(window, &slot6, &selected[6], ply_inv, 6, selected);
            print_slot(window, &slot7, &selected[7], ply_inv, 7, selected);
            sfRenderWindow_drawText(window, ply_name, NULL);
            sfRenderWindow_drawText(window, txt_life, NULL);
            sfRenderWindow_drawText(window, txt_defense, NULL);
            sfRenderWindow_drawText(window, txt_attak, NULL);
            sfRenderWindow_drawText(window, txt_stamina, NULL);
            sfRenderWindow_drawText(window, txt_crit, NULL);
            sfRenderWindow_drawText(window, txt_level, NULL);
            print_info_items(window, selected, info_item, ply_inv, event, my_player);
        }
        print_sprite(window, logohealth);
        print_sprite(window, logostamina);
        print_sprite(window, back_healthbar);
        print_sprite(window, healthbar);
        print_sprite(window, cadre_healthbar);
        print_sprite(window, back_staminabar);
        print_sprite(window, staminabar);
        print_sprite(window, cadre_staminabar);
        sfRenderWindow_display(window);
    }
    return 0;
}

int house3(sfRenderWindow *window, infogame *gameinfos, statchar *stat, player *my_player, item *ply_inv)
{
    item *list_item = make_list_item();
    int *selected = fill_int_arr(8);
    el slot0 = init_element(1352, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot1 = init_element(1489, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot2 = init_element(1629, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot3 = init_element(1769, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot4 = init_element(1352, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot5 = init_element(1489, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot6 = init_element(1629, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot7 = init_element(1769, 193, 64, 64, "Pictures/content/cadreslot.png");
    sfVector2u size_window = {my_getnbr(gameinfos -> resolution), my_getnbr_pos(gameinfos -> resolution, 5)};
    sfRenderWindow_setSize(window, size_window);
    sfEvent event; c clocks = init_clocks();
    sfMusic_stop(gameinfos -> arr_music[0]);
    el map = init_element(0, 0, 1920, 1080, "Pictures/map.png");
    my_player->my_sprite->pos.x = 960; my_player->my_sprite->pos.y = 650;
    el house = init_element(0, 0, 1920, 1080, "Pictures/interieur_maison.png");
    el cadre = init_element(1440, 0, 480, 270, "Pictures/contour.png");
    el torche_1 = init_element(888, 404, 16, 16, "Pictures/torche_1.png");
    el torche_11 = init_element(968, 404, 16, 16, "Pictures/torche_1.png");
    el torche_111 = init_element(1032, 404, 16, 16, "Pictures/torche_1.png");
    el torche_2 = init_element(1064, 468, 16, 16, "Pictures/torche_2.png");
    el torche_22 = init_element(1064, 596, 16, 16, "Pictures/torche_2.png");
    el torche_3 = init_element(920, 660, 16, 16, "Pictures/torche_3.png");
    el torche_33 = init_element(984, 660, 16, 16, "Pictures/torche_3.png");
    el torche_4 = init_element(840, 468, 16, 16, "Pictures/torche_4.png");
    el torche_44 = init_element(840, 612, 16, 16, "Pictures/torche_4.png");
    el logohealth = init_element(24, 849, 64, 64, "Pictures/content/logohealth.png");
    el logostamina = init_element(24, 952, 64, 64, "Pictures/content/logostamina.png");
    el back_healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthbg.png");
    el cadre_healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthcadre.png");
    el healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthbar.png");
    el back_staminabar = init_element(101, 959, 400, 50, "Pictures/content/healthbg.png");
    el cadre_staminabar = init_element(101, 959, 400, 50, "Pictures/content/healthcadre.png");
    el staminabar = init_element(101, 959, 400, 50, "Pictures/content/staminabar.png");
    liste_colisions *liste = create_liste1();
    el smoke = init_element(my_player->my_sprite->pos.x, my_player->my_sprite->pos.y, 16, 58, "Pictures/smoke_run_l.png");
    sfVector2f smoke_scale = {0.15, 0.15};
    sfSprite_setScale(smoke.sprite, smoke_scale);
    sfFloatRect rect_view = {0, 0, 1920, 1080};
    sfFloatRect rect_mini_view = {0, 0, 1920, 1080};
    sfFloatRect rect_mini_map = {0.75, 0, 0.25, 0.25};
    sfView *view = sfView_createFromRect(rect_view);
    sfVector2f center = {960, 650};
    sfView_setCenter(view, center);
    sfView *view_all = sfView_createFromRect(rect_view);
    sfView *mini_map = sfView_createFromRect(rect_mini_view);
    sfView_setCenter(mini_map, center);
    sfView *view_map = sfView_createFromRect(rect_view);
    sfVector2f pos = {960, 540}; int m = 0; float zoom = 1.0;
    int if_run; int inv = 0; int up = 0;
    sfView_setViewport(mini_map, rect_mini_map); sfView_zoom(view, 0.20); int if_stamina = 0;
    sfView_zoom(mini_map, 0.50); sfRenderWindow_setFramerateLimit(window, gameinfos -> fps);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (sfKeyboard_isKeyPressed(gameinfos -> map) == sfTrue)
                m = 1;
            if (sfKeyboard_isKeyPressed(gameinfos -> inventory) == sfTrue && inv == 0) {
                inv = 1;
            }
            if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue && inv == 1) {
                inv = 0;
            }
        }
        if (my_player->my_sprite->pos.y >= 664 && my_player->my_sprite->pos.y <= 670 && my_player->my_sprite->pos.x >= 950 && my_player->my_sprite->pos.x <= 970) {
                gameinfos->h3 = 2;
                return 0;
        }
        sfRenderWindow_setView(window, view);
        healthbar.rect.width = my_player->life * 4;
        staminabar.rect.width = my_player->endurance * 4;
        if (my_player->endurance == 0)
            up = 1;
        if (inv == 0)
            if_run = move_view(mini_map, view, my_player, &clocks, liste, gameinfos, if_stamina, &smoke);
        if (if_run != 2)
            if_stamina = up_stamina(&staminabar, my_player, clocks.clock6, &up);
        stat->stamina = my_player->endurance;
        attack(my_player->my_sprite, &clocks, if_run, gameinfos);
        print_liste_colisions(window, liste);
        print_sprite(window, house);
        move_torche1(&torche_1, clocks.clock24);
        print_sprite(window, torche_1);
        move_torche11(&torche_11, clocks.clock25);
        print_sprite(window, torche_11);
        move_torche111(&torche_111, clocks.clock26);
        print_sprite(window, torche_111);
        move_torche2(&torche_2, clocks.clock27);
        print_sprite(window, torche_2);
        move_torche22(&torche_22, clocks.clock28);
        print_sprite(window, torche_22);
        move_torche3(&torche_3, clocks.clock29);
        print_sprite(window, torche_3);
        move_torche33(&torche_33, clocks.clock30);
        print_sprite(window, torche_33);
        move_torche4(&torche_4, clocks.clock31);
        print_sprite(window, torche_4);
        move_torche44(&torche_44, clocks.clock32);
        print_sprite(window, torche_44);
        print_sprite(window, *my_player->my_sprite);
        sfRenderWindow_setView(window, view_all);
        if (inv == 1) {
            el inventory = init_element(1294, 18, 600, 299, "Pictures/content/cadreinventaire.png");
            el perso = init_element(260, 150, 479, 622, "Pictures/content/infopersonnage.png");
            el info_item = init_element(1591, 326, 300, 250, "Pictures/content/cadreinfo.png");
            el ico_life = init_element(320, 461, 64, 64, "Pictures/content/icolife.png");
            el ico_defense = init_element(320, 536, 64, 64, "Pictures/content/icodefense.png");
            el ico_attak = init_element(320, 611, 64, 64, "Pictures/content/icoattak.png");
            el ico_stamina = init_element(546, 461, 64, 64, "Pictures/content/icostamina.png");
            el ico_crit = init_element(546, 536, 64, 64, "Pictures/content/icocrit.png");
            el ico_level = init_element(546, 611, 64, 64, "Pictures/content/icolevel.png");
            int x_text = 497 - (my_strlen(gameinfos->username) * 12);
            sfText *ply_name = make_text(48, init_pos(x_text, 160), 1, sfWhite);
            sfText_setString(ply_name, gameinfos->username);
            sfText *txt_life = make_text(32, init_pos(404, 475), 1, sfWhite);
            sfText *txt_defense = make_text(32, init_pos(404, 545), 1, sfWhite);
            sfText *txt_attak = make_text(32, init_pos(404, 627), 1, sfWhite);
            sfText *txt_stamina = make_text(32, init_pos(634, 475), 1, sfWhite);
            sfText *txt_crit = make_text(32, init_pos(634, 545), 1, sfWhite);
            sfText *txt_level = make_text(32, init_pos(634, 627), 1, sfWhite);
            sfText_setString(txt_life, my_itoi(stat->life));
            sfText_setString(txt_defense, my_itoi(stat->defense));
            sfText_setString(txt_attak, my_itoi(stat->attack));
            sfText_setString(txt_stamina, my_itoi(stat->stamina));
            sfText_setString(txt_crit, my_itoi(stat->crit));
            sfText_setString(txt_level, my_itoi(stat->level));
            print_sprite(window, inventory);
            print_sprite(window, perso);
            print_sprite(window, ico_life);
            print_sprite(window, ico_stamina);
            print_sprite(window, ico_defense);
            print_sprite(window, ico_crit);
            print_sprite(window, ico_level);
            print_sprite(window, ico_attak);
            print_slot(window, &slot0, &selected[0], ply_inv, 0, selected);
            print_slot(window, &slot1, &selected[1], ply_inv, 1, selected);
            print_slot(window, &slot2, &selected[2], ply_inv, 2, selected);
            print_slot(window, &slot3, &selected[3], ply_inv, 3, selected);
            print_slot(window, &slot4, &selected[4], ply_inv, 4, selected);
            print_slot(window, &slot5, &selected[5], ply_inv, 5, selected);
            print_slot(window, &slot6, &selected[6], ply_inv, 6, selected);
            print_slot(window, &slot7, &selected[7], ply_inv, 7, selected);
            sfRenderWindow_drawText(window, ply_name, NULL);
            sfRenderWindow_drawText(window, txt_life, NULL);
            sfRenderWindow_drawText(window, txt_defense, NULL);
            sfRenderWindow_drawText(window, txt_attak, NULL);
            sfRenderWindow_drawText(window, txt_stamina, NULL);
            sfRenderWindow_drawText(window, txt_crit, NULL);
            sfRenderWindow_drawText(window, txt_level, NULL);
            print_info_items(window, selected, info_item, ply_inv, event, my_player);
        }
        print_sprite(window, logohealth);
        print_sprite(window, logostamina);
        print_sprite(window, back_healthbar);
        print_sprite(window, healthbar);
        print_sprite(window, cadre_healthbar);
        print_sprite(window, back_staminabar);
        print_sprite(window, staminabar);
        print_sprite(window, cadre_staminabar);
        sfRenderWindow_display(window);
    }
    return 0;
}

int house4(sfRenderWindow *window, infogame *gameinfos, statchar *stat, player *my_player, item *ply_inv)
{
    item *list_item = make_list_item();
    int *selected = fill_int_arr(8);
    el slot0 = init_element(1352, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot1 = init_element(1489, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot2 = init_element(1629, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot3 = init_element(1769, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot4 = init_element(1352, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot5 = init_element(1489, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot6 = init_element(1629, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot7 = init_element(1769, 193, 64, 64, "Pictures/content/cadreslot.png");
    sfVector2u size_window = {my_getnbr(gameinfos -> resolution), my_getnbr_pos(gameinfos -> resolution, 5)};
    sfRenderWindow_setSize(window, size_window);
    sfEvent event; c clocks = init_clocks();
    sfMusic_stop(gameinfos -> arr_music[0]);
    el map = init_element(0, 0, 1920, 1080, "Pictures/map.png");
    my_player->my_sprite->pos.x = 960; my_player->my_sprite->pos.y = 650;
    el house = init_element(0, 0, 1920, 1080, "Pictures/interieur_maison.png");
    el cadre = init_element(1440, 0, 480, 270, "Pictures/contour.png");
    el torche_1 = init_element(888, 404, 16, 16, "Pictures/torche_1.png");
    el torche_11 = init_element(968, 404, 16, 16, "Pictures/torche_1.png");
    el torche_111 = init_element(1032, 404, 16, 16, "Pictures/torche_1.png");
    el torche_2 = init_element(1064, 468, 16, 16, "Pictures/torche_2.png");
    el torche_22 = init_element(1064, 596, 16, 16, "Pictures/torche_2.png");
    el torche_3 = init_element(920, 660, 16, 16, "Pictures/torche_3.png");
    el torche_33 = init_element(984, 660, 16, 16, "Pictures/torche_3.png");
    el torche_4 = init_element(840, 468, 16, 16, "Pictures/torche_4.png");
    el torche_44 = init_element(840, 612, 16, 16, "Pictures/torche_4.png");
    el logohealth = init_element(24, 849, 64, 64, "Pictures/content/logohealth.png");
    el logostamina = init_element(24, 952, 64, 64, "Pictures/content/logostamina.png");
    el back_healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthbg.png");
    el cadre_healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthcadre.png");
    el healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthbar.png");
    el back_staminabar = init_element(101, 959, 400, 50, "Pictures/content/healthbg.png");
    el cadre_staminabar = init_element(101, 959, 400, 50, "Pictures/content/healthcadre.png");
    el staminabar = init_element(101, 959, 400, 50, "Pictures/content/staminabar.png");
    liste_colisions *liste = create_liste1();
    el smoke = init_element(my_player->my_sprite->pos.x, my_player->my_sprite->pos.y, 16, 58, "Pictures/smoke_run_l.png");
    sfVector2f smoke_scale = {0.15, 0.15};
    sfSprite_setScale(smoke.sprite, smoke_scale);
    sfFloatRect rect_view = {0, 0, 1920, 1080};
    sfFloatRect rect_mini_view = {0, 0, 1920, 1080};
    sfFloatRect rect_mini_map = {0.75, 0, 0.25, 0.25};
    sfView *view = sfView_createFromRect(rect_view);
    sfVector2f center = {960, 650};
    sfView_setCenter(view, center);
    sfView *view_all = sfView_createFromRect(rect_view);
    sfView *mini_map = sfView_createFromRect(rect_mini_view);
    sfView_setCenter(mini_map, center);
    sfView *view_map = sfView_createFromRect(rect_view);
    sfVector2f pos = {960, 540}; int m = 0; float zoom = 1.0;
    int if_run; int inv = 0; int up = 0;
    sfView_setViewport(mini_map, rect_mini_map); sfView_zoom(view, 0.20); int if_stamina = 0;
    sfView_zoom(mini_map, 0.50); sfRenderWindow_setFramerateLimit(window, gameinfos -> fps);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (sfKeyboard_isKeyPressed(gameinfos -> map) == sfTrue)
                m = 1;
            if (sfKeyboard_isKeyPressed(gameinfos -> inventory) == sfTrue && inv == 0) {
                inv = 1;
            }
            if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue && inv == 1) {
                inv = 0;
            }
        }
        if (my_player->my_sprite->pos.y >= 664 && my_player->my_sprite->pos.y <= 670 && my_player->my_sprite->pos.x >= 950 && my_player->my_sprite->pos.x <= 970) {
                gameinfos->h4 = 2;
                return 0;
        }
        sfRenderWindow_setView(window, view);
        healthbar.rect.width = my_player->life * 4;
        staminabar.rect.width = my_player->endurance * 4;
        if (my_player->endurance == 0)
            up = 1;
        if (inv == 0)
            if_run = move_view(mini_map, view, my_player, &clocks, liste, gameinfos, if_stamina, &smoke);
        if (if_run != 2)
            if_stamina = up_stamina(&staminabar, my_player, clocks.clock6, &up);
        stat->stamina = my_player->endurance;
        attack(my_player->my_sprite, &clocks, if_run, gameinfos);
        print_liste_colisions(window, liste);
        print_sprite(window, house);
        move_torche1(&torche_1, clocks.clock24);
        print_sprite(window, torche_1);
        move_torche11(&torche_11, clocks.clock25);
        print_sprite(window, torche_11);
        move_torche111(&torche_111, clocks.clock26);
        print_sprite(window, torche_111);
        move_torche2(&torche_2, clocks.clock27);
        print_sprite(window, torche_2);
        move_torche22(&torche_22, clocks.clock28);
        print_sprite(window, torche_22);
        move_torche3(&torche_3, clocks.clock29);
        print_sprite(window, torche_3);
        move_torche33(&torche_33, clocks.clock30);
        print_sprite(window, torche_33);
        move_torche4(&torche_4, clocks.clock31);
        print_sprite(window, torche_4);
        move_torche44(&torche_44, clocks.clock32);
        print_sprite(window, torche_44);
        print_sprite(window, *my_player->my_sprite);
        sfRenderWindow_setView(window, view_all);
        if (inv == 1) {
            el inventory = init_element(1294, 18, 600, 299, "Pictures/content/cadreinventaire.png");
            el perso = init_element(260, 150, 479, 622, "Pictures/content/infopersonnage.png");
            el info_item = init_element(1591, 326, 300, 250, "Pictures/content/cadreinfo.png");
            el ico_life = init_element(320, 461, 64, 64, "Pictures/content/icolife.png");
            el ico_defense = init_element(320, 536, 64, 64, "Pictures/content/icodefense.png");
            el ico_attak = init_element(320, 611, 64, 64, "Pictures/content/icoattak.png");
            el ico_stamina = init_element(546, 461, 64, 64, "Pictures/content/icostamina.png");
            el ico_crit = init_element(546, 536, 64, 64, "Pictures/content/icocrit.png");
            el ico_level = init_element(546, 611, 64, 64, "Pictures/content/icolevel.png");
            int x_text = 497 - (my_strlen(gameinfos->username) * 12);
            sfText *ply_name = make_text(48, init_pos(x_text, 160), 1, sfWhite);
            sfText_setString(ply_name, gameinfos->username);
            sfText *txt_life = make_text(32, init_pos(404, 475), 1, sfWhite);
            sfText *txt_defense = make_text(32, init_pos(404, 545), 1, sfWhite);
            sfText *txt_attak = make_text(32, init_pos(404, 627), 1, sfWhite);
            sfText *txt_stamina = make_text(32, init_pos(634, 475), 1, sfWhite);
            sfText *txt_crit = make_text(32, init_pos(634, 545), 1, sfWhite);
            sfText *txt_level = make_text(32, init_pos(634, 627), 1, sfWhite);
            sfText_setString(txt_life, my_itoi(stat->life));
            sfText_setString(txt_defense, my_itoi(stat->defense));
            sfText_setString(txt_attak, my_itoi(stat->attack));
            sfText_setString(txt_stamina, my_itoi(stat->stamina));
            sfText_setString(txt_crit, my_itoi(stat->crit));
            sfText_setString(txt_level, my_itoi(stat->level));
            print_sprite(window, inventory);
            print_sprite(window, perso);
            print_sprite(window, ico_life);
            print_sprite(window, ico_stamina);
            print_sprite(window, ico_defense);
            print_sprite(window, ico_crit);
            print_sprite(window, ico_level);
            print_sprite(window, ico_attak);
            print_slot(window, &slot0, &selected[0], ply_inv, 0, selected);
            print_slot(window, &slot1, &selected[1], ply_inv, 1, selected);
            print_slot(window, &slot2, &selected[2], ply_inv, 2, selected);
            print_slot(window, &slot3, &selected[3], ply_inv, 3, selected);
            print_slot(window, &slot4, &selected[4], ply_inv, 4, selected);
            print_slot(window, &slot5, &selected[5], ply_inv, 5, selected);
            print_slot(window, &slot6, &selected[6], ply_inv, 6, selected);
            print_slot(window, &slot7, &selected[7], ply_inv, 7, selected);
            sfRenderWindow_drawText(window, ply_name, NULL);
            sfRenderWindow_drawText(window, txt_life, NULL);
            sfRenderWindow_drawText(window, txt_defense, NULL);
            sfRenderWindow_drawText(window, txt_attak, NULL);
            sfRenderWindow_drawText(window, txt_stamina, NULL);
            sfRenderWindow_drawText(window, txt_crit, NULL);
            sfRenderWindow_drawText(window, txt_level, NULL);
            print_info_items(window, selected, info_item, ply_inv, event, my_player);
        }
        print_sprite(window, logohealth);
        print_sprite(window, logostamina);
        print_sprite(window, back_healthbar);
        print_sprite(window, healthbar);
        print_sprite(window, cadre_healthbar);
        print_sprite(window, back_staminabar);
        print_sprite(window, staminabar);
        print_sprite(window, cadre_staminabar);
        sfRenderWindow_display(window);
    }
    return 0;
}

int cave(sfRenderWindow *window, infogame *gameinfos, statchar *stat, player *my_player, item *ply_inv)
{
    item *list_item = make_list_item();
    int *selected = fill_int_arr(8);
    el slot0 = init_element(1352, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot1 = init_element(1489, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot2 = init_element(1629, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot3 = init_element(1769, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot4 = init_element(1352, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot5 = init_element(1489, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot6 = init_element(1629, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot7 = init_element(1769, 193, 64, 64, "Pictures/content/cadreslot.png");
    sfVector2u size_window = {my_getnbr(gameinfos -> resolution), my_getnbr_pos(gameinfos -> resolution, 5)};
    sfRenderWindow_setSize(window, size_window);
    sfEvent event; c clocks = init_clocks();
    sfMusic_stop(gameinfos -> arr_music[0]);
    el map = init_element(0, 0, 1920, 1080, "Pictures/map.png");
    my_player->my_sprite->pos.x = 960; my_player->my_sprite->pos.y = 658;
    el cave = init_element(0, 0, 1920, 1080, "Pictures/interieur_cave.png");
    el cadre = init_element(1440, 0, 480, 270, "Pictures/contour.png");
    el tcave_4 = init_element(848, 444, 16, 16, "Pictures/torche_44.png");
    el tcave_44 = init_element(896, 540, 16, 16, "Pictures/torche_44.png");
    el tcave_444 = init_element(848, 636, 16, 16, "Pictures/torche_44.png");
    el tcave_1 = init_element(896, 396, 16, 16, "Pictures/torche_11.png");
    el tcave_11 = init_element(944, 396, 16, 16, "Pictures/torche_11.png");
    el tcave_2 = init_element(1056, 412, 16, 16, "Pictures/torche_22.png");
    el tcave_22 = init_element(1056, 460, 16, 16, "Pictures/torche_22.png");
    el tcave_222 = init_element(1056, 636, 16, 16, "Pictures/torche_22.png");
    el tcave_2222 = init_element(992, 604, 16, 16, "Pictures/torche_22.png");
    el logohealth = init_element(24, 849, 64, 64, "Pictures/content/logohealth.png");
    el logostamina = init_element(24, 952, 64, 64, "Pictures/content/logostamina.png");
    el back_healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthbg.png");
    el cadre_healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthcadre.png");
    el healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthbar.png");
    el back_staminabar = init_element(101, 959, 400, 50, "Pictures/content/healthbg.png");
    el cadre_staminabar = init_element(101, 959, 400, 50, "Pictures/content/healthcadre.png");
    el staminabar = init_element(101, 959, 400, 50, "Pictures/content/staminabar.png");
    el boss = init_element(948, 450, 32, 32, "Pictures/boss.png");
    el boss_fight = init_element(0, 0, 16, 16, "Pictures/boss_16.png");
    sfVector2f origin = {16, 16};
    sfVector2f scale_boss = {0.75, 0.75};
    sfSprite_scale(boss.sprite, scale_boss);
    liste_colisions *liste = create_liste2();
    sfFloatRect rect_view = {0, 0, 1920, 1080};
    sfFloatRect rect_mini_view = {0, 0, 1920, 1080};
    sfFloatRect rect_mini_map = {0.75, 0, 0.25, 0.25};
    sfView *view = sfView_createFromRect(rect_view);
    sfVector2f center = {960, 650};
    sfView_setCenter(view, center);
    sfView *view_all = sfView_createFromRect(rect_view);
    sfView *mini_map = sfView_createFromRect(rect_mini_view);
    sfView_setCenter(mini_map, center);
    sfView *view_map = sfView_createFromRect(rect_view);
    sfVector2f pos = {960, 540}; int m = 0; float zoom = 1.0;
    el smoke = init_element(my_player->my_sprite->pos.x, my_player->my_sprite->pos.y, 16, 58, "Pictures/smoke_run_l.png");
    sfVector2f smoke_scale = {0.15, 0.15};
    sfSprite_setScale(smoke.sprite, smoke_scale);
    int if_run; int inv = 0; int up = 0;
    sfView_setViewport(mini_map, rect_mini_map); sfView_zoom(view, 0.20); int if_stamina = 0;
    sfView_zoom(mini_map, 0.50); sfRenderWindow_setFramerateLimit(window, gameinfos -> fps);
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (sfKeyboard_isKeyPressed(gameinfos -> map) == sfTrue)
                m = 1;
            if (sfKeyboard_isKeyPressed(gameinfos -> inventory) == sfTrue && inv == 0) {
                inv = 1;
            }
            if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue && inv == 1) {
                inv = 0;
            }
        }
        sfFloatRect bounds = sfSprite_getGlobalBounds(boss.sprite);
        if (sfFloatRect_contains(&bounds, my_player->my_sprite->pos.x, my_player->my_sprite->pos.y - 5)) {
            png mob_boss; mob_boss.my_sprite = boss_fight; mob_boss.life = 200;
            fight(window, my_player, &mob_boss, gameinfos, ply_inv);
            if (my_player->life <= 0) {
                do_loose(window, gameinfos);
            } else {
                win(window, gameinfos);
            }
        }
        if (my_player->my_sprite->pos.y >= 672 && my_player->my_sprite->pos.y <= 678 && my_player->my_sprite->pos.x >= 950 && my_player->my_sprite->pos.x <= 970) {
                gameinfos->c1 = 2;
                return 0;
        }
        sfRenderWindow_setView(window, view);
        healthbar.rect.width = my_player->life * 4;
        staminabar.rect.width = my_player->endurance * 4;
        if (my_player->endurance == 0)
            up = 1;
        if (inv == 0)
            if_run = move_view(mini_map, view, my_player, &clocks, liste, gameinfos, if_stamina, &smoke);
        if (if_run != 2)
            if_stamina = up_stamina(&staminabar, my_player, clocks.clock6, &up);
        stat->stamina = my_player->endurance;
        attack(my_player->my_sprite, &clocks, if_run, gameinfos);
        print_sprite(window, cave);
        print_liste_colisions(window, liste);
        move_torche1(&tcave_4, clocks.clock24);
        print_sprite(window, tcave_4);
        move_torche11(&tcave_44, clocks.clock25);
        print_sprite(window, tcave_44);
        move_torche111(&tcave_444, clocks.clock26);
        print_sprite(window, tcave_444);
        move_torche2(&tcave_1, clocks.clock27);
        print_sprite(window, tcave_1);
        move_torche22(&tcave_11, clocks.clock28);
        print_sprite(window, tcave_11);
        move_torche3(&tcave_2, clocks.clock29);
        print_sprite(window, tcave_2);
        move_torche33(&tcave_22, clocks.clock30);
        print_sprite(window, tcave_22);
        move_torche4(&tcave_222, clocks.clock31);
        print_sprite(window, tcave_222);
        move_torche44(&tcave_2222, clocks.clock32);
        print_sprite(window, tcave_2222);
        print_sprite(window, *my_player->my_sprite);
        print_sprite(window, boss);
        sfRenderWindow_setView(window, view_all);
        if (inv == 1) {
            el inventory = init_element(1294, 18, 600, 299, "Pictures/content/cadreinventaire.png");
            el perso = init_element(260, 150, 479, 622, "Pictures/content/infopersonnage.png");
            el info_item = init_element(1591, 326, 300, 250, "Pictures/content/cadreinfo.png");
            el ico_life = init_element(320, 461, 64, 64, "Pictures/content/icolife.png");
            el ico_defense = init_element(320, 536, 64, 64, "Pictures/content/icodefense.png");
            el ico_attak = init_element(320, 611, 64, 64, "Pictures/content/icoattak.png");
            el ico_stamina = init_element(546, 461, 64, 64, "Pictures/content/icostamina.png");
            el ico_crit = init_element(546, 536, 64, 64, "Pictures/content/icocrit.png");
            el ico_level = init_element(546, 611, 64, 64, "Pictures/content/icolevel.png");
            int x_text = 497 - (my_strlen(gameinfos->username) * 12);
            sfText *ply_name = make_text(48, init_pos(x_text, 160), 1, sfWhite);
            sfText_setString(ply_name, gameinfos->username);
            sfText *txt_life = make_text(32, init_pos(404, 475), 1, sfWhite);
            sfText *txt_defense = make_text(32, init_pos(404, 545), 1, sfWhite);
            sfText *txt_attak = make_text(32, init_pos(404, 627), 1, sfWhite);
            sfText *txt_stamina = make_text(32, init_pos(634, 475), 1, sfWhite);
            sfText *txt_crit = make_text(32, init_pos(634, 545), 1, sfWhite);
            sfText *txt_level = make_text(32, init_pos(634, 627), 1, sfWhite);
            sfText_setString(txt_life, my_itoi(stat->life));
            sfText_setString(txt_defense, my_itoi(stat->defense));
            sfText_setString(txt_attak, my_itoi(stat->attack));
            sfText_setString(txt_stamina, my_itoi(stat->stamina));
            sfText_setString(txt_crit, my_itoi(stat->crit));
            sfText_setString(txt_level, my_itoi(stat->level));
            print_sprite(window, inventory);
            print_sprite(window, perso);
            print_sprite(window, ico_life);
            print_sprite(window, ico_stamina);
            print_sprite(window, ico_defense);
            print_sprite(window, ico_crit);
            print_sprite(window, ico_level);
            print_sprite(window, ico_attak);
            print_slot(window, &slot0, &selected[0], ply_inv, 0, selected);
            print_slot(window, &slot1, &selected[1], ply_inv, 1, selected);
            print_slot(window, &slot2, &selected[2], ply_inv, 2, selected);
            print_slot(window, &slot3, &selected[3], ply_inv, 3, selected);
            print_slot(window, &slot4, &selected[4], ply_inv, 4, selected);
            print_slot(window, &slot5, &selected[5], ply_inv, 5, selected);
            print_slot(window, &slot6, &selected[6], ply_inv, 6, selected);
            print_slot(window, &slot7, &selected[7], ply_inv, 7, selected);
            sfRenderWindow_drawText(window, ply_name, NULL);
            sfRenderWindow_drawText(window, txt_life, NULL);
            sfRenderWindow_drawText(window, txt_defense, NULL);
            sfRenderWindow_drawText(window, txt_attak, NULL);
            sfRenderWindow_drawText(window, txt_stamina, NULL);
            sfRenderWindow_drawText(window, txt_crit, NULL);
            sfRenderWindow_drawText(window, txt_level, NULL);
            print_info_items(window, selected, info_item, ply_inv, event, my_player);
        }
        print_sprite(window, logohealth);
        print_sprite(window, logostamina);
        print_sprite(window, back_healthbar);
        print_sprite(window, healthbar);
        print_sprite(window, cadre_healthbar);
        print_sprite(window, back_staminabar);
        print_sprite(window, staminabar);
        print_sprite(window, cadre_staminabar);
        sfRenderWindow_display(window);
    }
}
