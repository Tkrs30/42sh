/*
** EPITECH PROJECT, 2020
** B-BOO-101-MPL-1-1-phoenixd03-hugo.gardes
** File description:
** concat_strings.c
*/

int mslen(char *str)
{
    int len = 0;
    for (; str[len]; len++);
    return (len);
}

char *concat_strings(char *dest, char *src)
{
    int len = mslen(dest);
    int u = 0;
    for (; src[u]; u++)
        dest[len + u] = src[u];
    dest[len + u] = 0;
    return (dest);
}