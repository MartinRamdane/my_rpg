/*
** EPITECH PROJECT, 2021
** B-MUL-200-MAR-2-1-myrpg-martin.ramdane
** File description:
** inter_pnj.c
*/

#include "../Includes/my.h"

int spawn_ennemy(el pnj, c *clocks, sfRenderWindow *window, el player)
{
    if (player.pos.y >= 692 && player.pos.x >= 338 && player.pos.x <= 1120) {
        return 1;
    } else
        return 0;
}

int ia_enemy(el *ennemy, c *clocks, el *player, sfRenderWindow *window)
{
    print_sprite(window, *ennemy);
    if (ennemy->pos.x < player->pos.x + 6) {
        ennemy->texture = sfTexture_createFromFile("Pictures/sorcier_walk_r.png", NULL);
        move_pnj(ennemy, clocks->clock10);
        ennemy->pos.x = ennemy->pos.x + 1;
        if (ennemy->pos.y < player->pos.y + 4) {
            ennemy->texture = sfTexture_createFromFile("Pictures/sorcier_walk_d.png", NULL);
            move_pnj(ennemy, clocks->clock10);
            ennemy->pos.y = ennemy->pos.y + 1;
        } else if (ennemy->pos.y > player->pos.y + 4) {
            ennemy->texture = sfTexture_createFromFile("Pictures/sorcier_walk_u.png", NULL);
            move_pnj(ennemy, clocks->clock10);
            ennemy->pos.y = ennemy->pos.y - 1;
        }
    } else if (ennemy->pos.x > player->pos.x + 6) {
        ennemy->texture = sfTexture_createFromFile("Pictures/sorcier _walk_l.png", NULL);
        move_pnj(ennemy, clocks->clock10);
        ennemy->pos.x = ennemy->pos.x - 1;
         if (ennemy->pos.y < player->pos.y + 4) {
            ennemy->texture = sfTexture_createFromFile("Pictures/sorcier_walk_d.png", NULL);
            move_pnj(ennemy, clocks->clock10);
            ennemy->pos.y = ennemy->pos.y + 1;
        } else if (ennemy->pos.y > player->pos.y + 4) {
            ennemy->texture = sfTexture_createFromFile("Pictures/sorcier_walk_u.png", NULL);
            move_pnj(ennemy, clocks->clock10);
            ennemy->pos.y = ennemy->pos.y - 1;
        }
    } else if (ennemy->pos.y < player->pos.y + 4) {
        ennemy->texture = sfTexture_createFromFile("Pictures/sorcier_walk_d.png", NULL);
        move_pnj(ennemy, clocks->clock10);
        ennemy->pos.y = ennemy->pos.y + 1;
    } else if (ennemy->pos.y > player->pos.y + 4) {
        ennemy->texture = sfTexture_createFromFile("Pictures/sorcier_walk_u.png", NULL);
        move_pnj(ennemy, clocks->clock10);
        ennemy->pos.y = ennemy->pos.y - 1;
    }
    if (ennemy->pos.x == player->pos.x + 6 && ennemy->pos.y == player->pos.y + 4)
        return 1;
    else
        return 0;
}

