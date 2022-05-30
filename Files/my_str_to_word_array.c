/*
** EPITECH PROJECT, 2022
** my_str_to_word_array
** File description:
** my_str_to_word_array
*/

#include "../Includes/my.h"

int my_strlen_line(char const *str, int i)
{
    int result = 0;
    while (str[i] != '\n' && str[i] != '\0') {
        result += 1;
        i = i + 1;
    }
    return (result);
}

char **my_str_to_word_array(char const *str)
{
    int i = 0, j = 0, x = 0;
    char **result = malloc(sizeof(char *) * 104);
    char *tmp = malloc(sizeof(char) * (my_strlen_line(str, i) +  1));
    while (str[i]) {
        tmp[x] = str[i];
        i = i + 1, x = x + 1;
        if (str[i] == '\n') {
            tmp[x - 1] = '\0';
            result[j] = malloc(sizeof(char) * (my_strlen(tmp) + 1));
            my_strcpy(result[j], tmp);
            j = j + 1, i = i + 1, x = 0;
            free(tmp);
            if (str[i] != '\0')
                tmp = malloc(sizeof(char) * my_strlen_line(str, i));;
        }
    }
    result[j] = NULL;
    return result;
}

char **my_str_to_word_array2(char const *str)
{
    int i = 0, j = 0, x = 0;
    char **result = malloc(sizeof(char *) * 24);
    char *tmp = malloc(sizeof(char) * (my_strlen_line(str, i) +  1));
    while (str[i]) {
        tmp[x] = str[i];
        i = i + 1, x = x + 1;
        if (str[i] == '\n') {
            tmp[x - 1] = '\0';
            result[j] = malloc(sizeof(char) * (my_strlen(tmp) + 1));
            my_strcpy(result[j], tmp);
            j = j + 1, i = i + 1, x = 0;
            free(tmp);
            if (str[i] != '\0')
                tmp = malloc(sizeof(char) * my_strlen_line(str, i));;
        }
    }
    result[j] = NULL;
    return result;
}

char **my_str_to_word_array3(char const *str)
{
    int i = 0, j = 0, x = 0;
    char **result = malloc(sizeof(char *) * 15);
    char *tmp = malloc(sizeof(char) * (my_strlen_line(str, i) +  1));
    while (str[i]) {
        tmp[x] = str[i];
        i = i + 1, x = x + 1;
        if (str[i] == '\n') {
            tmp[x - 1] = '\0';
            result[j] = malloc(sizeof(char) * (my_strlen(tmp) + 1));
            my_strcpy(result[j], tmp);
            j = j + 1, i = i + 1, x = 0;
            free(tmp);
            if (str[i] != '\0')
                tmp = malloc(sizeof(char) * my_strlen_line(str, i));;
        }
    }
    result[j] = NULL;
    return result;
}
