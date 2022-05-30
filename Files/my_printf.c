/*
** EPITECH PROJECT, 2021
** my_printf.c
** File description:
** my_printf
*/

#include "../Includes/my.h"
#include <stdarg.h>

void more(int i, const char *format, va_list *list)
{
    switch (format[i + 1]) {
        case '%':
            my_putchar('%');
            break;
        case 's':
            my_putstr(va_arg(*list, char *));
            break;
        case 'i':
            my_put_nbr(va_arg(*list, int));
            break;
        case 'd':
            my_put_nbr(va_arg(*list, int));
            break;
        case 'c':
            my_putchar(va_arg(*list, int));
            break;
        default:
            break;
    }
}

int my_printf(const char *format, ...)
{
    va_list list; va_start(list, format);
    int i = 0;
    while (format[i] != '\0') {
        if (format[i] == '%') {
            more(i, format, &list);
            i += 1;
        } else
            my_putchar(format[i]);
        i += 1;
    }
    va_end(list); return 0;
}