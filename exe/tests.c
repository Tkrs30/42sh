/*
** EPITECH PROJECT, 2020
** AtelierCode-Minishell1
** File description:
** test.c
*/

#include <stdlib.h>
#include <stdio.h>
#include "../include/include2.h"

test_env *push_back(char *str, test_env *struc_init)
{
    test_env *push_bac = my_malloc(sizeof(test_env));
    push_bac->next = struc_init;
    push_bac->var_env = str;
    push_bac->size = struc_init->size + 1;
    return (push_bac);
}

int nmatch(char *str_to_comp, char *str_comp, int n)
{
    for (int u = 0; str_to_comp[u] && str_comp[u] && n; u++)
        if (str_to_comp[u] != str_comp[u])
            return (1);
    return (0);
}

test_env *fill(char **env)
{
    test_env *test = my_malloc(sizeof(test_env) * 2);
    test->size = 0;
    for (int u = 0; env[u]; u++) {
        test = push_back(env[u], test);
        test->size = u;
    }
    return (test);
}

test_env *modif_path(test_env **test, char *search, int len, char *new_var)
{
    int size = (*test)->size;
    test_env *save = *test;
    for (int u = 0; u < size && nmatch((*test)->var_env, search, len); u++)
        *test = (*test)->next;
    (*test)->var_env = new_var;
    (*test) = save;
    return ((*test));
}

char **create_tab_from_list(env_tab_and_chained *env)
{
    int size = env->envv->size;
    test_env *save = env->envv;
    for (int u = 0; u < size; u++) {
        env->env[u] = env->envv->var_env;
        env->envv = env->envv->next;
    }
    env->envv = save;
    return (env->env);
}