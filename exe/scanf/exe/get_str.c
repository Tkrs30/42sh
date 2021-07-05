/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-navy-hugo.gardes
** File description:
** get_str.c
*/

#include <stdarg.h>
#include <stdio.h>
#include "../include.h"

void get_str(va_list ap, char *str)
{
    int y = 0;
    char *strtemp = va_arg(ap, char *);
    for (; str[y]; y++) {
        strtemp[y] = str[y];
    }
    strtemp[y] = 0;
}

void get_char(va_list ap, char *c)
{
    char *temp = va_arg(ap, char *);
    *temp = *c;
}