quest do_lord_pnj2(sfRenderWindow *window, infogame *gameinfos, el map, player my_player, el pnj, sfView *view, sfView *mini_view, el cadre, int *nb_quest)
{
    sfEvent event;
    sfFloatRect rect_view = {0, 0, 1920, 1080};
    sfView *view_all = sfView_createFromRect(rect_view);
    el dialogue = init_element(80, 700, 1758, 337, "Pictures/dialoguex1.png");
    int i = 0, j = 0, y = 0, len = 53 + my_strlen(gameinfos->username);
    sfClock *clock = sfClock_create();
    sfClock *clock2 = sfClock_create();
    sfClock *clock3 = sfClock_create();
    float scds = 0.06;
    char *txt = malloc(sizeof(char) * 6);
    sfVector2f pos = {120, 740};
    sfText *texte = make_text(47, pos, 1, sfWhite);
    txt = my_strcpy(txt, "Hey ");
    txt = my_strcat(txt, gameinfos -> username);
    txt = my_strcat(txt, ", in this strange land, many dangers are present.");
    sfText_setString(texte, get_txt_pos(txt, i));
    char *txt2 = malloc(sizeof(char) * 59);
    sfVector2f pos2 = {120, 800};
    sfText *texte2 = make_text(45, pos2, 1, sfWhite);
    txt2 = my_strcpy(txt2, "If you want to survive you will surely need a life potion.");
    sfText_setString(texte2, get_txt_pos(txt2, j));
    char *txt3 = malloc(sizeof(char) * 41);
    sfVector2f pos3 = {120, 860};
    sfText *texte3 = make_text(45, pos3, 1, sfWhite);
    txt3 = my_strcpy(txt3, "Find the wizard and fight him to get it !");
    sfText_setString(texte3, get_txt_pos(txt3, y));
    sfVector2f pos_quest_title = {1460, 280};
    sfVector2f pos_quest = {1460, 340};
        if (*nb_quest > 0) {
        pos_quest.y += 150 * *nb_quest;
        pos_quest_title.y += 150 * *nb_quest;
    }
    quest my_quest;
    my_quest.pos_title = pos_quest_title;
    my_quest.pos_txt = pos_quest;
    my_quest.null = 0;
    my_quest.text = make_text(30, my_quest.pos_txt, 1, sfWhite);
    sfText_setString(my_quest.text, "Find the wizard and fight it.");
    my_quest.title = make_text(40, my_quest.pos_title, 1, sfYellow);
    sfText_setString(my_quest.title, "Defeat the wizard");
    int continuer = 0; *nb_quest += 1;
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEnter) && continuer == 1)
                return my_quest;
            if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEnter))
                scds = 0.001;
        }
        sfRenderWindow_setView(window, view);
        print_sprite(window, map);
        print_sprite(window, *my_player.my_sprite);
        print_sprite(window, pnj);
        sfRenderWindow_setView(window, mini_view);
        print_sprite(window, map);
        print_sprite(window, *my_player.my_sprite);
        print_sprite(window, pnj);
        sfRenderWindow_setView(window, view_all);
        print_sprite(window, cadre);
        print_sprite(window, dialogue);
        if (*nb_quest > 0) {
            pos_quest.y += 150 * *nb_quest;
            pos_quest_title.y += 150 * *nb_quest;
        }
        if (i < len) {
            anim_txt(clock, txt, &i, texte, scds);
            sfRenderWindow_drawText(window, texte, NULL);
        }
        else if (i >= len && j < 58) {
            anim_txt(clock2, txt2, &j, texte2, scds);
            sfRenderWindow_drawText(window, texte, NULL);
            sfRenderWindow_drawText(window, texte2, NULL);
        }
        else {
            anim_txt(clock3, txt3, &y, texte3, scds);
            sfRenderWindow_drawText(window, texte, NULL);
            sfRenderWindow_drawText(window, texte2, NULL);
            sfRenderWindow_drawText(window, texte3, NULL);
        }
        if (y == 41)
            continuer = 1;
        sfRenderWindow_display(window);
    }
    return (my_quest);
}

