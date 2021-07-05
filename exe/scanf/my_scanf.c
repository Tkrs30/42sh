/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-navy-hugo.gardes
** File description:
** my_scanf.c
*/

#include <stdarg.h>
#include <unistd.h>
#include "include.h"

void reduc(int *u, char *str, char *buff, va_list ap)
{
    int i = 0;
    *u += 1;
    for (i = 0; f_ap[i].chara != str[*u] && f_ap[i].chara; i++);
    if (f_ap[i].chara && f_ap[i].chara == str[*u])
        f_ap[i].fonction(ap, buff);
    *u += 1;
}

void my_scanf(char *str, ...)
{
    va_list ap;
    char buff[999999];
    int len ;
    int u = 0;
    int i = 0;
    va_start(ap, str);
    for (; str[u] != '%' && str[u]; u++)
        write(1, &str[u], 1);
    while ((len = read(0, buff, 999999)) == -1);
    for (;buff[i] > 31 && buff[i] < 127 && buff[i]; i++);
    buff[i] = 0;
    for (; str[u]; u++)
        reduc(&u, str, buff, ap);
}