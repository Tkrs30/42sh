/*
** EPITECH PROJECT, 2020
** B-PSU-101-MPL-1-1-navy-hugo.gardes
** File description:
** include.h
*/

#ifndef INCLUDE_SCANF_H
#define INCLUDE_SCANF_H

int my_getnbr (char const *str);

void get_nbr(va_list ap, char *buff);

void get_str(va_list ap, char *str);

void get_char(va_list ap, char *c);

typedef struct fonct
{
    char chara;
    void (*fonction)(va_list, char *);
} ap_fonct;

static const ap_fonct f_ap[] =
{
    {'s', get_str},
    {'d', get_nbr},
    {'i', get_nbr},
    {'c', get_char},
    {0, 0}
};

#endif