quest do_lord_pnj(sfRenderWindow *window, infogame *gameinfos, el map, player my_player, el pnj, sfView *view, sfView *mini_view, el cadre, int *nb_quest)
{
    sfEvent event;
    sfFloatRect rect_view = {0, 0, 1920, 1080};
    sfView *view_all = sfView_createFromRect(rect_view);
    el dialogue = init_element(80, 700, 1758, 337, "Pictures/dialoguex1.png");
    int i = 0, j = 0, y = 0, len = 51 + my_strlen(gameinfos->username);
    sfClock *clock = sfClock_create();
    sfClock *clock2 = sfClock_create();
    sfClock *clock3 = sfClock_create();
    float scds = 0.06;
    char *txt = malloc(sizeof(char) * 6);
    sfVector2f pos = {120, 740};
    sfText *texte = make_text(47, pos, 1, sfWhite);
    txt = my_strcpy(txt, gameinfos -> username);
    txt = my_strcat(txt, " ! Aren't you tired of beingout of breath so fast ?");
    sfText_setString(texte, get_txt_pos(txt, i));
    char *txt2 = malloc(sizeof(char) * 63);
    sfVector2f pos2 = {120, 800};
    sfText *texte2 = make_text(45, pos2, 1, sfWhite);
    txt2 = my_strcpy(txt2, "If you want to run faster you need the magic boots.");
    sfText_setString(texte2, get_txt_pos(txt2, j));
    char *txt3 = malloc(sizeof(char) * 49);
    sfVector2f pos3 = {120, 860};
    sfText *texte3 = make_text(45, pos3, 1, sfWhite);
    txt3 = my_strcpy(txt3, "They were last seen near the forest. Find them !");
    sfText_setString(texte3, get_txt_pos(txt3, y));
    quest my_quest;
    my_quest.null = 0;
    sfVector2f pos_quest_title = {1460, 280};
    sfVector2f pos_quest = {1460, 340};
    if (*nb_quest > 0) {
        pos_quest.y += 150 * *nb_quest;
        pos_quest_title.y += 150 * *nb_quest;
    }
    my_quest.pos_title = pos_quest_title;
    my_quest.pos_txt = pos_quest;
    my_quest.text = make_text(30, my_quest.pos_txt, 1, sfWhite);
    sfText_setString(my_quest.text, "Find them in the forest.");
    my_quest.title = make_text(40, my_quest.pos_title, 1, sfYellow);
    sfText_setString(my_quest.title, "Find the magic boots");
    int continuer = 0; *nb_quest += 1;
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEnter) && continuer == 1)
                return my_quest;
            if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEnter))
                scds = 0.001;
        }
        sfRenderWindow_setView(window, view);
        print_sprite(window, map);
        print_sprite(window, *my_player.my_sprite);
        print_sprite(window, pnj);
        sfRenderWindow_setView(window, mini_view);
        print_sprite(window, map);
        print_sprite(window, *my_player.my_sprite);
        print_sprite(window, pnj);
        sfRenderWindow_setView(window, view_all);
        print_sprite(window, cadre);
        print_sprite(window, dialogue);
        if (i < len) {
            anim_txt(clock, txt, &i, texte, scds);
            sfRenderWindow_drawText(window, texte, NULL);
        }
        else if (i >= len && j < 62) {
            anim_txt(clock2, txt2, &j, texte2, scds);
            sfRenderWindow_drawText(window, texte, NULL);
            sfRenderWindow_drawText(window, texte2, NULL);
        }
        else {
            anim_txt(clock3, txt3, &y, texte3, scds);
            sfRenderWindow_drawText(window, texte, NULL);
            sfRenderWindow_drawText(window, texte2, NULL);
            sfRenderWindow_drawText(window, texte3, NULL);
        }
        if (y == 48)
            continuer = 1;
        sfRenderWindow_display(window);
    }
    return (my_quest);
}

