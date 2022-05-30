/*
** EPITECH PROJECT, 2022
** fight.c
** File description:
** fight.c
*/

#include "../Includes/my.h"

int check_potions_inv(item *inv)
{
    int i = 0;
    while (i < 8) {
        if (inv[i].type == 2) {
            return 1;
        }
        i = i + 1;
    }
    return 0;
}

int take_potions_inv(item *inv)
{
    int i = 0;
    while (i < 8) {
        if (inv[i].type == 2) {
            return i;
        }
        i = i + 1;
    }
    return 84;
}

int check_bananas_inv(item *inv)
{
    int i = 0;
    while (i < 8) {
        if (inv[i].type == 3) {
            return 1;
        }
        i = i + 1;
    }
    return 0;
}

int take_bananas_inv(item *inv)
{
    int i = 0;
    while (i < 8) {
        if (inv[i].type == 3) {
            return i;
        }
        i = i + 1;
    }
    return 84;
}

void print_btn_fight(btn *attack, btn *spells, btn *items, int hor_select)
{
    if (hor_select == 0) {
        attack->my_sprite.rect.left = 211;
        spells->my_sprite.rect.left = 0;
        items->my_sprite.rect.left = 0;
    }
    if (hor_select == 1) {
        attack->my_sprite.rect.left = 0;
        spells->my_sprite.rect.left = 192;
        items->my_sprite.rect.left = 0;
    }
    if (hor_select == 2) {
        attack->my_sprite.rect.left = 0;
        spells->my_sprite.rect.left = 0;
        items->my_sprite.rect.left = 192;
    }
}

int change_hor_select(int hor_select, sfEvent event)
{
    if (hor_select > 0 && sfKeyboard_isKeyPressed(sfKeyLeft)) {
        return (hor_select - 1);
    }
    if (hor_select < 2 && sfKeyboard_isKeyPressed(sfKeyRight)) {
        return (hor_select + 1);
    }
    return (hor_select);
}

int change_spell(int select_spell, sfEvent event)
{
    if (select_spell == 1 && sfKeyboard_isKeyPressed(sfKeyDown)) {
        return (select_spell + 1);
    }
    if (select_spell == 2 && sfKeyboard_isKeyPressed(sfKeyUp)) {
        return (select_spell - 1);
    }
    return (select_spell);
}

int change_object(int select_object, sfEvent event, item *inv)
{
    if (select_object == 1 && sfKeyboard_isKeyPressed(sfKeyDown) && check_bananas_inv(inv) == 1) {
        return (select_object + 1);
    }
    if (select_object == 2 && sfKeyboard_isKeyPressed(sfKeyUp) && check_potions_inv(inv) == 1) {
        return (select_object - 1);
    }
    return (select_object);
}

char *make_atk_str(int degat)
{
    char *str = malloc(sizeof(char) * 50);
    str = my_strcpy(str, "You hit ennemy with ");
    str = my_strcat(str, my_itoi(degat));
    str = my_strcat(str, " ");
    str = my_strcat(str, "damages.");
    return (str);
}

char *make_mob_str(int degat)
{
    char *str = malloc(sizeof(char) * 50);
    str = my_strcpy(str, "Your ennemy hit with ");
    str = my_strcat(str, my_itoi(degat));
    str = my_strcat(str, " ");
    str = my_strcat(str, "damages.");
    return (str);
}

char *make_heal_str(int pts)
{
    char *str = malloc(sizeof(char) * 50);
    str = my_strcpy(str, "Your ennemy hit with ");
    str = my_strcpy(str, "Your heal yourself ");
    str = my_strcat(str, my_itoi(pts));
    str = my_strcat(str, " ");
    str = my_strcat(str, "points.");
    return (str);
}

void play_attack_effect(el *attack, sfClock *clock_atk_effect, sfRenderWindow *window)
{
    sfTime time;
    float seconds;
    time = sfClock_getElapsedTime(clock_atk_effect);
    seconds = time.microseconds / 1000000.0;
    while (1) {
        if (seconds > 0.07) {
            if (attack -> rect.left == 786) {
                attack -> rect.left = 0;
                break;
            } else {
                print_sprite(window, *attack);
                attack -> rect.left += 262;
            }
            sfClock_restart(clock_atk_effect);
        }
    }
}

