/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include "../Includes/my.h"

int inter_objet(sfRenderWindow *window, el *obj, el player)
{
    el button_e = init_element(obj->pos.x - 5, obj->pos.y - 17, 35, 36, "Pictures/button_e.png");
    sfVector2f scale = {0.25, 0.25}; int a = 0;
    sfSprite_setScale(button_e.sprite, scale);
    if ((player.pos.x >= obj->pos.x - 25 && player.pos.x <= obj->pos.x + 30)
        && (player.pos.y >= obj->pos.y - 20 && player.pos.y <= obj->pos.y + 30)) {
        print_sprite(window, button_e);
        a = 1;
    }
    if (sfKeyboard_isKeyPressed(sfKeyE) && a == 1) {
        return 1;
    }
    return 0;
}

void get_quest(infogame *gameinfos, quest *quest1, quest *quest2, quest *quest3, quest *quest4, el *pnj1, el *pnj2, el *pnj3, el *pnj4, int *nb_quest)
{
    if (gameinfos->my_quests[0] == 1) {
        pnj1->quest = 1;
        pnj1->pnj_ac = 0;
        quest1->null = 0;
        sfVector2f pos_quest_title = {1460, 280};
        sfVector2f pos_quest = {1460, 340};
        if (*nb_quest > 0) {
            pos_quest.y += 150 * *nb_quest;
            pos_quest_title.y += 150 * *nb_quest;
        }
        quest1->text = make_text(30, pos_quest, 1, sfWhite);
        sfText_setString(quest1->text, "Find them in the forest.");
        quest1->title = make_text(40, pos_quest_title, 1, sfYellow);
        sfText_setString(quest1->title, "Find the magic boots");
        *nb_quest += 1;
    }
    if (gameinfos->my_quests[1] == 1) {
        pnj2->quest = 1;
        pnj2->pnj_ac = 0;
        quest2->null = 0;
        sfVector2f pos_quest_title = {1460, 280};
        sfVector2f pos_quest = {1460, 340};
        if (*nb_quest > 0) {
            pos_quest.y += 150 * *nb_quest;
            pos_quest_title.y += 150 * *nb_quest;
        }
        quest2->text = make_text(30, pos_quest, 1, sfWhite);
        sfText_setString(quest2->text, "Find the wizard and fight it.");
        quest2->title = make_text(40, pos_quest_title, 1, sfYellow);
        sfText_setString(quest2->title, "Defeat the wizard");
        *nb_quest += 1;
    }
    if (gameinfos->my_quests[2] == 1) {
        pnj3->quest = 1;
        pnj3->pnj_ac = 0;
        quest3->null = 0;
        sfVector2f pos_quest_title = {1460, 280};
        sfVector2f pos_quest = {1460, 340};
        if (*nb_quest > 0) {
            pos_quest.y += 150 * *nb_quest;
            pos_quest_title.y += 150 * *nb_quest;
        }
        quest3->text = make_text(30, pos_quest, 1, sfWhite);
        sfText_setString(quest3->text, "Find the blob and fight it.");
        quest3->title = make_text(40, pos_quest_title, 1, sfYellow);
        sfText_setString(quest3->title, "Defeat the blob");
        *nb_quest += 1;
    }
    if (gameinfos->my_quests[3] == 1) {
        pnj4->quest = 1;
        pnj4->pnj_ac = 0;
        quest4->null = 0;
        sfVector2f pos_quest_title = {1460, 280};
        sfVector2f pos_quest = {1460, 340};
        if (*nb_quest > 0) {
            pos_quest.y += 150 * *nb_quest;
            pos_quest_title.y += 150 * *nb_quest;
        }
        quest4->text = make_text(30, pos_quest, 1, sfWhite);
        sfText_setString(quest4->text, "Find the sword on the beach.");
        quest4->title = make_text(40, pos_quest_title, 1, sfYellow);
        sfText_setString(quest4->title, "Find the sword");
        *nb_quest += 1;
    }
}