quest do_lord_pnj3(sfRenderWindow *window, infogame *gameinfos, el map, player my_player, el pnj, sfView *view, sfView *mini_view, el cadre, int *nb_quest)
{
    sfEvent event;
    sfFloatRect rect_view = {0, 0, 1920, 1080};
    sfView *view_all = sfView_createFromRect(rect_view);
    el dialogue = init_element(80, 700, 1758, 337, "Pictures/dialoguex1.png");
    int i = 0, j = 0, y = 0, len = 37 + my_strlen(gameinfos->username);
    sfClock *clock = sfClock_create();
    sfClock *clock2 = sfClock_create();
    sfClock *clock3 = sfClock_create();
    float scds = 0.06;
    char *txt = malloc(sizeof(char) * 4);
    sfVector2f pos = {120, 740};
    sfText *texte = make_text(47, pos, 1, sfWhite);
    txt = my_strcpy(txt, "Oh ");
    txt = my_strcat(txt, gameinfos -> username);
    txt = my_strcat(txt, " ! I see that you are rather weak.");
    sfText_setString(texte, get_txt_pos(txt, i));
    char *txt2 = malloc(sizeof(char) * 43);
    sfVector2f pos2 = {120, 800};
    sfText *texte2 = make_text(45, pos2, 1, sfWhite);
    txt2 = my_strcpy(txt2, "Maybe you need an armor to strengthen you.");
    sfText_setString(texte2, get_txt_pos(txt2, j));
    char *txt3 = malloc(sizeof(char) * 38);
    sfVector2f pos3 = {120, 860};
    sfText *texte3 = make_text(45, pos3, 1, sfWhite);
    txt3 = my_strcpy(txt3, "Find the blob and beat it to get it !");
    sfText_setString(texte3, get_txt_pos(txt3, y));
    sfVector2f pos_quest_title = {1460, 280};
    sfVector2f pos_quest = {1460, 340};
        if (*nb_quest > 0) {
        pos_quest.y += 150 * *nb_quest;
        pos_quest_title.y += 150 * *nb_quest;
    }
    quest my_quest;
    my_quest.pos_title = pos_quest_title;
    my_quest.pos_txt = pos_quest;
    my_quest.null = 0;
    my_quest.text = make_text(30, my_quest.pos_txt, 1, sfWhite);
    sfText_setString(my_quest.text, "Find the blob and fight it.");
    my_quest.title = make_text(40, my_quest.pos_title, 1, sfYellow);
    sfText_setString(my_quest.title, "Defeat the blob");
    int continuer = 0; *nb_quest += 1;
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEnter) && continuer == 1)
                return my_quest;
            if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEnter))
                scds = 0.001;
        }
        sfRenderWindow_setView(window, view);
        print_sprite(window, map);
        print_sprite(window, *my_player.my_sprite);
        print_sprite(window, pnj);
        sfRenderWindow_setView(window, mini_view);
        print_sprite(window, map);
        print_sprite(window, *my_player.my_sprite);
        print_sprite(window, pnj);
        sfRenderWindow_setView(window, view_all);
        print_sprite(window, cadre);
        print_sprite(window, dialogue);
        if (i < len) {
            anim_txt(clock, txt, &i, texte, scds);
            sfRenderWindow_drawText(window, texte, NULL);
        }
        else if (i >= len && j < 42) {
            anim_txt(clock2, txt2, &j, texte2, scds);
            sfRenderWindow_drawText(window, texte, NULL);
            sfRenderWindow_drawText(window, texte2, NULL);
        }
        else {
            anim_txt(clock3, txt3, &y, texte3, scds);
            sfRenderWindow_drawText(window, texte, NULL);
            sfRenderWindow_drawText(window, texte2, NULL);
            sfRenderWindow_drawText(window, texte3, NULL);
        }
        if (y == 41)
            continuer = 1;
        sfRenderWindow_display(window);
    }
    return (my_quest);
}