char *update_points(int points, int max)
{
    char *str = malloc(sizeof(char) * 12);
    str = my_memset(str, '\0', 12);
    str = my_strcpy(str, "Pts ");
    str = my_strcat(str, my_itoi(points));
    str = my_strcat(str, "/");
    str = my_strcat(str, my_itoi(max));
    return (str);
}

int rand_dodge(int missed)
{
    int rd = rand() % 5;
    if (rd == 1) {
        return 1;
    } else {
        return 0;
    }
}

int rand_mob(void)
{
    int rd = rand() % 5;
    rd = rd + 5;
    return (rd);
}

int fight(sfRenderWindow *window, player *ply, png *mob, infogame *gameinfos, item *inv)
{
    sfEvent event;
    sfMusic_stop(gameinfos->arr_music[2]);
    sfMusic_setVolume(gameinfos->arr_music[1], gameinfos->vol_music);
    sfMusic_play(gameinfos->arr_music[1]);
    sfMusic_setLoop(gameinfos->arr_music[1], sfTrue);
    sfFloatRect rect_view = {0, 0, 1920, 1080};
    sfView *view = sfView_createFromRect(rect_view);
    el attack_effect = init_element(832, 283, 262, 256, "Pictures/content/attack_effect.png");
    el attack_effectmob = init_element(436, 28, 262, 256, "Pictures/content/attack_effect.png");
    sfVector2f scale_mob = {4, 4};
    sfVector2f scale_sprite = {16, 16};
    sfSprite_setScale(attack_effectmob.sprite, scale_mob);
    el fireball = init_element(832, 283, 252, 252, "Pictures/content/fireball_effect.png");
    mob->my_sprite.pos = init_pos(1075, 450);
    mob->my_sprite.rect.left = 0;
    sfSprite_setPosition(mob->my_sprite.sprite, init_pos(732, 300));
    sfSprite_setScale(mob->my_sprite.sprite, scale_sprite);
    el sprite_mob = init_element(832, 247, 256, 256, "Pictures/content/fight/sorcerer_fight.png");
    el cadre = init_element(283, 552, 1353, 288, "Pictures/content/cadre_fight.png");
    el bg_myhp = init_element(660, 860, 600, 50, "Pictures/content/bg_health_fight.png");
    el fg_myhp = init_element(660, 860, 600, 50, "Pictures/content/fg_health_fight.png");
    sfText *txt_myhp = make_text(64, init_pos(567, 840), 1, sfWhite);
    el bg_mobhp = init_element(660, 40, 600, 50, "Pictures/content/bg_health_fight.png");
    el fg_mobhp = init_element(660, 40, 100, 50, "Pictures/content/fg_health_fight.png");
    fg_myhp.rect.width = ply->life * 6;
    fg_mobhp.rect.width = mob->life * 6;
    sfText *txt_mobhp = make_text(64, init_pos(278, 19), 1, sfWhite);
    sfText_setString(txt_myhp, "HP");
    sfText_setString(txt_mobhp, "Ennemy\'s HP");
    btn *btn_simple_attk = make_button(1, 928, 65);
    btn *btn_obj1 = make_button(1, 512, 65);
    btn *btn_obj2 = make_button(1, 320, 65);
    btn *btn_spell1 = make_button(1, 512, 65);
    btn *btn_spell2 = make_button(1, 448, 65);
    btn *btn_attack = make_button(1, 211, 76);
    btn *btn_spells = make_button(1, 192, 76);
    btn *btn_items = make_button(1, 192, 76); sfClock *clock1 = sfClock_create(); sfClock *clock2 = sfClock_create();
    sfClock *clock3 = sfClock_create(); sfClock *clock4 = sfClock_create(); sfClock *clock5 = sfClock_create();
    sfClock *clock6 =  sfClock_create();
    sfClock *c_atk_effect = sfClock_create();
    btn_attack->my_sprite = init_button(init_pos(498, 982), btn_attack, "Pictures/content/btn_attack.png");
    btn_spells->my_sprite = init_button(init_pos(864, 982), btn_spells, "Pictures/content/btn_spell.png");
    btn_items->my_sprite = init_button(init_pos(1230, 982), btn_items, "Pictures/content/btn_items.png");
    btn_spell1->my_sprite = init_button(init_pos(319, 604), btn_spell1, "Pictures/content/fireball_spell.png");
    btn_spell2->my_sprite = init_button(init_pos(319, 724), btn_spell2, "Pictures/content/health_spell.png");
    btn_obj1->my_sprite = init_button(init_pos(319, 604), btn_obj1, "Pictures/content/potion_items.png");
    btn_obj2->my_sprite = init_button(init_pos(319, 724), btn_obj2, "Pictures/content/banana_items.png");
    btn_simple_attk->my_sprite = init_button(init_pos(319, 604), btn_simple_attk,  "Pictures/content/simple_attack.png");
    int hor_select = 0; int phase = 0; int select_spell = 1;
    int ver_select = 0; int start_fight = 0; int sound_play = 0;
    char *welcome_msg1 = malloc(sizeof(char) * 25);
    welcome_msg1 = my_memset(welcome_msg1, '\0', 25);
    char *welcome_msg2 = malloc(sizeof(char) * 22);
    welcome_msg2 = my_memset(welcome_msg2, '\0', 22);
    int i = 0; int j = 0; int continuer = 0; int k = 0; int len_attack = -1;
    sfText *txt_welcome1 = make_text(64, init_pos(327, 585), 1, sfWhite);
    sfText *txt_welcome2 = make_text(64, init_pos(327, 661), 1, sfWhite);
    sfText *txt_attack = make_text(64, init_pos(327, 585), 1, sfWhite);
    sfText *txt_fireball = make_text(64, init_pos(327, 585), 1, sfWhite);
    char *attack_msg = malloc(sizeof(char) * 25);
    attack_msg = my_memset(attack_msg, '\0', 25);
    sfText_setString(txt_welcome1, welcome_msg1);
    sfText_setString(txt_welcome2, welcome_msg2);
    sfText_setString(txt_attack, attack_msg);
    sfText *txt_lvl = make_text(64, init_pos(283, 838), 1, sfWhite);
    char *str_lvl = malloc(sizeof(char) * 7); str_lvl = my_memset(str_lvl, '\0', 7);
    str_lvl = my_strcpy(str_lvl, "Lvl. ");
    str_lvl = my_strcat(str_lvl, my_itoi(ply->ply_stat->level));
    sfText_setString(txt_lvl, str_lvl);
    int ply_degat = ply->ply_stat->attack; int select = 0; int select_obj = 1; int missed = 0;
    int current_pts = ply->const_stamina;
    char *str_points = update_points(current_pts, ply->const_stamina);
    sfText *txt_pts = make_text(64,init_pos(1412, 828), 1, sfWhite);
    sfText_setString(txt_pts, str_points); int turn = 0; int attack_mob = 0;
    sfText *txt_mob_atk = make_text(64, init_pos(327, 585), 1, sfWhite); int life_ennemy = 0;
    int fireball_degat = 20;
    if (mob->life != 200) {
        life_ennemy = mob->life;
    } else {
        ply_degat = ply_degat / 2;
        fireball_degat = fireball_degat / 2;
        mob->my_sprite.pos = init_pos(800, 250);
        life_ennemy = 100;
    }
    while (sfRenderWindow_isOpen(window)) {
        sfRenderWindow_setView(window, view);
        sfRenderWindow_clear(window, sfBlack);
        while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (start_fight == 1 && continuer != 1)
                hor_select = change_hor_select(hor_select, event);
            if (continuer != 1 && hor_select == 1)
                select_spell = change_spell(select_spell, event);
            if (continuer != 1 && hor_select == 2)
                select_obj = change_object(select_obj, event, inv);
            if (sfKeyboard_isKeyPressed(sfKeySpace) && hor_select == 0 && phase == 0 && continuer != 1) {
                phase = 1;
                attack_mob = rand_mob();
                missed = rand_dodge(missed);
                if (missed == 0 && mob->life != 200) {
                    life_ennemy -= ply_degat;
                } else if (missed == 0 && mob->life == 200) {
                    life_ennemy = life_ennemy - ply_degat;
                }
                sfSound_setVolume(gameinfos->arr_sound[0], gameinfos->vol_sound);
                sfSound_play(gameinfos->arr_sound[0]);
            }
            if (sfKeyboard_isKeyPressed(sfKeySpace) && hor_select == 1 && select_spell == 1 && continuer != 1 && phase == 0 && current_pts >= 25) {
                phase = 2;
                attack_mob = rand_mob();
                missed = rand_dodge(missed);
                if (missed == 0)
                    life_ennemy -= fireball_degat;
                sfSound_setVolume(gameinfos->arr_sound[5], gameinfos->vol_sound);
                sfSound_play(gameinfos->arr_sound[5]);
                if (ply->const_stamina - current_pts <= 75 )
                    current_pts = current_pts - 25;
            }
            if (sfKeyboard_isKeyPressed(sfKeySpace) && hor_select == 1 && select_spell == 2 && continuer != 1 && phase == 0 && current_pts >= 10) {
                phase = 2;
                attack_mob = rand_mob();
                sfSound_setVolume(gameinfos->arr_sound[6], gameinfos->vol_sound);
                sfSound_play(gameinfos->arr_sound[6]);
                if (ply->life <= 75) {
                    ply->life += 25;
                } else {
                    ply->life = 100;
                }
                if (ply->const_stamina - current_pts <= 90 )
                    current_pts = current_pts - 10;
            }
            if (sfKeyboard_isKeyPressed(sfKeySpace) && hor_select == 2 && select_obj == 1 && continuer != 1 && phase == 0 && btn_obj1->type != 2) {
                phase = 3;
                attack_mob = rand_mob();
                sfSound_setVolume(gameinfos->arr_sound[6], gameinfos->vol_sound);
                sfSound_play(gameinfos->arr_sound[6]);
                if (ply->life <= 75) {
                    ply->life += 35;
                } else {
                    ply->life = 100;
                }
                int indice = take_potions_inv(inv);
                inv[indice].type = 84;
                if (check_bananas_inv(inv) == 1)
                    select_obj = 2;
            }
            if (sfKeyboard_isKeyPressed(sfKeySpace) && hor_select == 2 && select_obj == 2 && continuer != 1 && phase == 0 && btn_obj2->type != 2) {
                phase = 3;
                attack_mob = rand_mob();
                sfSound_setVolume(gameinfos->arr_music[6], gameinfos->vol_sound);
                sfSound_play(gameinfos->arr_sound[6]);
                if (ply->life <= 85 ) {
                    ply->life += 15;
                } else {
                    ply->life = 100;
                }
                int indice = take_bananas_inv(inv);
                inv[indice].type = 84;
            }
        }
        if (check_potions_inv(inv) == 0) {
            btn_obj1->type = 2;
            btn_obj1->my_sprite.rect.left = 1024;
        }  else {
            btn_obj1->type = 1;
        }
        if (check_bananas_inv(inv) == 0) {
            btn_obj2->type = 2;
            btn_obj2->my_sprite.rect.left = 640;
        } else  {
            btn_obj2->type = 1;
        }
        str_points = update_points(current_pts, ply->const_stamina);
        sfText *txt_pts = make_text(64,init_pos(1412, 828), 1, sfWhite);
        sfText_setString(txt_pts, str_points);
        if (select_spell == 1) {
            btn_spell1->my_sprite.rect.left = 512;
            btn_spell2 -> my_sprite.rect.left = 0;
            sfSprite_setTextureRect(btn_spell1->my_sprite.sprite, btn_spell1->my_sprite.rect);
            sfSprite_setTextureRect(btn_spell2->my_sprite.sprite, btn_spell2->my_sprite.rect);
        }
        if (select_spell == 2) {
            btn_spell2->my_sprite.rect.left = 448;
            btn_spell1 -> my_sprite.rect.left = 0;
            sfSprite_setTextureRect(btn_spell1->my_sprite.sprite, btn_spell1->my_sprite.rect);
            sfSprite_setTextureRect(btn_spell2->my_sprite.sprite, btn_spell2->my_sprite.rect);
        }
        if (select_obj == 1) {
            if (btn_obj1->type != 2)
                btn_obj1->my_sprite.rect.left = 512;
            if (btn_obj2->type != 2)
                btn_obj2 -> my_sprite.rect.left = 0;
            sfSprite_setTextureRect(btn_obj1->my_sprite.sprite, btn_obj1->my_sprite.rect);
            sfSprite_setTextureRect(btn_obj2->my_sprite.sprite, btn_obj2->my_sprite.rect);
        }
        if (select_obj == 2) {
            if (btn_obj1->type != 2)
                btn_obj1->my_sprite.rect.left = 0;
            if (btn_obj2->type != 2)
                btn_obj2 -> my_sprite.rect.left = 320;
            sfSprite_setTextureRect(btn_obj1->my_sprite.sprite, btn_obj1->my_sprite.rect);
            sfSprite_setTextureRect(btn_obj2->my_sprite.sprite, btn_obj2->my_sprite.rect);
        }
        if (i < 19 && start_fight == 0) {
            anim_txt(clock1, "Lets go to fight...", &i, txt_welcome1, 0.03);
            sfRenderWindow_drawText(window, txt_welcome1, NULL);
        }
        if (i == 19 && j < 20 && start_fight == 0) {
            anim_txt(clock2, "You cant defeat me !", &j, txt_welcome2, 0.03);
            sfRenderWindow_drawText(window, txt_welcome1, NULL);
            sfRenderWindow_drawText(window, txt_welcome2, NULL);
        }
        if (j == 20) {
            if_continuer(clock3, &continuer, 4);
            turn = 1;
        }
        if (k == len_attack) {
            if_continuer(clock6, &continuer, 1);
            k = 0;
        }
        if (continuer == 1) {
            start_fight = 1;
            continuer = 2; phase = 0; j = 0; k = 0; sfClock_destroy(clock6);
            sfClock_restart(clock3); clock6 = sfClock_create();
            if (mob->my_sprite.pos.x <= 700) {
                mob->my_sprite.pos.x = 1075;
            }
            if (turn == 1) {
                turn = 2;
            } else {
                turn = 1;
                ply->life -=  attack_mob;
                sfSound_setVolume(gameinfos->arr_sound[7], gameinfos->vol_sound);
                sfSound_play(gameinfos->arr_sound[7]);
            }
            attack_effect.rect.left = 0;
            fireball.rect.left = 0;
            attack_effectmob.rect.left = 0;
        }
        if (phase == 1) {
            continuer = 0;
            char *attack_str = NULL;
            if (missed == 0) {
                attack_str = make_atk_str(ply_degat);
                len_attack = my_strlen(attack_str);
            } else {
                attack_str = malloc(sizeof(char) * 33);
                attack_str = my_strcpy(attack_str, "Your attack missed. He dodged.");
                len_attack = my_strlen(attack_str);
            }
            anim_txt(clock5, attack_str, &k, txt_attack, 0.03);
            sfRenderWindow_drawText(window, txt_attack, NULL);
        }
        if (phase == 2) {
            continuer = 0;
            char *fireball_str = NULL;
            if (missed == 0 && select_spell == 1) {
                fireball_str = make_atk_str(ply_degat);
                len_attack = my_strlen(fireball_str);
            } else if (missed == 0 &&  select_spell == 2) {
                fireball_str = make_heal_str(25);
                len_attack = my_strlen(fireball_str);
            } else {
                fireball_str = malloc(sizeof(char) * 33);
                fireball_str = my_strcpy(fireball_str, "Your attack missed. He dodged.");
                len_attack = my_strlen(fireball_str);
            }
            anim_txt(clock5, fireball_str, &k, txt_fireball, 0.03);
            sfRenderWindow_drawText(window, txt_fireball, NULL);
        }
        if (phase == 3) {
            continuer = 0;
            char *fireball_str = NULL;
            if (missed == 0 && select_obj == 1) {
                fireball_str = make_heal_str(35);
                len_attack = my_strlen(fireball_str);
            } else if (missed == 0 &&  select_obj == 2) {
                fireball_str = make_heal_str(15);
                len_attack = my_strlen(fireball_str);
            }
            anim_txt(clock5, fireball_str, &k, txt_fireball, 0.03);
            sfRenderWindow_drawText(window, txt_fireball, NULL);
        }
        if (turn == 2) {
            continuer = 0;
            char *mob_str = NULL;
            mob_str = make_mob_str(attack_mob);
            len_attack = my_strlen(mob_str);
            anim_txt(clock5, mob_str, &k, txt_mob_atk, 0.03);
            sfRenderWindow_drawText(window, txt_mob_atk, NULL);
        }
        if (life_ennemy <= 0) {
            sfMusic_stop(gameinfos->arr_music[1]);
            sfMusic_setVolume(gameinfos->arr_music[2], gameinfos->vol_music);
            sfMusic_play(gameinfos->arr_music[2]);
            return 0;
        }
        if (ply->life <= 0) {
            sfMusic_stop(gameinfos->arr_music[1]);
            sfMusic_setVolume(gameinfos->arr_music[2], gameinfos->vol_music);
            sfMusic_play(gameinfos->arr_music[2]);
            return 1;
        }
        if (hor_select == 0 && phase == 0 && start_fight == 1 && turn == 1)
            print_sprite(window, btn_simple_attk->my_sprite);
        if (hor_select == 1 && phase == 0 && turn == 1) {
            print_sprite(window, btn_spell1->my_sprite);
            print_sprite(window, btn_spell2->my_sprite);
        }
        if (hor_select == 2 && phase == 0 && turn == 1) {
            print_sprite(window, btn_obj1->my_sprite);
            print_sprite(window, btn_obj2->my_sprite);
        }
        fg_myhp.rect.width = ply->life * 6;
        fg_mobhp.rect.width = life_ennemy * 6;
        print_btn_fight(btn_attack, btn_spells, btn_items, hor_select);
        print_sprite(window, mob->my_sprite);
        print_sprite(window, cadre);
        print_sprite(window, btn_attack->my_sprite);
        print_sprite(window, btn_spells->my_sprite);
        print_sprite(window, btn_items->my_sprite);
        print_sprite(window, bg_myhp);
        print_sprite(window, fg_myhp);
        print_sprite(window, bg_mobhp);
        print_sprite(window, fg_mobhp);
        if (phase == 1) {
            if (missed == 1) {
                if (mob->my_sprite.pos.x > 700) {
                    mob->my_sprite.pos.x -= 50;
                } else {
                    if (attack_effect.rect.left != 786) {
                        print_sprite(window, attack_effect);
                        attack_effect.rect.left += 262;
                    }
                }
            } else {
                if (attack_effect.rect.left != 786) {
                    print_sprite(window, attack_effect);
                    attack_effect.rect.left += 262;
                }
            }
        }
        if (phase == 2) {
            if (missed == 1) {
                if (mob->my_sprite.pos.x > 700) {
                    mob->my_sprite.pos.x -= 50;
                } else {
                    if (fireball.rect.left != 2772) {
                        print_sprite(window, fireball);
                        fireball.rect.left += 252;
                    }
                }
            } else {
                if (fireball.rect.left != 2772) {
                    print_sprite(window, fireball);
                    fireball.rect.left += 252;
                }
            }
        }
        if (turn == 2) {
            if (attack_effectmob.rect.left != 786) {
                print_sprite(window, attack_effectmob);
                attack_effectmob.rect.left += 262;
            }
        }
        sfRenderWindow_drawText(window, txt_lvl, NULL);
        sfRenderWindow_drawText(window, txt_myhp, NULL);
        sfRenderWindow_drawText(window, txt_mobhp, NULL);
        sfRenderWindow_drawText(window, txt_pts, NULL);
        sfRenderWindow_display(window);
    }
    return 0;
}