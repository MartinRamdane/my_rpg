/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include "../Includes/my.h"

int *fill_int_arr(int taille)
{
    int *arr = malloc(sizeof(int) * taille);
    for (int i = 0; i < taille; i++) {
        arr[i] = 0;
    }
    return (arr);
}

void print_quest(sfRenderWindow *window, int nb_quest, quest my_quest1, quest my_quest2, quest my_quest3, quest my_quest4)
{
    if (nb_quest > 0) {
        if (my_quest1.null == 0) {
            sfRenderWindow_drawText(window, my_quest1.text, NULL);
            sfRenderWindow_drawText(window, my_quest1.title, NULL);
        }
        if (my_quest2.null == 0) {
            sfRenderWindow_drawText(window, my_quest2.text, NULL);
            sfRenderWindow_drawText(window, my_quest2.title, NULL);
        }
        if (my_quest3.null == 0) {
            sfRenderWindow_drawText(window, my_quest3.text, NULL);
            sfRenderWindow_drawText(window, my_quest3.title, NULL);
        }
        if (my_quest4.null == 0) {
            sfRenderWindow_drawText(window, my_quest4.text, NULL);
            sfRenderWindow_drawText(window, my_quest4.title, NULL);
        }
    }
}

int game(sfRenderWindow *window, infogame *gameinfos, statchar *stat)
{
    item *list_item = make_list_item();
    item *ply_inv = make_inventory();
    int *selected = fill_int_arr(8);
    recup_inventory(list_item, ply_inv, gameinfos);
    gameinfos->arr_music[2] = play_sound("music/musicgame.ogg", gameinfos->vol_music);
    sfMusic_setLoop(gameinfos->arr_music[2], sfTrue); sfMusic_setVolume(gameinfos->arr_music[2], gameinfos->vol_music);
    sfMusic_play(gameinfos->arr_music[2]);
    el slot0 = init_element(1352, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot1 = init_element(1489, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot2 = init_element(1629, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot3 = init_element(1769, 76, 64, 64, "Pictures/content/cadreslot.png");
    el slot4 = init_element(1352, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot5 = init_element(1489, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot6 = init_element(1629, 193, 64, 64, "Pictures/content/cadreslot.png");
    el slot7 = init_element(1769, 193, 64, 64, "Pictures/content/cadreslot.png");
    sfEvent event; c clocks = init_clocks();
    sfMusic_stop(gameinfos -> arr_music[0]);
    el map = init_element(0, 0, 1920, 1080, "Pictures/map.png");
    el el_player = init_element(gameinfos->pos_player_x, gameinfos->pos_player_y, 16, 16, "Pictures/walk_r.png");
    player my_player; my_player.my_sprite = &el_player; my_player.life = stat->life;
    my_player.endurance = stat->stamina; my_player.ply_stat = stat;
    el cadre = init_element(1440, 0, 480, 270, "Pictures/contour.png");
    el rect_quest = init_element(1440, 270, 480, 0, "Pictures/content/rect_quest.png");
    int nb_quest = 0;
    el pnj = init_element(630, 400, 16, 16, "Pictures/princ_walk_d.png");
    pnj.pnj_ac = 0;
    el pnj2 = init_element(1600, 750, 16, 16, "Pictures/princ_walk_d.png");
    pnj2.pnj_ac = 0;
    el pnj3 = init_element(200, 450, 16, 16, "Pictures/dog_walk_d.png");
    pnj3.pnj_ac = 0;
    el dog2 = init_element(1400, 300, 16, 16, "Pictures/dog_walk_d.png");
    dog2.pnj_ac = 0;
    el water = init_element(592, 176, 272, 64, "Pictures/anim_water.png");
    el water2 = init_element(688, 368, 223, 48, "Pictures/anim_water2.png");
    el cascade = init_element(688, 240, 80, 128, "Pictures/cascade.png");
    el cave_open = init_element(496, 576, 16, 16, "Pictures/g_open.png");
    el logohealth = init_element(24, 849, 64, 64, "Pictures/content/logohealth.png");
    el logostamina = init_element(24, 952, 64, 64, "Pictures/content/logostamina.png");
    el back_healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthbg.png");
    el cadre_healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthcadre.png");
    el healthbar = init_element(101, 859, 400, 50, "Pictures/content/healthbar.png");
    el back_staminabar = init_element(101, 959, 400, 50, "Pictures/content/healthbg.png");
    el cadre_staminabar = init_element(101, 959, 400, 50, "Pictures/content/healthcadre.png");
    el staminabar = init_element(101, 959, 400, 50, "Pictures/content/staminabar.png");
    el mer = init_element(0, 1013, 1920, 67, "Pictures/anime_mer.png");
    liste_colisions *liste = create_liste();
    water2.rect.left = 223;
    el smoke = init_element(el_player.pos.x, el_player.pos.y, 16, 58, "Pictures/smoke_run_l.png");
    sfVector2f smoke_scale = {0.15, 0.15};
    sfSprite_setScale(smoke.sprite, smoke_scale);
    el sorcier = init_element(830, 730, 16, 16, "Pictures/sorcier_walk_d.png");
    sfVector2f origine2 = {15, 13}; sfSprite_setOrigin(pnj.sprite, origine2);
    el blob = init_element(140, 920, 16, 16, "Pictures/anime_blob.png");
    sfSprite_setOrigin(blob.sprite, origine2);
    sfSprite_setOrigin(pnj2.sprite, origine2);
    sfSprite_setOrigin(pnj3.sprite, origine2);
    sfSprite_setOrigin(dog2.sprite, origine2);
    sfSprite_setOrigin(sorcier.sprite, origine2);
    sfVector2f origin = {8, 8}; sfSprite_setOrigin(el_player.sprite, origin);
    sfFloatRect rect_view = {0, 0, 1920, 1080};
    sfFloatRect rect_mini_view = {0, 0, 1920, 1080};
    sfFloatRect rect_mini_map = {0.75, 0, 0.25, 0.25};
    sfView *view = sfView_createFromRect(rect_view);
    sfVector2f center = {gameinfos->pos_player_x, gameinfos->pos_player_y};
    sfView_setCenter(view, center);
    sfView *view_all = sfView_createFromRect(rect_view);
    sfView *mini_map = sfView_createFromRect(rect_mini_view);
    sfView_setCenter(mini_map, center);
    sfView *view_map = sfView_createFromRect(rect_view);
    sfVector2f pos = {960, 540}; int m = 0; float zoom = 1.0; int up = 0;
    dialogues d1; dialogues d2; dialogues d3; dialogues d4;
    dialogues d; sfVector2f start_pnj =  {pnj.pos.x, pnj.pos.y};
    sfVector2f start_ennemy = {sorcier.pos.x, sorcier.pos.y};
    quest my_quest1; quest my_quest2; quest my_quest3; quest my_quest4;
    my_quest1.null = 1; my_quest2.null = 1; my_quest3.null = 1; my_quest4.null = 1;
    get_quest(gameinfos, &my_quest1, &my_quest2, &my_quest3, &my_quest4, &pnj, &pnj2, &pnj3, &dog2, &nb_quest);
    rect_quest.rect.height = nb_quest * 150;
    int if_run; int inv = 0;
    sfVector2f scale = {0.75, 0.75};
    el boots  = init_element(1765, 230, 16, 16, "Pictures/item/boots.png");
    sfVector2f or = {8, 8}; sfSprite_scale(boots.sprite, scale);
    sfSprite_setOrigin(boots.sprite, or);
    el shield  = init_element(1140, 990, 16, 16, "Pictures/item/sword.png");
    sfSprite_setOrigin(shield.sprite, or); sfSprite_scale(shield.sprite, scale);
    sfView_setViewport(mini_map, rect_mini_map); sfView_zoom(view, 0.20); int if_stamina = 0;
    sfView_zoom(mini_map, 0.50); sfRenderWindow_setFramerateLimit(window, gameinfos -> fps);
    sfVector2f pos_quest_title = {1460, 280};
    sfVector2f pos_quest = {1460, 340};
    quest my_quest_boss;
    my_quest_boss.pos_title = pos_quest_title;
    my_quest_boss.pos_txt = pos_quest;
    my_quest_boss.text = make_text(30, my_quest_boss.pos_txt, 1, sfWhite);
    sfText_setString(my_quest_boss.text, "Find the cave that was opened");
    my_quest_boss.title = make_text(40, my_quest_boss.pos_title, 1, sfYellow);
    sfText_setString(my_quest_boss.title, "Fight the boss");
    png mob;
    int f = 0, i = 0, old_i = i;
    ordre_quest ordre_quest;
    ordre_quest.quest1 = 0;
    ordre_quest.quest2 = 0;
    ordre_quest.quest3 = 0;
    ordre_quest.quest4 = 0;
    my_player.ply_stat = malloc(sizeof(statchar));
    my_player.ply_stat->attack = stat->attack; my_player.ply_stat->defense = stat->defense; my_player.ply_stat->level = stat->level;
    my_player.ply_stat->stamina = stat->stamina; my_player.ply_stat->crit = stat->crit; my_player.const_stamina = stat->stamina;
    my_player.life = stat -> life; my_player.boots = 0; gameinfos->boss = 0;
    while (sfRenderWindow_isOpen(window)) {
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                gameinfos->pos_player_x = el_player.pos.x;
                gameinfos->pos_player_y = el_player.pos.y;
                stat->life = my_player.life;
                stat->stamina = my_player.endurance;
                if (get_nb_items(ply_inv) != 0) {
                    free(gameinfos->my_items);
                    gameinfos->my_items = malloc(sizeof(char) * (get_nb_items(ply_inv) + 1));
                    for (int i = 0; i < get_nb_items(ply_inv); i++)
                        gameinfos->my_items[i] = (ply_inv[i].id - 1) + 48;
                }
                do_save(gameinfos, stat);
                sfRenderWindow_close(window);
            }
            change_perso(&el_player, event);
            if (sfKeyboard_isKeyPressed(gameinfos -> map) == sfTrue)
                m = 1;
            if (sfKeyboard_isKeyPressed(sfKeyEscape) == sfTrue && inv == 1) {
                inv = 0;
            }
            if (sfKeyboard_isKeyPressed(gameinfos -> inventory) == sfTrue && inv == 0) {
                inv = 1;
            }
            if (sfKeyboard_isKeyPressed(gameinfos -> pause) == sfTrue) {
                gameinfos->pos_player_x = el_player.pos.x;
                gameinfos->pos_player_y = el_player.pos.y;
                stat->life = my_player.life;
                stat->stamina = my_player.endurance;
                free(gameinfos->my_items);
                gameinfos->my_items = malloc(sizeof(char) * (get_nb_items(ply_inv) + 1));
                for (int i = 0; i < get_nb_items(ply_inv); i++)
                    gameinfos->my_items[i] = (ply_inv[i].id - 1) + 48;
                do_save(gameinfos, stat);
                sfMusic_pause(gameinfos->arr_music[2]);
                do_pause(window, gameinfos);
                sfVector2u size_w = {my_getnbr(gameinfos -> resolution), my_getnbr_pos(gameinfos -> resolution, 5)};
                sfRenderWindow_setSize(window, size_w); sfRenderWindow_setFramerateLimit(window, gameinfos -> fps);
                sfMusic_setVolume(gameinfos->arr_music[2], gameinfos->vol_music);
                sfMusic_play(gameinfos->arr_music[2]);
            }
        }
        if (m == 1) {
            do_map(window, map, el_player, &m, event, view_map, &zoom, gameinfos, pnj, pnj2, pnj3, dog2);
        } else {
            sfRenderWindow_clear(window, sfBlack);
            if (gameinfos->h1 == 2) {
                    el_player.texture = sfTexture_createFromFile("Pictures/walk_d.png", NULL);
                    el_player.pos.y = 581;
                    el_player.pos.x = 1456;
                    sfVector2f center = {1456, 581};
                    sfVector2f mcenter = {1441, 460};
                    sfView_setCenter(view, center);
                    sfView_setCenter(mini_map, mcenter);
                    gameinfos->h1 = 0;
            }
            if (gameinfos->h2 == 2) {
                    el_player.texture = sfTexture_createFromFile("Pictures/walk_d.png", NULL);
                    el_player.pos.y = 822;
                    el_player.pos.x = 1881;
                    sfVector2f center = {1728, 822};
                    sfVector2f mcenter = {1441, 822};
                    sfView_setCenter(view, center);
                    sfView_setCenter(mini_map, mcenter);
                    gameinfos->h2 = 0;
            }
            if (gameinfos->h3 == 2) {
                    el_player.texture = sfTexture_createFromFile("Pictures/walk_d.png", NULL);
                    el_player.pos.y = 790;
                    el_player.pos.x = 1416;
                    sfVector2f center = {1416, 790};
                    sfVector2f mcenter = {1441, 822};
                    sfView_setCenter(view, center);
                    sfView_setCenter(mini_map, mcenter);
                    gameinfos->h3 = 0;
            }
            if (gameinfos->h4 == 2) {
                    el_player.texture = sfTexture_createFromFile("Pictures/walk_d.png", NULL);
                    el_player.pos.y = 325;
                    el_player.pos.x = 1672;
                    sfVector2f center = {1672, 325};
                    sfVector2f mcenter = {1441, 325};
                    sfView_setCenter(view, center);
                    sfView_setCenter(mini_map, mcenter);
                    gameinfos->h4 = 0;
            }
            if (gameinfos->c1 == 2) {
                el_player.texture = sfTexture_createFromFile("Pictures/walk_d.png", NULL);
                el_player.pos.y = 597;
                el_player.pos.x = 504;
                sfVector2f center = {504, 597};
                sfView_setCenter(view, center);
                gameinfos->c1 = 0;
            }
            if (el_player.pos.y >= 577 && el_player.pos.y <= 579 && el_player.pos.x >= 1455 && el_player.pos.x <= 1457) {
                gameinfos->h1 = 1;
                if (gameinfos->h1 == 1) {
                    house1(window, gameinfos, stat, &my_player, ply_inv);
                }
            }
            if (el_player.pos.y >= 818 && el_player.pos.y <= 820 && el_player.pos.x >= 1880 && el_player.pos.x <= 1882) {
                gameinfos->h2 = 1;
                if (gameinfos->h2 == 1) {
                    house2(window, gameinfos, stat, &my_player, ply_inv);
                }
            }
            if (el_player.pos.y >= 786 && el_player.pos.y <= 788 && el_player.pos.x >= 1415 && el_player.pos.x <= 1417) {
                gameinfos->h3 = 1;
                if (gameinfos->h3 == 1) {
                    house3(window, gameinfos, stat, &my_player, ply_inv);
                }
            }
            if (el_player.pos.y >= 322 && el_player.pos.y <= 324 && el_player.pos.x >= 1671 && el_player.pos.x <= 1673) {
                gameinfos->h4 = 1;
                if (gameinfos->h4 == 1) {
                    house4(window, gameinfos, stat, &my_player, ply_inv);
                }
            }
            sfRenderWindow_setView(window, view);
            healthbar.rect.width = my_player.life * 4;
            staminabar.rect.width = my_player.endurance * 4;
            if (my_player.endurance == 0)
                up = 1;
            if (inv == 0)
                if_run = move_view(mini_map, view, &my_player, &clocks, liste, gameinfos, if_stamina, &smoke);
            if (if_run != 2)
                if_stamina = up_stamina(&staminabar, &my_player, clocks.clock6, &up);
            stat->stamina = my_player.endurance;
            attack(&el_player, &clocks, if_run, gameinfos);
            print_sprite(window, map);
            if (gameinfos->boss == 4)
                print_sprite(window, cave_open);
            print_liste_colisions(window, liste);
            move_water(&water, clocks.clock3, 272);
            print_sprite(window, water);
            move_water2(&water2, clocks.clock4, 0);
            print_sprite(window, water2);
            move_cascade(&cascade, clocks.clock5);
            print_sprite(window, cascade);
            move_mer(&mer, clocks.clock21);
            print_sprite(window, mer);
            if (if_run == 2 && el_player.dir != DOWN) {
                print_sprite(window, smoke);
            }
            print_sprite(window, el_player);
            print_sprite(window, pnj);
            print_sprite(window, pnj2); print_sprite(window, pnj3);
            print_sprite(window, dog2);
            if (pnj.quest != 1)
                inter_pnj(window, el_player, &pnj, &d1);
            if (pnj2.quest != 1)
                inter_pnj(window, el_player, &pnj2, &d2);
            if (pnj3.quest != 1)
                inter_pnj(window, el_player, &pnj3, &d3);
            if (dog2.quest != 1)
                inter_pnj(window, el_player, &dog2, &d4);
            if (my_quest1.null == 0) {
                if (inter_objet(window, &boots, *my_player.my_sprite) == 1) {
                    add_elem_inventory(ply_inv, list_item[3]);
                    rect_quest.rect.height -= 150;
                    my_quest1.null = 1;
                    nb_quest -= 1;
                    i -= 1;
                    gameinfos->my_quests[0] = 0;
                    gameinfos->boss = gameinfos->boss + 1;
                }
                print_sprite(window, boots);
            }
            if (my_quest4.null == 0) {
                if (inter_objet(window, &shield, *my_player.my_sprite) == 1) {
                    add_elem_inventory(ply_inv, list_item[0]);
                    rect_quest.rect.height -= 150;
                    my_quest4.null = 1;
                    nb_quest -= 1;
                    i -= 1;
                    gameinfos->my_quests[0] = 0;
                    gameinfos->boss = gameinfos->boss + 1;
                }
                print_sprite(window, shield);
            }
            if (my_quest2.null == 0) {
                print_sprite(window, sorcier);
                int ennemy = spawn_ennemy(sorcier, &clocks, window, el_player);
                int enemy_col = ad_colisions_enemy(&sorcier, liste, el_player);
                if (ennemy == 1) {
                    if (enemy_col != 1)
                        f = ia_enemy(&sorcier, &clocks, &el_player, window);
                    if (f == 1) {
                        png mob_sorcerer; mob_sorcerer.my_sprite = sorcier; mob_sorcerer.life = 125;
                        mob_sorcerer.my_sprite.texture = sfTexture_createFromFile("Pictures/sorcier_walk_d.png", NULL);
                        int fight_result = fight(window, &my_player, &mob_sorcerer, gameinfos, ply_inv);
                        if (fight_result == 0) {
                            my_quest2.null = 1;
                            my_player.ply_stat->level = my_player.ply_stat->level + 1;
                            my_player.ply_stat->life = my_player.ply_stat->life + 5;
                            my_player.life = my_player.life + 5;
                            my_player.ply_stat->attack = my_player.ply_stat->attack + 10;
                        }
                        rect_quest.rect.height -= 150;
                        nb_quest -= 1;
                        i -= 1;
                        gameinfos->my_quests[1] = 0;
                        add_elem_inventory(ply_inv, list_item[1]);
                        gameinfos->boss = gameinfos->boss + 1;
                    }
                }
            }
            if (my_quest3.null == 0) {
                print_sprite(window, blob);
                move_blob(&blob, clocks.clock18);
                sfFloatRect bounds = sfSprite_getGlobalBounds(blob.sprite);
                if (sfFloatRect_contains(&bounds, el_player.pos.x, el_player.pos.y)) {
                    png mob_blob; mob_blob.my_sprite = blob; mob_blob.life = 100;
                    fight(window, &my_player, &mob_blob, gameinfos, ply_inv);
                    rect_quest.rect.height -= 150;
                    my_quest3.null = 1;
                    my_player.ply_stat->level = my_player.ply_stat->level + 1;
                    my_player.ply_stat->life = my_player.ply_stat->life + 5;
                    my_player.life = my_player.life + 5;
                    my_player.ply_stat->attack = my_player.ply_stat->attack + 10;
                    nb_quest -= 1;
                    i -= 1;
                    gameinfos->my_quests[2] = 0;
                    add_elem_inventory(ply_inv, list_item[4]);
                    gameinfos->boss = gameinfos->boss + 1;
                }
            }
            if (my_quest3.null == 0) {
                print_sprite(window, blob);
                move_blob(&blob, clocks.clock18);
                sfFloatRect bounds = sfSprite_getGlobalBounds(blob.sprite);
                if (sfFloatRect_contains(&bounds, el_player.pos.x, el_player.pos.y)) {
                    png mob_blob; mob_blob.my_sprite = blob; mob_blob.life = 75;
                    fight(window, &my_player, &mob_blob, gameinfos, ply_inv);
                    rect_quest.rect.height -= 150;
                    my_quest3.null = 1;
                    nb_quest -= 1;
                    i -= 1;
                    gameinfos->my_quests[2] = 0;
                    add_elem_inventory(ply_inv, list_item[4]);
                    gameinfos->boss = gameinfos->boss + 1;
                }
            }
            if (my_player.life <= 0)
                do_loose(window, gameinfos);
            sfRenderWindow_setView(window, mini_map);
            print_sprite(window, map); print_sprite(window, el_player);
            move_water(&water, clocks.clock3, 272);
            print_sprite(window, water);
            move_water2(&water2, clocks.clock4, 0);
            print_sprite(window, water2);
            move_cascade(&cascade, clocks.clock5);
            print_sprite(window, cascade);
            print_sprite(window, pnj);
            print_sprite(window, pnj2); print_sprite(window, pnj3);
            if (my_quest2.null == 0)
                print_sprite(window, sorcier);
            sfRenderWindow_setView(window, view_all);
            print_sprite(window, logohealth);
            print_sprite(window, logostamina);
            print_sprite(window, back_healthbar);
            print_sprite(window, healthbar);
            print_sprite(window, cadre_healthbar);
            print_sprite(window, back_staminabar);
            print_sprite(window, staminabar);
            print_sprite(window, cadre_staminabar);
            print_sprite(window, cadre);
            print_sprite(window, rect_quest);
            print_quest(window, nb_quest, my_quest1, my_quest2, my_quest3, my_quest4);
            if (gameinfos->boss == 4) {
                rect_quest.rect.height = 150;
                sfRenderWindow_drawText(window, my_quest_boss.text, NULL);
                sfRenderWindow_drawText(window, my_quest_boss.title, NULL);
                if (el_player.pos.y >= 593 && el_player.pos.y <= 595 && el_player.pos.x >= 502 && el_player.pos.x <= 506) {
                    gameinfos->c1 = 1;
                    if (gameinfos->c1 == 1) {
                        cave(window, gameinfos, stat, &my_player, ply_inv);
                    }
                }
            }
            if (pnj.pnj_ac == 1) {
                i++;
                ordre_quest.quest1 = i;
                if (ordre_quest.quest1 == ordre_quest.quest2 || ordre_quest.quest1 == ordre_quest.quest3 || ordre_quest.quest1 == ordre_quest.quest4)
                    ordre_quest.quest1 += 1;
                my_quest1 = do_lord_pnj(window, gameinfos, map, my_player, pnj, view, mini_map, cadre, &nb_quest);
                pnj.pnj_ac = 0;
                rect_quest.rect.height = nb_quest * 150;
                gameinfos->my_quests[0] = 1;
            }
            if (pnj2.pnj_ac == 1) {
                i++;
                ordre_quest.quest2 = i;
                if (ordre_quest.quest2 == ordre_quest.quest1 || ordre_quest.quest2 == ordre_quest.quest3 || ordre_quest.quest2 == ordre_quest.quest4)
                    ordre_quest.quest2 += 1;
                my_quest2 = do_lord_pnj2(window, gameinfos, map, my_player, pnj2, view, mini_map, cadre, &nb_quest);
                pnj2.pnj_ac = 0;
                rect_quest.rect.height = nb_quest * 150;
                gameinfos->my_quests[1] = 1;
            }
            if (pnj3.pnj_ac == 1) {
                i++;
                ordre_quest.quest3 = i;
                if (ordre_quest.quest3 == ordre_quest.quest2 || ordre_quest.quest3 == ordre_quest.quest1 || ordre_quest.quest3 == ordre_quest.quest4)
                    ordre_quest.quest3 += 1;
                my_quest3 = do_lord_pnj3(window, gameinfos, map, my_player, pnj3, view, mini_map, cadre, &nb_quest);
                pnj3.pnj_ac = 0;
                rect_quest.rect.height = nb_quest * 150;
                gameinfos->my_quests[2] = 1;
            }
            if (dog2.pnj_ac == 1) {
                i++;
                ordre_quest.quest4 = i;
                if (ordre_quest.quest4 == ordre_quest.quest2 || ordre_quest.quest4 == ordre_quest.quest3 || ordre_quest.quest4 == ordre_quest.quest1)
                    ordre_quest.quest4 += 1;
                my_quest4 = do_lord_pnj4(window, gameinfos, map, my_player, dog2, view, mini_map, cadre, &nb_quest);
                dog2.pnj_ac = 0;
                rect_quest.rect.height = nb_quest * 150;
                gameinfos->my_quests[3] = 1;
            }
            if (ordre_quest.quest1 >= i && old_i > i && ordre_quest.quest1 != 1) {
                my_quest1.pos_txt.y -= 150;
                my_quest1.pos_title.y -= 150;
                my_quest1.text = make_text(30, my_quest1.pos_txt, 1, sfWhite);
                sfText_setString(my_quest1.text, "Find them in the forest.");
                my_quest1.title = make_text(40, my_quest1.pos_title, 1, sfYellow);
                sfText_setString(my_quest1.title, "Find the magic boots");
            }
            if (ordre_quest.quest2 >= i && old_i > i && ordre_quest.quest2 != 1) {
                my_quest2.pos_txt.y -= 150;
                my_quest2.pos_title.y -= 150;
                my_quest2.text = make_text(30, my_quest2.pos_txt, 1, sfWhite);
                sfText_setString(my_quest2.text, "Find the wizard and fight it.");
                my_quest2.title = make_text(40, my_quest2.pos_title, 1, sfYellow);
                sfText_setString(my_quest2.title, "Defeat the wizard");
            }
            if (ordre_quest.quest3 >= i && old_i > i && ordre_quest.quest3 != 1) {
                my_quest3.pos_txt.y -= 150;
                my_quest3.pos_title.y -= 150;
                my_quest3.text = make_text(30, my_quest3.pos_txt, 1, sfWhite);
                sfText_setString(my_quest3.text, "Find the blob and fight it.");
                my_quest3.title = make_text(40, my_quest3.pos_title, 1, sfYellow);
                sfText_setString(my_quest3.title, "Defeat the blob");
            }
            if (ordre_quest.quest4 >= i && old_i > i && ordre_quest.quest4 != 1) {
                my_quest4.pos_txt.y -= 150;
                my_quest4.pos_title.y -= 150;
                my_quest4.text = make_text(30, my_quest4.pos_txt, 1, sfWhite);
                sfText_setString(my_quest4.text, "Find the sword on the beach.");
                my_quest4.title = make_text(40, my_quest4.pos_title, 1, sfYellow);
                sfText_setString(my_quest4.title, "Find the sword");
            }
            old_i = i;
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
                sfText_setString(txt_life, my_itoi(my_player.life));
                sfText_setString(txt_defense, my_itoi(my_player.ply_stat->defense));
                sfText_setString(txt_attak, my_itoi(my_player.ply_stat->attack));
                sfText_setString(txt_stamina, my_itoi(my_player.ply_stat->stamina));
                sfText_setString(txt_crit, my_itoi(my_player.ply_stat->crit));
                sfText_setString(txt_level, my_itoi(my_player.ply_stat->level));
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
                print_info_items(window, selected, info_item, ply_inv, event, &my_player);
            }
        }
        sfRenderWindow_display(window);
    }
    return 0;
}

int main(int ac, char **av)
{
    sfVideoMode mode = {1920, 1080, 32};
    srand(time(NULL));
    sfRenderWindow *window = sfRenderWindow_create(mode, "My Rpg", sfResize | sfClose, NULL);
    infogame *gameinfos = malloc(sizeof(infogame));
    gameinfos -> move_foreward = sfKeyZ;
    gameinfos -> move_back = sfKeyS;
    gameinfos -> move_left = sfKeyQ;
    gameinfos -> move_rigth = sfKeyD;
    gameinfos -> map = sfKeyM;
    gameinfos -> inventory = sfKeyI;
    gameinfos -> sprint = sfKeyLShift;
    gameinfos -> hit = sfKeySpace;
    gameinfos -> pause = sfKeyP;
    gameinfos -> resolution = malloc(sizeof(char) * 10);
    gameinfos -> resolution = my_strcpy(gameinfos -> resolution, "1920x1080");
    gameinfos -> vol_music = 100.0;
    gameinfos -> vol_sound = 100.0;
    gameinfos -> fps = 30;
    gameinfos -> pos_player_x = 960;
    gameinfos -> pos_player_y = 540;
    gameinfos -> arr_music = tab_music();
    gameinfos -> arr_music[0] = play_sound("Sounds/startmenu.ogg", gameinfos->vol_music);
    gameinfos -> arr_music[1] = play_sound("music/fight_song.ogg", gameinfos->vol_music);
    gameinfos->arr_music[3] = play_sound("music/gameoversong.ogg", gameinfos->vol_music);
    gameinfos -> arr_sound = tab_sound();
    gameinfos->arr_sound[0] = make_sound("Sounds/attack_effect.ogg", gameinfos->vol_sound);
    gameinfos->arr_sound[1] = make_sound("Sounds/land.ogg", gameinfos->vol_sound);
    gameinfos->arr_sound[5] = make_sound("Sounds/fireball_effect.ogg", gameinfos->vol_sound);
    gameinfos->arr_sound[6] = make_sound("Sounds/getlife.ogg", gameinfos->vol_sound);
    gameinfos->arr_sound[7] = make_sound("Sounds/hurt.ogg", gameinfos->vol_sound);
    gameinfos->my_quests = malloc(sizeof(int) * 4);
    gameinfos->my_quests[0] = 0;
    gameinfos->my_quests[1] = 0;
    gameinfos->my_quests[2] = 0;
    gameinfos->my_quests[3] = 0;
    gameinfos->my_items = malloc(sizeof(char) * 2);
    gameinfos->my_items[0] = 'a';
    gameinfos->my_items[1] = '\0';
    menu(window, gameinfos);
    return 0;
}