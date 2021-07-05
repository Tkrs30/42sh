/*
** EPITECH PROJECT, 2020
** B-PSU-210-MPL-2-1-42sh-samuel.nadal
** File description:
** unsetenv.c
*/

#include <include.h>

int get_index(test_env **test, char *search, int len)
{
    int size = (*test)->size;
    int index = 0;
    test_env *save = *test;
    for (int u = 0; u < size && nmatch((*test)->var_env, search, len); u++) {
        index += 1;
        *test = (*test)->next;
    }
    // my_printf("index = %d && size = %d, searsh = %s && list = %s\n", index, size, search, (*test)->var_env);
    (*test) = save;
    return (index + 1);
}

test_env *terminanode(test_env *cancer, int victime)
{
    test_env *save = cancer;
    int x = 1;
    int size = cancer->size;

    while (x < size && x < victime - 1) {
        cancer = cancer->next;
        x++;
    }
    cancer->next->next->size -= 1;
    cancer->next = cancer->next->next;
    cancer = save;
    return (cancer);
}

test_env *my_unsetenv(test_env **test, char *search, int len)
{
    char buff[999];
    strcpy(buff, search);
    terminanode(*test, get_index(test, concat_strings(buff, "="), len));
    return (*test);
}