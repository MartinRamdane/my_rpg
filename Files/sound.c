/*
** EPITECH PROJECT, 2022
** sound.c
** File description:
** sound.c
*/

#include "../Includes/my.h"

sfMusic *play_sound(char *filepath, int vol)
{
    sfMusic *sound = sfMusic_createFromFile(filepath);
    sfMusic_setLoop(sound, sfTrue);
    sfMusic_setVolume(sound, vol);
    return (sound);
}

sfSound *make_sound(char *filepath, int vol)
{
    sfSoundBuffer *buffer = sfSoundBuffer_createFromFile(filepath);
    sfSound *my_sound = sfSound_create();
    sfSound_setBuffer(my_sound, buffer);
    sfSound_setVolume(my_sound, vol);
    return (my_sound);
}

sfMusic **tab_music(void)
{
    sfMusic **arr = malloc(sizeof(sfMusic *) * 100);
    int i = 0;
    while (i < 100) {
        arr[i] = malloc(sizeof(sfMusic *));
        i++;
    }
    return (arr);
}

sfSound **tab_sound(void)
{
    sfSound **arr = malloc(sizeof(sfSound *) * 100);
    int i = 0;
    while (i < 100) {
        arr[i] = malloc(sizeof(sfSound *));
        i++;
    }
    return (arr);
}
