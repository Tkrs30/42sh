/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-42sh-samuel.nadal
** File description:
** setenv.c
*/

#include <include.h>

int list_get_size(test_env *list)
{
    int t = 0;
    test_env *listt = list;
    while (listt != NULL) {
        t += 1;
        listt = listt->next;
    }
    return (t);
}

bool strncomp(char *s1, char *s2)
{
    for (int i = 0; s2[i] != 0; i++) {
        if (s1[i] != s2[i])
            return (false);
    }
    return (true);
}

bool ifsetenv(test_env *list, char **av)
{
    int i = 0;
    int max_size = list->size;
    char buff[999] = "\0";

    strcpy(buff, av[1]);
    for (int i = 0; !strncomp(list->var_env, av[1]) && i != max_size; i++) {
        if (i != 0)
            list = list->next;
    }
    if (i == max_size) {
        concat_strings(buff, "=");
        concat_strings(buff, av[2]);
        list = push_back(my_str_copie(buff), list);
    } else {
        concat_strings(buff, "=");
        concat_strings(buff, av[2]);
        list->var_env = my_str_copie(buff);
    }
    return (true);
}