quest do_lord_pnj4(sfRenderWindow *window, infogame *gameinfos, el map, player my_player, el pnj, sfView *view, sfView *mini_view, el cadre, int *nb_quest)
{
    sfEvent event;
    sfFloatRect rect_view = {0, 0, 1920, 1080};
    sfView *view_all = sfView_createFromRect(rect_view);
    el dialogue = init_element(80, 700, 1758, 337, "Pictures/dialoguex1.png");
    int i = 0, j = 0, y = 0, len = 46 + my_strlen(gameinfos->username);
    sfClock *clock = sfClock_create();
    sfClock *clock2 = sfClock_create();
    sfClock *clock3 = sfClock_create();
    float scds = 0.06;
    char *txt = malloc(sizeof(char) * 4);
    sfVector2f pos = {120, 740};
    sfText *texte = make_text(47, pos, 1, sfWhite);
    txt = my_strcpy(txt, "Hello ");
    txt = my_strcat(txt, gameinfos -> username);
    txt = my_strcat(txt, ", I think if you want to do more damage,");
    sfText_setString(texte, get_txt_pos(txt, i));
    char *txt2 = malloc(sizeof(char) * 22);
    sfVector2f pos2 = {120, 800};
    sfText *texte2 = make_text(45, pos2, 1, sfWhite);
    txt2 = my_strcpy(txt2, "you should use a sword.");
    sfText_setString(texte2, get_txt_pos(txt2, j));
    char *txt3 = malloc(sizeof(char) * 43);
    sfVector2f pos3 = {120, 860};
    sfText *texte3 = make_text(45, pos3, 1, sfWhite);
    txt3 = my_strcpy(txt3, "A sword was hidden near the beach, find it!");
    sfText_setString(texte3, get_txt_pos(txt3, y));
    sfVector2f pos_quest_title = {1460, 280};
    sfVector2f pos_quest = {1460, 340};
        if (*nb_quest > 0) {
        pos_quest.y += 150 * *nb_quest;
        pos_quest_title.y += 150 * *nb_quest;
    }
    quest my_quest;
    my_quest.null = 0;
    my_quest.pos_title = pos_quest_title;
    my_quest.pos_txt = pos_quest;
    my_quest.text = make_text(30, my_quest.pos_txt, 1, sfWhite);
    sfText_setString(my_quest.text, "Find the sword on the beach.");
    my_quest.title = make_text(40, my_quest.pos_title, 1, sfYellow);
    sfText_setString(my_quest.title, "Find the sword");
    int continuer = 0; *nb_quest += 1;
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEnter) && continuer == 1)
                return my_quest;
            if (event.type == sfEvtKeyPressed && sfKeyboard_isKeyPressed(sfKeyEnter))
                scds = 0.001;
        }
        sfRenderWindow_setView(window, view);
        print_sprite(window, map);
        print_sprite(window, *my_player.my_sprite);
        print_sprite(window, pnj);
        sfRenderWindow_setView(window, mini_view);
        print_sprite(window, map);
        print_sprite(window, *my_player.my_sprite);
        print_sprite(window, pnj);
        sfRenderWindow_setView(window, view_all);
        print_sprite(window, cadre);
        print_sprite(window, dialogue);
        if (i < len) {
            anim_txt(clock, txt, &i, texte, scds);
            sfRenderWindow_drawText(window, texte, NULL);
        }
        else if (i >= len && j < 21) {
            anim_txt(clock2, txt2, &j, texte2, scds);
            sfRenderWindow_drawText(window, texte, NULL);
            sfRenderWindow_drawText(window, texte2, NULL);
        }
        else {
            anim_txt(clock3, txt3, &y, texte3, scds);
            sfRenderWindow_drawText(window, texte, NULL);
            sfRenderWindow_drawText(window, texte2, NULL);
            sfRenderWindow_drawText(window, texte3, NULL);
        }
        if (y == 41)
            continuer = 1;
        sfRenderWindow_display(window);
    }
    return (my_quest);
}

void inter_pnj(sfRenderWindow *window, el player, el *png, dialogues *d)
{
    el button_e = init_element(png->pos.x - 12, png->pos.y - 25, 35, 36, "Pictures/button_e.png");
    sfVector2f scale = {0.25, 0.25}; int a = 0;
    sfSprite_setScale(button_e.sprite, scale);
    if ((player.pos.x >= png->pos.x - 25 && player.pos.x <= png->pos.x + 30)
        && (player.pos.y >= png->pos.y - 20 && player.pos.y <= png->pos.y + 30)) {
        print_sprite(window, button_e);
        d->a = 1; a = 1;
    }
    if (d->a == 1 && sfKeyboard_isKeyPressed(sfKeyE) && a == 1) {
        png -> quest = 1;
        png->pnj_ac = 1;
        d->a = 0;
    }
}
